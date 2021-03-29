//
// Created by lorenzo on 29/03/21.
//

#ifndef UDP_CLIENT_TIMESETTER_H
#define UDP_CLIENT_TIMESETTER_H

#include <sys/time.h>

/**
 * Sets the system's correct time
 *
 * @param time The time object retrieved by a NTP server
 */
void set_time(time_t time);

#endif //UDP_CLIENT_TIMESETTER_H
