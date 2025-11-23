#include "../src/filesystem_ops.h"
int main(){
    fs_create("/dev/vg0/data", FS_TYPE_EXT4, "data_vol");
    return 0;
}
