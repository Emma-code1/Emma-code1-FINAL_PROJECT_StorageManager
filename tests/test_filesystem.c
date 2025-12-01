#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("dd if=/dev/zero of=tests/fs.img bs=1M count=16 >/dev/null 2>&1");
    system("losetup -fP tests/fs.img >/dev/null 2>&1");
    FILE *l = popen("losetup -a | grep fs.img | cut -d: -f1", "r");
    char loop[128] = {0};
    fgets(loop, sizeof(loop), l); pclose(l);
    loop[strcspn(loop, "\n")] = 0;
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "sudo mkfs.ext4 -F %s >/dev/null 2>&1", loop);
    if (system(cmd) != 0) { printf("mkfs failed\n"); goto cleanup; }
    system("sudo mkdir -p /mnt/test_fs");
    snprintf(cmd, sizeof(cmd), "sudo mount %s /mnt/test_fs >/dev/null 2>&1", loop);
    if (system(cmd) != 0) { printf("mount failed\n"); goto cleanup; }
    system("echo 'fs-test' | sudo tee /mnt/test_fs/file.txt >/dev/null");
    system("sudo umount /mnt/test_fs >/dev/null 2>&1");
    printf("Filesystem test OK\n");
cleanup:
    system("losetup -a | grep fs.img | cut -d: -f1 | xargs -r sudo losetup -d >/dev/null 2>&1 || true");
    system("rm -f tests/fs.img");
    return 0;
}
