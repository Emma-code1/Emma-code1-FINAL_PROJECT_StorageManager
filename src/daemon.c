#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "ipc_server.h"

int daemon_init(void) {
    pid_t pid = fork();
    if (pid != 0) exit(0);
    setsid();
    pid = fork();
    if (pid != 0) exit(0);
    chdir("/");
    close(0); close(1); close(2);
    open("/dev/null", O_RDWR);
    open("/dev/null", O_RDWR);
    open("/dev/null", O_RDWR);
    return 0;
}

int main_daemon(void) {
    daemon_init();
    ipc_server_init("/var/run/storage_mgr.sock");
    ipc_server_run();
    return 0;
}
