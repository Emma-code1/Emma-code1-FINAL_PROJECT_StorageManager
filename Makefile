CC=gcc
CFLAGS=-Iinclude -Wall

SRC=src/main.c src/daemon.c src/ipc_server.c src/raid_manager.c \
    src/lvm_manager.c src/filesystem_ops.c src/memory_manager.c \
    src/security_manager.c src/backup_engine.c src/performance_tuner.c \
    src/monitor.c src/utils.c

OBJ=$(SRC:.c=.o)

all: storage_daemon storage_cli

storage_daemon: $(OBJ)
	$(CC) $(OBJ) -o storage_daemon

storage_cli:
	$(CC) cli/storage_cli.c src/utils.o -Iinclude -o storage_cli

clean:
	rm -f $(OBJ) storage_daemon storage_cli
