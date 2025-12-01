#include <stdio.h>
#include <stdlib.h>
#include "lvm_manager.h"

int lvm_pv_create(const char *device) {
    char cmd[256];
    sprintf(cmd, "pvcreate %s", device);
    return system(cmd);
}

int lvm_vg_create(const char *vg_name, char **pvs, int count) {
    char cmd[512];
    sprintf(cmd, "vgcreate %s", vg_name);
    for (int i=0;i<count;i++) {
        strcat(cmd, " ");
        strcat(cmd, pvs[i]);
    }
    return system(cmd);
}

int lvm_lv_create(const char *vg_name, const char *lv_name, unsigned long long size_mb) {
    char cmd[256];
    sprintf(cmd, "lvcreate -L %llum -n %s %s", size_mb, lv_name, vg_name);
    return system(cmd);
}

int lvm_lv_extend(const char *vg_name, const char *lv_name, unsigned long long size_mb) {
    char cmd[256];
    sprintf(cmd, "lvextend -L +%llum /dev/%s/%s", size_mb, vg_name, lv_name);
    return system(cmd);
}
