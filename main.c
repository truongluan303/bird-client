#define DONT_BREAK_ON_INTERUPT
#include "src/bird_client.h"

#include <stdio.h>
#include <stdlib.h>

// https://bird.network.cz/doc/bird-4.html

int main() {
    bird_client* client = server_connect("/run/bird/bird.ctl");
    if (client == NULL) {
        printf("Not good\n");
    } else {
        printf("Connected\n");
    }

    char* res = (char*)malloc(10000);
    if (bird_send_command(client, "show status", res) != 0) {
        printf("Failed to send command");
    }

    bird_configure(client);

    bird_send_command(client, "show protocols", res);

    bird_send_command(client, "show interfaces", res);

    bird_client_cleanup(client);
    return 0;
}
