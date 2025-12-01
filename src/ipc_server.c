#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include "ipc_server.h"

static int server_fd;

int ipc_server_init(const char *path) {
    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, path);
    unlink(path);
    return bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
}

int ipc_server_run(void) {
    listen(server_fd, 5);
    while (1) {
        int c = accept(server_fd, NULL, NULL);
        if (c >= 0) {
            write(c, "OK", 2);
            close(c);
        }
    }
    return 0;
}
