#STORAGE MANAGER — README

##Descripción
------------
Este proyecto implementa un sistema de gestión de almacenamiento para Linux,
incluyendo RAID, LVM, sistemas de archivos, swap, backups, seguridad, un daemon
con IPC por socket UNIX y un módulo del kernel para estadísticas.

##Características principales
---------------------------
• Gestión de RAID mediante "mdadm".
• Gestión de LVM (PV/VG/LV).
• Creación y montaje de sistemas de archivos (ext4, xfs).
• Administración de swap.
• Backups full e incrementales utilizando rsync.
• Seguridad con ACL y LUKS.
• Ajustes de rendimiento (scheduler, readahead).
• Daemon en segundo plano con servidor IPC.
• Módulo del kernel que expone estadísticas en /proc/storage_stats.

##Compilación
-----------
make

##Ejecución del daemon
--------------------
sudo ./storage_daemon &

##Uso del CLI
-----------
./storage_cli <comandos>

##Requisitos
----------
• Linux
• mdadm
• lvm2
• rsync
• util-linux (losetup)
• socat o netcat
