#include <windows.h>
#include <stdio.h>
#include <time.h>

#include "lib.h"
#include "config/config.h"
#include "utils/http.h"

// Global vars
BOOL gFinishedBooting = FALSE;
static unsigned int gErrorModule = 0;
static unsigned int gErrorStatus = 0;

// OA043711000000
int cloud_boot(cloud_boot_params *params) {
    if (params == NULL) {
        return 1;
    }

    config_load();

    if (config_get_debug() == TRUE) {
        AllocConsole();

        FILE *fDummy;
        freopen_s(&fDummy, "CONIN$", "r", stdin);
        freopen_s(&fDummy, "CONOUT$", "w", stderr);
        freopen_s(&fDummy, "CONOUT$", "w", stdout);
    }

    if (http_boot() == FALSE) {
        printf("[libcloud] http boot failed\n");
        return 1;
    }

    printf("[libcloud] finished booting\n");
    gFinishedBooting = TRUE;
    return 0;
}

// OA043711000001
unsigned int cloud_booted() {
    unsigned int result = 0;

    if (gFinishedBooting == TRUE) {
        result = 2;
    }

    return result;
}

// OA043711000002
void cloud_shutdown() {
    printf("[libcloud] shutting down...\n");

    http_shutdown();
    FreeConsole();
}

// OA043711000003
unsigned int cloud_get_error_module() {
    return gErrorModule;
}

// OA043711000004
unsigned int cloud_get_error_status() {
    return gErrorStatus;
}

// OA043711000008
unsigned long cloud_clock() {
    unsigned long now = (unsigned long)time(NULL);

    // TODO calc server offset difference
    return now;
}

// OA043711000009
unsigned int cloud_get_server_state() {
    return 1;
}

// OA043711000010
BOOL cloud_is_dev() {
    return config_get_debug();
}

// OA043711000013
uint8_t cloud_get_subscription_status(char *name) {
    printf("[libcloud] %s(%s)\n", __FUNCTION__, name);
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
    printf("[libcloud] %s(%s, %s, %s)\n", __FUNCTION__, serviceName, moduleName, methodName);
    return 0;
}

// OA043711000024
unsigned int cloud_acrelay_wait() {
    return 2;
}

// OA043711000025
unsigned int cloud_acrelay_get(void *node) {
    printf("[libcloud] %s()\n", __FUNCTION__);
    return 0;
}

// OA043711000026
unsigned int cloud_resource_info_request() {
    return 0;
}

// OA043711000027
unsigned int cloud_resource_info_wait() {
    return 0;
}

// OA043711000028
unsigned int cloud_resource_info_get(void *url, unsigned int urlLen, void *hash, int hashLen) {
    return 0;
}

// OA043711000029
unsigned int cloud_card_get(char *cardId) {
    printf("[libcloud] %s(%p)\n", __FUNCTION__, cardId);

    if (cardId == NULL) {
        return 1;
    }

    strncpy(cardId, "0000000000000000", 64);

    return 0;
}

// OA043711000030
unsigned int cloud_get_sum_request(char *a1) {
    return 0;
}

// OA043711000031
unsigned int cloud_get_sum_wait() {
    return 0;
}

// OA043711000032
unsigned int cloud_get_sum_get(char *out, unsigned int outLen) {
    return 0;
}

// OA043711000033
unsigned int cloud_download_request(char *url, char *directory) {
    printf("[libcloud] %s(%s, %s)\n", __FUNCTION__, url, directory);
    return 0;
}

// OA043711000034
unsigned int cloud_download_wait(char *filePath, unsigned int filePathSize, int *size) {
    printf("[libcloud] %s\n", __FUNCTION__);
    return 0;
}

// OA043711000042
unsigned int cloud_get_launcher_info(char *buffer) {
    return 0;
}

// OA043711000046
unsigned int cloud_get_acrelay_status(int *a1, int *a2, int *a3) {
    printf("[libcloud] %s\n", __FUNCTION__);

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
    printf("[libcloud] %s\n", __FUNCTION__);

    if (a1 != NULL) {
        *a1 = 600;
    }

    return 0;
}

// OA043711000051
unsigned int cloud_unk2(int *a1) {
    printf("[libcloud] %s\n", __FUNCTION__);

    return 1;
}
