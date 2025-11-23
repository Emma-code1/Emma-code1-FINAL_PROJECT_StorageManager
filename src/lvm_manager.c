#include "lvm_manager.h"
#include <stdio.h>
int lvm_pv_create(const char *device){ printf("pv_create %s\n", device); return 0;}
int lvm_vg_create(const char *vg_name, char **pvs, int pv_count){ printf("vg_create %s\n", vg_name); return 0;}
int lvm_lv_create(const char *vg_name, const char *lv_name, unsigned long long size_mb){ printf("lv_create %s/%s %llu\n", vg_name, lv_name, size_mb); return 0;}
int lvm_lv_extend(const char *vg_name, const char *lv_name, unsigned long long add_size_mb){ return 0; }
int lvm_snapshot_create(const char *vg_name, const char *origin_lv, const char *snapshot_name, unsigned long long size_mb){ return 0; }
