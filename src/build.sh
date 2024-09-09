#!/bin/bash

#echo "[+] Building commands..."
#gcc commands.c -o commands.o


echo "[+] Building xShell..."
gcc  main.c -o shell

echo "[+] Run  xShell"
chmod +x shell
./shell


