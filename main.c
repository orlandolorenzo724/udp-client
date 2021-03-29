#include "headers/client.h"
#include "headers/timesetter.h"

int main(int argc, char *argv[]) {
    if(argc < 3)  {
        puts("Format: ./main <server name> <server port>");
        exit(EXIT_SUCCESS);
    }

    time_t time = run(argv[1], atoi(argv[2]));
    char *time_c = ctime((const time_t *) &time);
    printf("%s\n", time_c);

    set_time(time);

    return 0;
}