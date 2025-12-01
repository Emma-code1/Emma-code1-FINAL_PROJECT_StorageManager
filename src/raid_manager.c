#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raid_manager.h"

int raid_create(const char *array_name, int level, char **devices, int count) {
    char cmd[512];
    strcpy(cmd, "mdadm --create ");
    strcat(cmd, array_name);
    strcat(cmd, " --level=");
    char lvl[8];
    sprintf(lvl, "%d", level);
    strcat(cmd, lvl);
    strcat(cmd, " --raid-devices=");
    char num[8];
    sprintf(num, "%d", count);
    strcat(cmd, num);
    for (int i=0;i<count;i++) {
        strcat(cmd, " ");
        strcat(cmd, devices[i]);
    }
    return system(cmd);
}

int raid_monitor(raid_array_t *array) {
    char cmd[256];
    sprintf(cmd, "cat /proc/mdstat | grep %s", array->name);
    return system(cmd);
}

int raid_add_disk(const char *array_name, const char *device) {
    char cmd[256];
    sprintf(cmd, "mdadm %s --add %s", array_name, device);
    return system(cmd);
}

int raid_fail_disk(const char *array_name, const char *device) {
    char cmd[256];
    sprintf(cmd, "mdadm %s --fail %s", array_name, device);
    return system(cmd);
}

int raid_remove_disk(const char *array_name, const char *device) {
    char cmd[256];
    sprintf(cmd, "mdadm %s --remove %s", array_name, device);
    return system(cmd);
}

int raid_stop(const char *array_name) {
    char cmd[256];
    sprintf(cmd, "mdadm --stop %s", array_name);
    return system(cmd);
}
