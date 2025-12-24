/*
2)  Check File Present in Directory
    @   Accept directory name and file name.
    @   Check whether that file extis in that directory.
    @   Print absolute matched path if found.
*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main()
{
    DIR *dp;
    struct dirent *ptr;
    char dirname[100];
    char filename[100];
    char fullpath[500];

    printf("Enter directory name: ");
    scanf("%s", dirname);

    printf("Enter file name: ");
    scanf("%s", filename);

    dp = opendir(dirname);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    chdir(dirname);   
    
    while ((ptr = readdir(dp)) != NULL)
    {
        if (strcmp(ptr->d_name, filename) == 0)
        {
            realpath(ptr->d_name, fullpath);
            printf("File found at: %s\n", fullpath);
            break;
        }
    }

    closedir(dp);
}
