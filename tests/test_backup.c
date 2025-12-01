#include <stdio.h>
#include <stdlib.h>

int main() {
    system("rm -rf tests/backup_src tests/backup_dest >/dev/null 2>&1 || true");
    system("mkdir -p tests/backup_src");
    system("echo 'file1' > tests/backup_src/a.txt");
    system("mkdir -p tests/backup_dest");
    if (system("rsync -a tests/backup_src tests/backup_dest/full_ >/dev/null 2>&1") != 0) { printf("rsync failed\n"); return 1; }
    if (system("test -f tests/backup_dest/full_/backup_src/a.txt") != 0) { printf("backup missing\n"); return 1; }
    printf("Backup test OK\n");
    return 0;
}
