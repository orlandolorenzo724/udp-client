//
// Created by lorenzo on 29/03/21.
//

#include "../headers/timesetter.h"
#include "../headers/error.h"

#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Sets the system's correct time
 *
 * @param time The time object retrieved from a NTP server
 */
void set_time(time_t time) {
    // Setting the time zone
    setenv("TZ", "UTC", 1);

    // ISO C time structure that takes the time object from a NTP server
    // This structure is created to modify the time correctly
    // Later it will be passed again to a time_t object
    struct tm *temp_time = gmtime(&time);
    temp_time->tm_year += 1900;
    temp_time->tm_mon += 1;
    temp_time->tm_hour += 2;

    // Converting the previous tm structure to time_t
    time_t current_time = mktime(temp_time);

    // System time setter
    struct timeval setter;
    setter.tv_sec = current_time;
    setter.tv_usec = 0;

    // Setting the time and checking for any error
    int result = settimeofday(&setter, NULL);
    if(result == -1) {
        print_error("Error setting the time\n", HIGH);
    }

    puts("Time set with success\n");
}

