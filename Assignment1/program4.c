/*
4)  Display Complete File Information
    @   Size,Inode, permissions, hard links, owner uid/gid, file type, last access/modify time
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
int main()
{
    int iRet =0;
    char fileName[20];
    printf("Enter the File name : ");
    scanf("%s",fileName);

    struct stat sobj;

    iRet = stat(fileName, &sobj);
    
    if (iRet == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Inode Number       : %ld\n", sobj.st_ino);
    printf("Hard Link Count    : %ld\n", sobj.st_nlink);
    printf("File Size          : %ld bytes\n", sobj.st_size);
    printf("Block Size         : %ld\n", sobj.st_blksize);

    printf("Owner UID          : %d\n", sobj.st_uid);
    printf("Owner GID          : %d\n", sobj.st_gid);

    printf("File Type          : ");
    if (S_ISREG(sobj.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(sobj.st_mode))
        printf("Directory\n");
    else
        printf("Other\n");
    printf("Last Access Time   : %s", ctime(&sobj.st_atime));
    printf("Last Modify Time   : %s", ctime(&sobj.st_mtime));

    return 0;
}