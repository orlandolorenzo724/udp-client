//
// Created by Lorenzo on 29/03/21.
//

#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "../headers/packet.h"
#include "../headers/error.h"
#include "../headers/client.h"

/**
 * Function that creates a UDP client that will send a NTP packet to a NTP server and reads the response
 * It returns a time_t object which contains the current time
 *
 * @param server_name The NTP server name
 * @param server_port The NTP server port
 * @return The current time
 */
time_t run(char *server_name, int server_port) {
    // Creating a UDP socket and checking for any error
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd == -1) {
        print_error("Error opening socket", HIGH);
    }

    // Creating a NTP packet
    struct ntp_packet packet;

    // Zero out the packet
    memset(&packet, 0, sizeof(struct ntp_packet));

    // Set the first byte's bits to 00, 011, 011
    // li = 0, vn = 0 and mode = 3
    // The rest will be set to 0
    *((char *) &packet + 0) = 0x1b; // 00011011

    // Creating a NTP server data structure
    // And then checking if the URL is valid + the server is reachable
    struct hostent *server = gethostbyname(server_name);
    if(server == NULL) {
        print_error("Error connecting to server", HIGH);
    }

    // Server address structure
    struct sockaddr_in server_address;

    // Zero out the server address structure
    bzero((char *) &server_address, sizeof(server_address));

    // Copy the server's IP Address to the server address structure
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);

    // Calling up the server and checking if there's any error
    int connection = connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address));
    if(connection == -1) {
        print_error("Error connecting", HIGH);
    }

    // If the connection is established between the UDP client and the NTP server, we can finally send and receive packets
    // Sending the NTP packet and checking if there's any error
    int send = write(sockfd, (char *) &packet, sizeof(struct ntp_packet));
    if(send == -1) {
        print_error("Error writing to socket", HIGH);
    }

    // If the packet has been sent, the NTP will then send a response
    // Receiving the NTP packet response and checking if there's any error
    int receive = read(sockfd, (char *) &packet, sizeof(struct ntp_packet));
    if(receive == -1) {
        print_error("Error reading from socket", HIGH);
    }

    // Converting the bits order from the network's to host's endianess
    packet.transmit_timestamp_s = ntohl(packet.transmit_timestamp_s);
    packet.transmit_timestamp_f = ntohl(packet.transmit_timestamp_f);

    // Subtracting 70 years worth of seconds from the seconds since 1900
    time_t transmit_timestamp = (time_t) (packet.transmit_timestamp_s - NTP_TIMESTAMP_DELTA);

    // Returning the current time
    return transmit_timestamp;
}