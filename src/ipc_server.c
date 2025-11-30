#include "ipc_server.h"
#include <stdio.h>
int ipc_server_init(const char *socket_path){ printf("ipc init %s\n", socket_path); return 0;}
int ipc_server_run(void){ printf("ipc run (stub)\n"); return 0;}
int ipc_handle_request(int client_fd, request_t *req, response_t *resp){ return 0;}
