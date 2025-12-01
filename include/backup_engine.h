#ifndef BACKUP_ENGINE_H
#define BACKUP_ENGINE_H

int backup_full(const char *src, const char *dest);
int backup_inc(const char *src, const char *dest);

#endif
