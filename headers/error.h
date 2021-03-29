/**
 * Created by Lorenzo on 29/03/21.
*/

#ifndef UDP_CLIENT_ERROR_H
#define UDP_CLIENT_ERROR_H

/**
 * Struct for defining error gravity
 */
enum error_gravity {
    LOW,
    MIDDLE,
    HIGH
};

/**
 * Function that prints an error message with its error gravity level
 *
 * @param message The message
 * @param gravity The gravity level
 */
void print_error(char *message, enum error_gravity gravity);

/**
 * Function that converts a enum error_gravity value to a pointer to characters
 *
 * @param gravity The error gravity
 * @return char *
 */
char *convert_error_gravity(enum error_gravity gravity);

#endif //UDP_CLIENT_ERROR_H
