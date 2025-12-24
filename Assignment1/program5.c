/*
5)  Read N bytes from file
    @   Accept file name and number of bytes N.
    @   Read exactly N bytes using read() and print on console   
    @   If file contains less than N, print only available bytes.
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

#define SIZE_BUFFER 100

int main()
{
    int fd = 0;
    char Buffer[SIZE_BUFFER];
    int iRet = 0;
    int iNo = 0;

    printf("Enter the Name of file: ");
    scanf("%s",Buffer);

    printf("Enter the number of bytes to be read: ");
    scanf("%d",&iNo);

    memset(Buffer, '\0', SIZE_BUFFER);

    fd = open(Buffer, O_RDONLY);    //IMP

    if(fd<0)
    {
        printf("Unable to open the file\n");
        printf("Reason: %s\n", strerror(errno));

        return -1;
    }
    
    printf("File successfully opened with fd: %d\n", fd);

    iRet = read(Buffer, Buffer, iNo);

    printf("%d bytes gets successfully read\n", iRet);
    
    printf("Data from file: %s\n", Buffer);
    
    close(fd);

    return 0;
}