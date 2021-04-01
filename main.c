#include "headers/client.h"
#include "headers/timesetter.h"

int main(int argc, char *argv[]) {
    if(argc < 3)  {
        puts("Format: ./main <server name> <server port>");
        exit(EXIT_FAILURE);
    }

    time_t time = run(argv[1], atoi(argv[2]));
    set_time(time);

    return 0;
}
