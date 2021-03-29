//
// Created by lorenzo on 29/03/21.
//

#ifndef UDP_CLIENT_CLIENT_H
#define UDP_CLIENT_CLIENT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "../headers/packet.h"
#include "../headers/error.h"

/**
 * Function that creates a UDP client that will send a NTP packet to a NTP server and reads the response
 * It returns a time_t object which contains the current time
 *
 * @param server_name The NTP server name
 * @param server_port The NTP server port
 * @return The current time
 */
time_t run(char *server_name, int server_port);

#endif //UDP_CLIENT_CLIENT_H
