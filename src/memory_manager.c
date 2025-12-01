#include <stdio.h>
#include <stdlib.h>
#include "memory_manager.h"

int swap_create(const char *path, unsigned long long size_mb) {
    char cmd[256];
    sprintf(cmd, "dd if=/dev/zero of=%s bs=1M count=%llu", path, size_mb);
    system(cmd);
    sprintf(cmd, "mkswap %s", path);
    return system(cmd);
}

int swap_enable(const char *path) {
    char cmd[256];
    sprintf(cmd, "swapon %s", path);
    return system(cmd);
}

int swap_disable(const char *path) {
    char cmd[256];
    sprintf(cmd, "swapoff %s", path);
    return system(cmd);
}
