#include <stdlib.h>
#include <stdio.h>
#include "security_manager.h"

int acl_set(const char *path, const char *user, const char *perms) {
    char cmd[256];
    sprintf(cmd, "setfacl -m u:%s:%s %s", user, perms, path);
    return system(cmd);
}

int luks_format(const char *device, const char *pass) {
    char cmd[256];
    sprintf(cmd, "echo -n %s | cryptsetup luksFormat %s -", pass, device);
    return system(cmd);
}

int luks_open(const char *device, const char *name, const char *pass) {
    char cmd[256];
    sprintf(cmd, "echo -n %s | cryptsetup open %s %s -", pass, device, name);
    return system(cmd);
}

int luks_close(const char *name) {
    char cmd[256];
    sprintf(cmd, "cryptsetup close %s", name);
    return system(cmd);
}
