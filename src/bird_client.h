#ifndef BIRD_CLIENT__BIRD_CLIENT_H
#define BIRD_CLIENT_H

#ifndef MAX_RESPONSE_SIZE
#define MAX_RESPONSE_SIZE       10000
#endif // MAX_RESPONSE_SIZE

#ifndef DELAY_BETWEEN_RETRIES
#define DELAY_BETWEEN_RETRIES   2000 /* unit: microsecond */
#endif // DELAY_BETWEEN_RETRIES

#include <stdbool.h>

#include "data_structures/vector.h"


/******************************************************************************
 * @brief Represents a connection to the BIRD server.
 *****************************************************************************/
typedef struct _bird_client bird_client;

/******************************************************************************
 * @brief Connect to the BIRD server.
 *
 * @param[in] server_path   Path to the BIRD server's control file (.ctl).
 *
 * @return The bird_client instance if the connecting process was successful,
 *         NULL otherwise.
 *****************************************************************************/
bird_client* server_connect(const char* server_path);

/******************************************************************************
 * @brief Deallocate a bird_client.
 *
 * @param client The client to be deallocated.
 *****************************************************************************/
void bird_client_cleanup(bird_client* client);

/******************************************************************************
 * @brief Sends a command to the server.
 *
 * @param[in] client    The BIRD client.
 * @param[in] cmd       The command to be sent.
 * @param[out] response The response received from BIRD server.
 *****************************************************************************/
int bird_send_command(bird_client* client, const char* cmd, char* response);

bool bird_configure(bird_client* client);

#endif // BIRD_CLIENT__BIRD_CLIENT_H
