// src/ipc_server.h
#ifndef IPC_SERVER_H
#define IPC_SERVER_H
#include <stdint.h>
typedef enum { CMD_RAID_CREATE, CMD_LVM_CREATE, CMD_FS_MOUNT, CMD_BACKUP_CREATE, CMD_MONITOR_STATS, CMD_STATUS } command_type_t;
typedef struct {
    uint32_t version;
    uint32_t request_id;
    command_type_t command;
    uint32_t payload_size;
    char payload[4096];
} request_t;
typedef struct {
    uint32_t request_id;
    int status;
    char error_msg[256];
    uint32_t data_size;
    char data[4096];
} response_t;
int ipc_server_init(const char *socket_path);
int ipc_server_run(void);
int ipc_handle_request(int client_fd, request_t *req, response_t *resp);
#endif
