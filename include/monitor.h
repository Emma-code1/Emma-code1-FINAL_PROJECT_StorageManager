#ifndef MONITOR_H
#define MONITOR_H

typedef struct {
    unsigned long long reads;
    unsigned long long writes;
} device_stats_t;

int monitor_get_stats(const char *device, device_stats_t *s);

#endif
