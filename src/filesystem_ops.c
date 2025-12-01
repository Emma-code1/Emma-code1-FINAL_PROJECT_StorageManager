#include <stdio.h>
#include <stdlib.h>
#include "filesystem_ops.h"

int fs_create(const char *device, fs_type_t type) {
    char cmd[256];
    if (type == FS_TYPE_EXT4) sprintf(cmd, "mkfs.ext4 %s", device);
    else sprintf(cmd, "mkfs.xfs -f %s", device);
    return system(cmd);
}

int fs_mount(const char *device, const char *mount_point) {
    char cmd[256];
    sprintf(cmd, "mount %s %s", device, mount_point);
    return system(cmd);
}

int fs_unmount(const char *mount_point) {
    char cmd[256];
    sprintf(cmd, "umount %s", mount_point);
    return system(cmd);
}
