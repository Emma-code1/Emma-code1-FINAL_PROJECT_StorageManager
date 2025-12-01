#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

int swap_create(const char *path, unsigned long long size_mb);
int swap_enable(const char *path);
int swap_disable(const char *path);

#endif
