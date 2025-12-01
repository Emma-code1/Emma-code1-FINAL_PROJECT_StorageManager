STORAGE MANAGER — MANUAL DE USUARIO
---------------------

Introducción
-------------
Storage Manager es una herramienta para administrar dispositivos de
almacenamiento en Linux mediante una interfaz de línea de comandos (CLI).

1. RAID
--------
Crear RAID1:
    sudo mdadm --create /dev/md0 --level=1 --raid-devices=2 <disk1> <disk2>

Monitorear RAID:
    cat /proc/mdstat

Detener RAID:
    sudo mdadm --stop /dev/md0

2. LVM
------
Crear PV:
    sudo pvcreate /dev/loop0

Crear VG:
    sudo vgcreate vg1 /dev/loop0

Crear LV:
    sudo lvcreate -L 1G -n lv1 vg1

Montar LV:
    sudo mkfs.ext4 /dev/vg1/lv1
    sudo mount /dev/vg1/lv1 /mnt

3. Sistemas de Archivos
------------------------
Crear filesystem:
    sudo mkfs.ext4 /dev/md0

Montar:
    sudo mount /dev/md0 /mnt

Desmontar:
    sudo umount /mnt

4. Swap
--------
Crear swap:
    dd if=/dev/zero of=/swapfile bs=1M count=1024
    mkswap /swapfile
    swapon /swapfile

5. Backups
-----------
Backup completo:
    rsync -a SRC/ DEST/full_

Backup incremental:
    rsync -a --link-dest=DEST/full_ SRC/ DEST/inc_

6. Seguridad
------------
ACL:
    setfacl -m u:user:rw file

LUKS:
    cryptsetup luksFormat /dev/sdx
    cryptsetup open /dev/sdx secure

7. Demonio e IPC
-----------------
Iniciar daemon:
    sudo ./storage_daemon &

Conectarse:
    echo | socat - UNIX-CONNECT:/var/run/storage_mgr.sock

