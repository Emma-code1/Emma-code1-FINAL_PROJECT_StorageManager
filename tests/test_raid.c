#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    system("dd if=/dev/zero of=tests/disk1.img bs=1M count=16 >/dev/null 2>&1");
    system("dd if=/dev/zero of=tests/disk2.img bs=1M count=16 >/dev/null 2>&1");

    system("losetup -fP tests/disk1.img >/dev/null 2>&1");
    system("losetup -fP tests/disk2.img >/dev/null 2>&1");

    char loop1[128] = {0}, loop2[128] = {0};

    FILE *l = popen("losetup -a | grep disk1.img | cut -d: -f1", "r");
    fgets(loop1, sizeof(loop1), l);
    pclose(l);

    l = popen("losetup -a | grep disk2.img | cut -d: -f1", "r");
    fgets(loop2, sizeof(loop2), l);
    pclose(l);

    loop1[strcspn(loop1, "\n")] = 0;
    loop2[strcspn(loop2, "\n")] = 0;

    char cmd[512];
    snprintf(cmd, sizeof(cmd),
            "sudo mdadm --create /dev/md0 --level=1 --raid-devices=2 %s %s --force >/dev/null 2>&1",
            loop1, loop2);

    if (system(cmd) != 0) {
        printf("RAID create failed\n");
        goto cleanup;
    }

    system("sleep 1");
    system("sudo mkfs.ext4 -F /dev/md0 >/dev/null 2>&1");
    system("sudo mkdir -p /mnt/tests_md");

    if (system("sudo mount /dev/md0 /mnt/tests_md >/dev/null 2>&1") != 0) {
        printf("Mount failed\n");
        goto cleanup;
    }

    system("echo 'raid-test' | sudo tee /mnt/tests_md/hello.txt >/dev/null");
    system("sudo umount /mnt/tests_md >/dev/null 2>&1");

    printf("RAID test OK\n");

cleanup:
    system("sudo mdadm --stop /dev/md0 >/dev/null 2>&1 || true");
    system("losetup -D >/dev/null 2>&1");
    system("rm -f tests/disk1.img tests/disk2.img");
    return 0;
}

