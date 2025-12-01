#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    system("dd if=/dev/zero of=tests/pv.img bs=1M count=32 >/dev/null 2>&1");
    system("losetup -fP tests/pv.img >/dev/null 2>&1");
    FILE *l = popen("losetup -a | grep pv.img | cut -d: -f1", "r");
    char loop[128] = {0};
    fgets(loop, sizeof(loop), l); pclose(l);
    loop[strcspn(loop, "\n")] = 0;
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "sudo pvcreate %s >/dev/null 2>&1", loop);
    if (system(cmd) != 0) { printf("pvcreate failed\n"); goto cleanup; }
    system("sudo vgcreate test_vg $(losetup -a | grep pv.img | cut -d: -f1) >/dev/null 2>&1");
    system("sudo lvcreate -n test_lv -L 20M test_vg >/dev/null 2>&1");
    system("sudo mkfs.ext4 -F /dev/test_vg/test_lv >/dev/null 2>&1");
    system("sudo mkdir -p /mnt/test_lv");
    if (system("sudo mount /dev/test_vg/test_lv /mnt/test_lv >/dev/null 2>&1") != 0) { printf("mount lv failed\n"); goto cleanup; }
    system("echo 'lvm-test' | sudo tee /mnt/test_lv/ok.txt >/dev/null");
    system("sudo umount /mnt/test_lv >/dev/null 2>&1");
    printf("LVM test OK\n");
cleanup:
    system("sudo lvremove -f /dev/test_vg/test_lv >/dev/null 2>&1 || true");
    system("sudo vgremove -f test_vg >/dev/null 2>&1 || true");
    system("sudo pvremove -f $(losetup -a | grep pv.img | cut -d: -f1) >/dev/null 2>&1 || true");
    system("losetup -a | grep pv.img | cut -d: -f1 | xargs -r sudo losetup -d >/dev/null 2>&1 || true");
    system("rm -f tests/pv.img");
    return 0;
}
