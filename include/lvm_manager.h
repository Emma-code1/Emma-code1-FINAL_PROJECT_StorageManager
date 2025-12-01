#ifndef LVM_MANAGER_H
#define LVM_MANAGER_H

int lvm_pv_create(const char *device);
int lvm_vg_create(const char *vg_name, char **pvs, int pv_count);
int lvm_lv_create(const char *vg_name, const char *lv_name, unsigned long long size_mb);
int lvm_lv_extend(const char *vg_name, const char *lv_name, unsigned long long size_mb);

#endif
