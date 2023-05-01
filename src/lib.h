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
unsigned int cloud_booted();

// Called to shut down the background thread if it is running
void cloud_shutdown();

// Get the error module code if there is any
unsigned int cloud_get_error_module();

// Get the error status code if there is any
unsigned int cloud_get_error_status();

// Get current unix timestamp with server offset
unsigned long cloud_clock();

// Get the server state, if it is active or not
unsigned int cloud_get_server_state();

// Check if is running as dev
BOOL cloud_is_dev();

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

// Request resource list contents
unsigned int cloud_resource_info_request();

// Wait for resource list request to complete
unsigned int cloud_resource_info_wait();

// Get contents of resource list
unsigned int cloud_resource_info_get(void *url, unsigned int urlLen, void *hash, int hashLen);

// Get the card as a string of the current user logged in
unsigned int cloud_card_get(char *cardId);

// Make request to check if hash of exe is correct
unsigned int cloud_get_sum_request(char *a1);

// Wait for hash check request
unsigned int cloud_get_sum_wait();

// Get hash response
unsigned int cloud_get_sum_get(char *out, unsigned int outLen);

// Download a file from given url to a directory
unsigned int cloud_download_request(char *url, char *directory);

// Wait for current download to finish downloading (only 1 download exists at a time)
unsigned int cloud_download_wait(char *filePath, unsigned int filePathSize, int *size);

// Get launcher text
unsigned int cloud_get_launcher_info(char *buffer);

// Get error status for xrpc, etc, unchecked
unsigned int cloud_get_acrelay_status(int *a1, int *a2, int *a3);

// Get session time? unchecked
unsigned int cloud_unk1(int *a1);

// Get session time? unchecked
unsigned int cloud_unk2(int *a1);

#endif //OPENCLOUD_LIB_H
