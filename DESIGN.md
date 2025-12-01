#STORAGE MANAGER — DISEÑO DEL SISTEMA

##Arquitectura General
---------------------
El proyecto se divide en módulos independientes dentro de "src/" que se
comunican únicamente a través de funciones declaradas en "include/".

##Módulos Principales
-------------------
1. RAID Manager
   - Implementa funciones para crear y administrar arreglos RAID usando mdadm.

2. LVM Manager
   - Maneja volúmenes lógicos mediante pvcreate, vgcreate, lvcreate y lvextend.

3. Filesystem Ops
   - Se encarga de la creación de sistemas de archivos y montaje.

4. Memory Manager
   - Crea y habilita swapfiles.

5. Security Manager
   - Operaciones de ACL y LUKS.

6. Backup Engine
   - Implementa backups full e incrementales mediante rsync.

7. Performance Tuner
   - Ajustes de scheduler y readahead.

8. Monitor
   - Obtiene estadísticas básicas (en esta versión inicial: placeholder).

##Daemon + IPC
-------------
El daemon se ejecuta en segundo plano utilizando:
• double fork()
• cierre de file descriptors
• creación de /var/run/storage_mgr.sock
El IPC usa sockets UNIX tipo stream.

##Kernel Module
--------------
Implementa /proc/storage_stats usando la API seq_file.

##Independencia de Módulos
-------------------------
Cada módulo puede compilarse sin depender del funcionamiento de los otros,
cumpliendo con el requisito de trabajo en paralelo.
