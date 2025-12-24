/*
1)  Read Whole file
    @   Accept file name and print full content on console.
    @   Use a buffer loop read() until 0.
    @   Show total bytes read.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define SIZE_BUFFER 100

int main()
{
    int fd = 0;
    char FileName[SIZE_BUFFER];
    char Buffer[SIZE_BUFFER];
    int iRet = 0;
    int totalBytes = 0;

    printf("Enter the Name of file: ");
    scanf("%s", FileName);

    fd = open(FileName, O_RDONLY);
    if (fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason: %s\n", strerror(errno));
        return -1;
    }

    printf("File successfully opened with fd: %d\n", fd);
        
    iRet = read(fd, Buffer, SIZE_BUFFER);
    while (iRet > 0)
    {
        write(STDOUT_FILENO, Buffer, iRet);
        totalBytes += iRet;

        iRet = read(fd, Buffer, SIZE_BUFFER); // IMPORTANT
    }

    if (iRet < 0)
    {
        printf("Error while reading file\n");
        close(fd);
        return -1;
    }

    printf("\nTotal bytes read: %d\n", totalBytes);

    close(fd);
    return 0;
}
