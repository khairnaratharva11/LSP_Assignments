/*
2) OPEN FILE in Given Mode
    @   Accept file name and mode (R,W,RW,A) from user
    @   Convert mode flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND | O_CREAT).
    @   Open file accordingly and display fd
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd = 0;
    char fileName[30];
    char flag[10];

    printf("Enter the File Name: ");
    scanf("%s", fileName);
    
    printf(" R. Read Only \n W. Write Only \n RW. Read and Write both \n A. Apped or Create\n");
    scanf("%s", flag);

    if (strcmp(flag, "R") == 0)
    {
        fd = open(fileName, O_RDONLY);
    }
    else if (strcmp(flag, "W") == 0)
    {
        fd = open(fileName, O_WRONLY);
    }
    else if (strcmp(flag, "RW") == 0)
    {
        fd = open(fileName, O_RDWR);
    }
    else if (strcmp(flag, "A") == 0)
    {
        fd = open(fileName, O_APPEND | O_CREAT, 0777);
    }
    else
    {
        printf("Invalid Mode!\n");
        return 1;
    }
    
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