#include <stdio.h>
#include <stdlib.h>
#include "monitor.h"

int monitor_get_stats(const char *device, device_stats_t *s) {
    s->reads = 0;
    s->writes = 0;
    return 0;
}
