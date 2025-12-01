#include <stdio.h>
#include <stdlib.h>
#include "backup_engine.h"

int backup_full(const char *src, const char *dest) {
    char cmd[512];
    sprintf(cmd, "rsync -a %s %s/full_", src, dest);
    return system(cmd);
}

int backup_inc(const char *src, const char *dest) {
    char cmd[512];
    sprintf(cmd, "rsync -a --link-dest=%s/full_ %s %s/inc_", dest, src, dest);
    return system(cmd);
}
