#include <stdio.h>
#include <string.h>
#include "../include/common.h"
#include "../include/raid_manager.h"
#include "../include/lvm_manager.h"
#include "../include/filesystem_ops.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        print_error("Not enough arguments");
        return 1;
    }
    printf("CLI OK\n");
    return 0;
}
