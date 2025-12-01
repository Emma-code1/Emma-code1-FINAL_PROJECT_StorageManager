#!/bin/bash
set -e
echo "Compilando tests..."
gcc tests/test_raid.c -o tests/test_raid
gcc tests/test_lvm.c -o tests/test_lvm
gcc tests/test_filesystem.c -o tests/test_filesystem
gcc tests/test_backup.c -o tests/test_backup
echo "Ejecutando test_raid (requiere sudo)..."
sudo ./tests/test_raid
echo "Ejecutando test_lvm (requiere sudo)..."
sudo ./tests/test_lvm
echo "Ejecutando test_filesystem (requiere sudo)..."
sudo ./tests/test_filesystem
echo "Ejecutando test_backup..."
./tests/test_backup
echo "Integración OK"
