/*
3)  List All Files From Directory
    @   Accept directory name
    @   Use opendir() / readdir()
    @   Print only names (skip . and ..)
*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define SIZE 100

int main()
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    char DirName[SIZE];

    printf("Enter directory name: ");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if (dp == NULL)
    {
        printf("Reason: %s\n", strerror(errno));
        return -1;
    }

    printf("Files in directory:\n");

    while ((ptr = readdir(dp)) != NULL)
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        {
            continue;
        }

        printf("%s\n", ptr->d_name);
    }

    closedir(dp);
    return 0;
}