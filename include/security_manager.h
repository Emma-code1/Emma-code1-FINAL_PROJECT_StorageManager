#ifndef SECURITY_MANAGER_H
#define SECURITY_MANAGER_H

int acl_set(const char *path, const char *user, const char *perms);
int luks_format(const char *device, const char *pass);
int luks_open(const char *device, const char *name, const char *pass);
int luks_close(const char *name);

#endif
