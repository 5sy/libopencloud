#ifndef OPENCLOUD_LIB_H
#define OPENCLOUD_LIB_H

#include <stdint.h>

typedef struct {
    uint32_t boot_type;
    char game[65];
    char client_version[21];
    char token[65];
    uint8_t is_dev;
} cloud_boot_params;

// Called to boot the game with certain params
int cloud_boot(cloud_boot_params *params);

// Called in a loop to check if the thread has finished booting
unsigned int cloud_finished_booting();

// Called to shut down the background thread if it is running
void cloud_shutdown();

// Get the error module code if there is any
unsigned int cloud_get_error_module();

// Get the error status code if there is any
unsigned int cloud_get_error_status();

// Get the server state, if it is active or not
unsigned int cloud_get_server_state();

// Get the subscription status, check if a user is subscribed to param name
uint8_t cloud_get_subscription_status(char *name);

// Make a request to the relay
int cloud_acrelay_request(
    const char *serviceName,
    const char *moduleName,
    const char *methodName,
    void *node,
    unsigned int size
);

// Wait for the relay request to finish
unsigned int cloud_acrelay_wait();

// Retrieve the data returned by the relay as a node
unsigned int cloud_acrelay_get(void *node);

// Get the card as a string of the current user logged in
unsigned int cloud_card_get(char *cardId);

// Download a file from given url to a directory
unsigned int cloud_download_request(char *url, char *directory);

// Wait for current download to finish downloading (only 1 download exists at a time)
unsigned int cloud_download_wait(char *filePath, unsigned int filePathSize, int *size);

// Get error status for xrpc, etc, unchecked
unsigned int cloud_get_acrelay_status(int *a1, int *a2, int *a3);

// Get session time? unchecked
unsigned int cloud_unk1(int *a1);

// Get session time? unchecked
unsigned int cloud_unk2(int *a1);

#endif //OPENCLOUD_LIB_H
