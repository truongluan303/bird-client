#include "bird_client.h"

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "bird_server_reply_codes.h"
#include "strutils.h"

#ifndef SUN_LEN
#define SUN_LEN(ptr) ((size_t)(((struct sockaddr_un *) 0)->sun_path) +\
                      strlen ((ptr)->sun_path))
#endif // SUN_LEN

#ifdef DONT_BREAK_ON_INTERUPT
static const bool BREAK_ON_INTERUPT = false;
#else
static const bool BREAK_ON_INTERUPT = true;
#endif // DONT_BREAK_ON_INTERUPT


typedef struct _bird_client {
    int server_fd;
    const char* server_socket_path;
} bird_client;


bird_client*
server_connect(const char* server_socket_path) {
    struct sockaddr_un sa;

    // Create socket
    int server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return NULL;
    }

    // Initialize server address structure
    if (strlen(server_socket_path) >= sizeof(sa.sun_path)) {
        (void)printf("Server path too long\n");
        return NULL;
    }
    bzero(&sa, sizeof(sa));
    sa.sun_family = AF_UNIX;
    (void)strcpy(sa.sun_path, server_socket_path);

    // Connect to BIRD server
    if (connect(server_fd, (struct sockaddr*)&sa, SUN_LEN(&sa)) == -1) {
        perror("connect");
        return NULL;
    }

    if (fcntl(server_fd, F_SETFL, O_NONBLOCK)) {
        perror("fcntl");
        return NULL;
    }

    bird_client* client         = (bird_client*)malloc(sizeof(client));
    client->server_fd           = server_fd;
    client->server_socket_path  = server_socket_path;

    char response[1024];
    (void)bird_send_command(client, "show status\n", response);
    if (!strstr(response, STATUS_REPORT)) {
        free(client);
        return NULL;
    }
    return client;
}


void
bird_client_cleanup(bird_client* client) {
    free(client);
}


/**
 * @brief Helper function to get response from BIRD
 */
static ssize_t
read_response(int fd, char* buffer) {
    ssize_t total_bytes_read = 0;
    int read_cr = 0;
    unsigned short irresponsive_count = 0;

    while (1) {
        ssize_t read_result = read(fd, buffer + total_bytes_read, 1);
        if (read_result == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                if (irresponsive_count++ == 10) {
                    buffer[total_bytes_read] = '\0';
                    return total_bytes_read;
                }
                (void)usleep(DELAY_BETWEEN_RETRIES);
                continue;
            } else if (errno == EINTR) {
                if (BREAK_ON_INTERUPT) {
                    return -1;
                }
                continue;
            } else {
                perror("read");
                break;
            }
        } else if (read_result == 0) {
            break; // Peer disconnected
        } else {
            if (buffer[total_bytes_read] == '\r') {
                read_cr = 1;
            } else if ((buffer[total_bytes_read] == '\n') && read_cr) {
                break; // CRLF detected
            } else {
                read_cr = 0;
            }
            total_bytes_read += read_result;
            irresponsive_count = 0;
        }
    }
    buffer[total_bytes_read] = '\0';
    return total_bytes_read;
}


int
bird_send_command(bird_client* client, const char* cmd, char* response) {
    if (client == NULL || cmd == NULL || response == NULL) {
        (void)fprintf(stderr, "Invalid parameters\n");
        return -1;
    }

    // The command must end with a newline. So if it doesn't, add newline.
    char processed_cmd[1024];
    strcpy(processed_cmd, cmd);
    if (!str_endswith(cmd, "\n")) {
        (void)strcat(processed_cmd, "\n");
    }
    size_t cmd_size = strlen(processed_cmd);

    ssize_t bytes_sent = send(client->server_fd, processed_cmd, cmd_size, 0);
    if (bytes_sent == -1 || bytes_sent != cmd_size) {
        perror("send");
        return -1;
    }

    ssize_t retval = read_response(client->server_fd, response);
    printf("---> %ld\n", retval);
    printf("'%s'\n", response);
    return 0;
}


bool
bird_configure(bird_client* client) {
    char* response = (char*)malloc(1024);
    if (bird_send_command(client, "configure\n", response) <= 0) {
        return false;
    }
    free(response);
    return true;
}
