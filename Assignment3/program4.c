/*
4)  Delete All Empty Regular Files
    @   Accept directory name.
    @   Delete files with size=0 bytes(regular files only).
    @   Print names deleted + total deleted count.
*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char dirName[100];
    DIR *dp;
    struct dirent *ptr;
    struct stat sobj;
    int count = 0;
    char path[200];

    printf("Enter directory name: ");
    scanf("%s", dirName);

    dp = opendir(dirName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while ((ptr = readdir(dp)) != NULL)
    {
        if (ptr->d_name[0] == '.')
            continue;

        strcpy(path, dirName);
        strcat(path, "/");
        strcat(path, ptr->d_name);

        lstat(path, &sobj);

        if (S_ISREG(sobj.st_mode) && sobj.st_size == 0)
        {
            unlink(path);
            printf("Deleted: %s\n", ptr->d_name);
            count++;
        }
    }

    closedir(dp);

    printf("Total empty files deleted: %d\n", count);

    return 0;
}
