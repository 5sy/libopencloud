#include "config.h"
#include "../utils/ini.h"

typedef struct {
    BOOL debug;
} cloud_config;
static cloud_config gConfig;

static int config_handler(
        void* user,
        const char* section,
        const char* name,
        const char* value) {

    if (strcmp(section, "debug") == 0 && strcmp(name, "enabled") == 0) {
        if (strcmp(value, "1") == 0) {
            gConfig.debug = TRUE;
        } else {
            gConfig.debug = FALSE;
        }
    }

    return 1;
}

BOOL config_load() {
    ZeroMemory(&gConfig, sizeof(cloud_config));

    if (ini_parse("cloud.ini", config_handler, NULL) < 0) {
        return FALSE;
    }

    return TRUE;
}

BOOL config_get_debug() {
    return gConfig.debug;
}
