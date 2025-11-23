#include "../src/raid_manager.h"
int main(){
    char *devices[] = {"/dev/loop0","/dev/loop1"};
    raid_create("/dev/md0", 1, devices, 2);
    return 0;
}
