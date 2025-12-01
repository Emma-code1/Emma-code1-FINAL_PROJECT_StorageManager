#STORAGE MANAGER — REFERENCIA DE API

###RAID Manager (raid_manager.h)
------------------------------
int raid_create(const char *array, int level, char **devices, int count);
int raid_monitor(raid_array_t *array);
int raid_add_disk(const char *array, const char *device);
int raid_fail_disk(const char *array, const char *device);
int raid_remove_disk(const char *array, const char *device);
int raid_stop(const char *array);

###LVM Manager (lvm_manager.h)
---------------------------
int lvm_pv_create(const char *device);
int lvm_vg_create(const char *vg, char **pvs, int count);
int lvm_lv_create(const char *vg, const char *lv, unsigned long long size_mb);
int lvm_lv_extend(const char *vg, const char *lv, unsigned long long size_mb);

###Filesystem Ops (filesystem_ops.h)
----------------------------------
int fs_create(const char *device, fs_type_t type);
int fs_mount(const char *device, const char *mount_point);
int fs_unmount(const char *mount_point);

###Memory Manager (memory_manager.h)
---------------------------------
int swap_create(const char *path, unsigned long long size_mb);
int swap_enable(const char *path);
int swap_disable(const char *path);

###Security Manager (security_manager.h)
-------------------------------------
int acl_set(const char *path, const char *user, const char *perms);
int luks_format(const char *device, const char *pass);
int luks_open(const char *device, const char *name, const char *pass);
int luks_close(const char *name);

###Backup Engine (backup_engine.h)
-------------------------------
int backup_full(const char *src, const char *dest);
int backup_inc(const char *src, const char *dest);

###Performance Tuner (performance_tuner.h)
----------------------------------------
int perf_set_scheduler(const char *device, const char *sched);
int perf_set_readahead(const char *device, int kb);

###Monitor (monitor.h)
--------------------
int monitor_get_stats(const char *device, device_stats_t *s);

###IPC Server (ipc_server.h)
--------------------------
int ipc_server_init(const char *path);
int ipc_server_run(void);

###Common (common.h)
------------------
void print_error(const char *msg);
