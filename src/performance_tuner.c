#include <stdio.h>
#include <stdlib.h>
#include "performance_tuner.h"

int perf_set_scheduler(const char *device, const char *sched) {
    char cmd[256];
    sprintf(cmd, "echo %s > /sys/block/%s/queue/scheduler", sched, device);
    return system(cmd);
}

int perf_set_readahead(const char *device, int kb) {
    char cmd[256];
    sprintf(cmd, "blockdev --setra %d /dev/%s", kb, device);
    return system(cmd);
}
