/*
3)  Check File Access Permission
        @   Accept file name and mode (read\write\execute)
        @   Use access() to check permission for current process
        @   Print "Accessible/ Not Accessible" with reason
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>

int main()
{
    char fileName[50];
    char mode[10];
    int result;

    printf("Enter file name: ");
    scanf("%s", fileName);

    printf("Enter access mode (read / write / execute): ");
    scanf("%s", mode);

    if (strcmp(mode, "read") == 0)
    {
        result = access(fileName, R_OK);
    }
    else if (strcmp(mode, "write") == 0)
    {
        result = access(fileName, W_OK);
    }
    else if (strcmp(mode, "execute") == 0)
    {
        result = access(fileName, X_OK);
    }
    else
    {
        printf("Invalid access mode!\n");
        return 1;
    }

    if (result == 0)
    {
        printf("Accessible: Permission granted for %s access\n", mode);
    }
    else
    {
        perror("Not Accessible:");
    }

    return 0;
}