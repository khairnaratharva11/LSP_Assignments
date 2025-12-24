/*
1)  OPEN FILE
        @   Accept file name from user and open it using open().
        @   Print: success message + returned file discriptor.
        @   Handle errors using perror()
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd = 0;
    char fileName[20];
    printf("Enter the file name: ");
    scanf("%s", fileName);

    fd = open(fileName, O_CREAT | O_RDWR, 0777);

    if (fd == -1)
    {
        perror("Error opening file");
    }
    else
    {
        printf("File opened successfully\n");
        printf("File descriptor: %d\n", fd);
        
    }
    close(fd);

    return 0;
}