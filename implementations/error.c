//
// Created by Lorenzo on 29/03/21.
//

#include "../headers/error.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Function that prints an error message with its error gravity level
 *
 * @param message The message
 * @param gravity The gravity level
 */
void print_error(char *message, enum error_gravity gravity) {
    printf("%s: %s", convert_error_gravity(gravity), message);
    exit(EXIT_SUCCESS);
}

/**
 * Function that converts a enum error_gravity value to a pointer to characters
 *
 * @param gravity The error gravity
 * @return char *
 */
char *convert_error_gravity(enum error_gravity gravity) {
    switch(gravity) {
        case LOW:
            return "LOW";
        case MIDDLE:
            return "MIDDLE";
        case HIGH:
            return "HIGH";
        default:
            return "ERROR";
    }
}

