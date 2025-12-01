#ifndef PERFORMANCE_TUNER_H
#define PERFORMANCE_TUNER_H

int perf_set_scheduler(const char *device, const char *sched);
int perf_set_readahead(const char *device, int kb);

#endif

