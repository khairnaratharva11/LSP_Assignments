/*
1)  Copy File Contents(source->destination)
    @   Accept source_file and dest_file.
    @   Create destination if not existes(O_CREAT | O_TRUNC).
    @   Copy using buffered read()/write() loop.
    @   Preserve permissions(optional bonus using stat()+chmod()).
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int fdSrc, fdDest;
    int iRet;
    char buffer[BUFSIZE];
    struct stat sobj;

    if (argc != 3)
    {
        printf("Usage: %s source_file dest_file\n", argv[0]);
        return -1;
    }

    fdSrc = open(argv[1], O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to open source file\n");
        return -1;
    }

    fstat(fdSrc, &sobj);   
    fdDest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, sobj.st_mode);
    if (fdDest == -1)
    {
        printf("Unable to create destination file\n");
        close(fdSrc);
        return -1;
    }

    while ((iRet = read(fdSrc, buffer, BUFSIZE)) > 0)
    {
        write(fdDest, buffer, iRet);
    }

    close(fdSrc);
    close(fdDest);

    printf("File copied successfully\n");
    return 0;
}
