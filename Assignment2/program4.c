/*
4)  List Files with Type
    @   Accept directory name.
    @   Print each entry with its type: Regular/Directory/Link/FIFO/Socket/Char/Block   
    @   Use lstat() for accurate type.
*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
    int iRet = 0;
    struct stat sobj;
    char fileName[20];

    printf("ENter the directory name: ");
    scanf("%s",fileName);

    iRet = lstat(fileName, &sobj);

    if (iRet == -1)
    {
        printf("Unable to get file information\n");
        return -1;
    }

    printf("File Name: %s\n",fileName);

    if (S_ISREG(sobj.st_mode))
        printf("File Type: Regular File\n");
    else if (S_ISDIR(sobj.st_mode))
        printf("File Type: Directory\n");
    else if (S_ISLNK(sobj.st_mode))
        printf("File Type: Symbolic Link\n");
    else
        printf("File Type: Other\n");

    return 0;
}
