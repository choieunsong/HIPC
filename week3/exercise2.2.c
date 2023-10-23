#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 10

/**
 * read file and write in another file
*/
// Version2: using file descriptors only
int main(int argc, char const *argv[])
{
    int fd1 = open("./textfile1.txt", O_RDONLY);
    int x;

    if(fd1 < 0){
        write(2, "Error opening file\n", sizeof("Error opening file\n"));
        exit(1);
    }

    int fd2 = open("./textfile3.txt", O_WRONLY | O_CREAT);
    char str[BUFSIZE];

    // create and write into a new file
    while((x = read(fd1, str, BUFSIZE-1)) > 0){
        str[x] = '\0';
        write(fd2, str, strlen(str));
    }

    printf("\n");
    close(fd1);
    close(fd2);
    return 0;
}
