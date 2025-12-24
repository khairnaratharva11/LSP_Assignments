/*
3)  Move All Files(Dir->Dir)
    @   Accept source dir and destination dir
    @   Move all regular files:
        #   Use rename() if same filesystem
        #   Else copy + delete
    @   Print count of moved files.
*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char srcDir[100], destDir[100];
    DIR *dp;
    struct dirent *ptr;
    struct stat sobj;
    int count = 0;

    printf("Enter source directory: ");
    scanf("%s", srcDir);

    printf("Enter destination directory: ");
    scanf("%s", destDir);

    dp = opendir(srcDir);
    if (dp == NULL)
    {
        printf("Unable to open source directory\n");
        return -1;
    }

    while ((ptr = readdir(dp)) != NULL)
    {
        if (ptr->d_name[0] == '.')
            continue;

        char oldPath[200], newPath[200];

        strcpy(oldPath, srcDir);
        strcat(oldPath, "/");
        strcat(oldPath, ptr->d_name);

        strcpy(newPath, destDir);
        strcat(newPath, "/");
        strcat(newPath, ptr->d_name);

        lstat(oldPath, &sobj);

        if (S_ISREG(sobj.st_mode))
        {
            if (rename(oldPath, newPath) == 0)
                count++;
        }
    }

    closedir(dp);

    printf("Total files moved: %d\n", count);

    return 0;
}
