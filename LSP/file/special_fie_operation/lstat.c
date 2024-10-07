#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




/*

struct stat {
               dev_t     st_dev;        // ID of device containing file
               ino_t     st_ino;         // Inode number
               mode_t    st_mode;        // File type and mode
               nlink_t   st_nlink;       / Number of hard links
               uid_t     st_uid;         // User ID of owner
               gid_t     st_gid;         // Group ID of owner
               dev_t     st_rdev;        // Device ID (if special file)
               off_t     st_size;        // Total size, in bytes
               blksize_t st_blksize;     // Block size for filesystem I/O
               blkcnt_t  st_blocks;      // Number of 512B blocks allocated

                Since Linux 2.6, the kernel supports nanosecond
                  precision for the following timestamp fields.
                  For the details before Linux 2.6, see NOTES.

               struct timespec st_atim;  // Time of last access
               struct timespec st_mtim;  // Time of last modification
               struct timespec st_ctim;  // Time of last status change

           #define st_atime st_atim.tv_sec      // Backward compatibility
           #define st_mtime st_mtim.tv_sec
           #define st_ctime st_ctim.tv_sec
           

};


*/


int main(int argc,char *argv[]){



struct stat t;
int ret;
ret=stat(argv[1],&t);
if(ret<0){
perror("stat failed\n");
}
printf("using stst \n\n ");
printf("Dev Address of file     :  %ld\n",t.st_dev);
printf("inode number of file    :  %ld\n",t.st_ino);
printf("Mode of od file is :  %o\n",t.st_mode& 000777);
printf("UID Of File is :  %d\n",t.st_uid);
printf("GID Of File is :  %d\n",t.st_gid);
printf("Size Of File is :  %ld\n",t.st_size);



printf("============>>LAST TIME CHANGE <<===========\n\n");

printf("Last status change:       %s", ctime(&t.st_ctime));
        printf("Last file access:         %s", ctime(&t.st_atime));
        printf("Last file modification:   %s", ctime(&t.st_mtime));



printf("using lstat : \n\n\n");

ret=lstat(argv[1],&t);
if(ret<0){
perror("stat failed\n");
}

printf("Dev Address of file     :  %ld\n",t.st_dev);
printf("inode number of file    :  %ld\n",t.st_ino);
printf("Mode of od file is :  %o\n",t.st_mode& 000777);
printf("UID Of File is :  %d\n",t.st_uid);
printf("GID Of File is :  %d\n",t.st_gid);
printf("Size Of File is :  %ld\n",t.st_size);

printf("============>>LAST TIME CHANGE <<===========\n\n");

printf("Last status change:       %s", ctime(&t.st_ctime));
        printf("Last file access:         %s", ctime(&t.st_atime));
        printf("Last file modification:   %s", ctime(&t.st_mtime));



}

