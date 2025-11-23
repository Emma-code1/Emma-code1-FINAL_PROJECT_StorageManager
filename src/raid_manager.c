#include "raid_manager.h"
#include <stdio.h>
int raid_create(const char *array_name, int level, char **devices, int count){
    // stub: log and return success
    printf("raid_create: %s level=%d count=%d\n", array_name, level, count);
    return 0;
}
int raid_monitor(raid_array_t *array){ return 0; }
int raid_add_disk(const char *array_name, const char *device){ return 0; }
int raid_fail_disk(const char *array_name, const char *device){ return 0; }
int raid_remove_disk(const char *array_name, const char *device){ return 0; }
int raid_stop(const char *array_name){ return 0; }
