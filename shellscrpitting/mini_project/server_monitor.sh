#!/bin/sh
echo "OS name":
cat /etc/os-release | grep PRETTY_NAME

echo

echo "Architecture version":`uname -m`

echo 

echo "Kernel version": `uname -r`

echo 

echo "Internet status": 
ping -c 1 google.com &> /dev/null && echo "Internet is up" || echo "Internet is down"

echo

echo "IP Address":
ip addr show | grep inet | grep -v 'inet6\|127.0.0.1' | awk '{print $2}' | cut -d/ -f1

echo

echo "memory usage":
free -h

echo

echo "Disk file system usage":
df -h

echo

echo "system uptime":
uptime

