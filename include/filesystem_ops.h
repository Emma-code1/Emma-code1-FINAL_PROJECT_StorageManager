#ifndef FILESYSTEM_OPS_H
#define FILESYSTEM_OPS_H

typedef enum { FS_TYPE_EXT4, FS_TYPE_XFS } fs_type_t;

int fs_create(const char *device, fs_type_t type);
int fs_mount(const char *device, const char *mount_point);
int fs_unmount(const char *mount_point);

#endif
