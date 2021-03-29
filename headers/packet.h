//
// Created by lorenzo on 29/03/21.
//

#ifndef UDP_CLIENT_PACKET_H
#define UDP_CLIENT_PACKET_H

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

#define NTP_TIMESTAMP_DELTA 2208988800ull

/**
 * Please consult https://www.rfc-editor.org/rfc/rfc1119.pdf for more information about the Network Time Protocol
 */

/**
 * NTP packet struct
 * Its size is 384 bits or 48 bytes
 */
struct ntp_packet {
    uint8_t li_vn_mode;                 // LI   (2 bits): Indicates whether the last minute of the current day is to have a leap seconds applied.
                                        // VN   (3 bits): Indicates the NTP Version Number
                                        // MODE (3 bits): Indicates the NTP packet mode (reserved, symmetric, client, server, broadcast...)

    uint8_t stratum;                    // Indicates the stratum level of the time source (unspecified, primary server, reserved...)
    uint8_t poll;                       // Indicates the poll interval value of the maximum interval between successive NTP messages, in seconds
    uint8_t precision;                  // Indicates the clock precision in log_2 seconds

    uint32_t root_delay;                // The total round-trip delay from the server to the primary reference sourced.
                                        // The value is a 32-bit signed fixed-point number in units of seconds, with the fraction point between bits 15 and 16.
                                        // This field is significant only in server messages.

    uint32_t root_dispersion;           // The maximum error due to clock frequency tolerance. The value is a 32-bit signed fixed-point number
                                        // in units of seconds, with the fraction point between bits 15 and 16.
                                        // This field is significant only in server messages.

    uint32_t reference_identifier;      // For stratum 1 servers this value is a four-character ASCII code that describes the external reference source.
                                        // For secondary servers this value is the 32-bit IPv4 address of the synchronization source,
                                        // or the first 32 bits of the Message Digest Algorithm 5 (MD5) hash of the IPv6 address of the synchronization source.

    uint32_t reference_timestamp_s;     // The time the system clock was last set or corrected, in 32-bit time-stamp seconds format.
    uint32_t reference_timestamp_f;     // The time the system clock was last set or corrected, in 32-bit time-stamp fraction of a second format.

    uint32_t originate_timestamp_s;     // The time at which the request departed the client for the server, in 32-bit time-stamp seconds format.
    uint32_t originate_timestamp_f;     // The time at which the request departed the client for the server, in 32-bit time-stamp fraction a second format.

    uint32_t receive_timestamp_s;       // The time at which the client request arrived at the server in 32-bit time-stamp seconds format.
    uint32_t receive_timestamp_f;       // The time at which the client request arrived at the server in 32-bit time-stamp fraction of a second format.

    uint32_t transmit_timestamp_s;      // The time at which the server reply departed the server, in 32-bit time-stamp seconds format.
    uint32_t transmit_timestamp_f;      // The time at which the server reply departed the server, in 32-bit time stamp fraction of a second format.
};

#endif //UDP_CLIENT_PACKET_H
