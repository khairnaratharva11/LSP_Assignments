/*
5)  Find Largest File in Directory
    @   Accept Directory name.
    @   Find and print:
        #   largest file
        #   its size in bytes
    @   Consider only regular files(ignore directories).
*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    DIR *dp;
    struct dirent *ptr;
    struct stat sobj;
    char dirname[100];
    long max = 0;
    char fname[100];

    printf("Enter directory name: ");
    scanf("%s", dirname);

    chdir(dirname);   // change working directory

    dp = opendir(".");
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while ((ptr = readdir(dp)) != NULL)
    {
        if (ptr->d_name[0] == '.')
            continue;

        lstat(ptr->d_name, &sobj);

        if (S_ISREG(sobj.st_mode) && sobj.st_size > max)
        {
            max = sobj.st_size;
            strcpy(fname, ptr->d_name);
        }
    }

    closedir(dp);

    printf("Largest file: %s\n", fname);
    printf("Size: %ld bytes\n", max);

    return 0;
}