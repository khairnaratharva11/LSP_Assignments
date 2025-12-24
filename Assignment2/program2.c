/*
2)  Write String to File
    @   Accept file name and string from user
    @   Write string using write() (append mode by default)
    @   Print number of bytes written
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define SIZE 100

int main()
{
    int fd = 0;
    char FileName[SIZE];
    char Data[SIZE];
    int iRet = 0;

    printf("Enter file name: ");
    scanf("%s", FileName);

    printf("Enter string to write: ");
    scanf(" %[^\n]", Data);   // read string with spaces

    fd = open(FileName, O_WRONLY | O_APPEND);
    if (fd < 0)
    {
        printf("Unable to open file\n");
        printf("Reason: %s\n", strerror(errno));
        return -1;
    }

    iRet = write(fd, Data, strlen(Data));
    if (iRet < 0)
    {
        printf("Unable to write to file\n");
        close(fd);
        return -1;
    }

    printf("Number of bytes written: %d\n", iRet);

    close(fd);
    return 0;
}
