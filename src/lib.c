#include <windows.h>

#include "lib.h"

// Global vars
BOOL gFinishedBooting = FALSE;
static unsigned int gErrorModule = 0;
static unsigned int gErrorStatus = 0;

// OA043711000000
int cloud_boot(cloud_boot_params *params) {
    if (params == NULL) {
        return 2;
    }

    gFinishedBooting = TRUE;
    return 0;
}

// OA043711000001
unsigned int cloud_finished_booting() {
    if (gFinishedBooting == TRUE) {
        return 2;
    }

    return 0;
}

// OA043711000002
void cloud_shutdown() { }

// OA043711000003
unsigned int cloud_get_error_module() {
    return gErrorModule;
}

// OA043711000004
unsigned int cloud_get_error_status() {
    return gErrorStatus;
}

// OA043711000009
unsigned int cloud_get_server_state() {
    return 1;
}

// OA043711000013
uint8_t cloud_get_subscription_status(char *name) {
    return 1;
}

// OA043711000023
int cloud_acrelay_request(
        const char *serviceName,
        const char *moduleName,
        const char *methodName,
        void *node,
        unsigned int size
) {
    return 0;
}

// OA043711000024
unsigned int cloud_acrelay_wait() {
    return 2;
}

// OA043711000025
unsigned int cloud_acrelay_get(void *node) {
    return 0;
}

// OA043711000029
unsigned int cloud_card_get(char *cardId) {
    if (cardId == NULL) {
        return 1;
    }

    strncpy(cardId, "0000000000000000", 64);

    return 0;
}

// OA043711000033
unsigned int cloud_download_request(char *url, char *directory) {
    return 0;
}

// OA043711000034
unsigned int cloud_download_wait(char *filePath, unsigned int filePathSize, int *size) {
    return 0;
}

// OA043711000046
unsigned int cloud_get_acrelay_status(int *a1, int *a2, int *a3) {
    if (a1 != NULL) {
        *a1 = 0;
    }

    if (a2 != NULL) {
        *a2 = 0;
    }

    if (a3 != NULL) {
        *a3 = 0;
    }

    return 0;
}

// OA043711000050
unsigned int cloud_unk1(int *a1) {
    if (a1 != NULL) {
        *a1 = 600;
    }

    return 0;
}

// OA043711000051
unsigned int cloud_unk2(int *a1) {
    return 1;
}
