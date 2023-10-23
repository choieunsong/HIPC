#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>  // for the open() function
#include <unistd.h> // for read(), write() and close() functions

#define BUFSIZE 10

/**
 * <standard I/O streams>
 * stdin: 0
 * stdout: 1
 * stderr: 2
 * **/

int main(int argc, char const *argv[])
{
    int fd1 = open("./textfile1.txt", O_RDONLY); // opens the file in read only mode and returns a file descriptor for the file
    int x;

    if (fd1 < 0){
        // writes the error message to stderr
        write(2, "Error opening file\n", sizeof("Error opening file\n"));
        exit(1);
    }

    char str[BUFSIZE];

    printf("Content of the opened file: \n");

    // read() reads up to BUFSIZE-1 bytes from fd1 and stores in str. x is nbyte str read
    while((x = read(fd1, str, BUFSIZE-1)) > 0){
        // the number of bytes actually read is returned
        str[x] = '\0';
        // "1" is the file descriptor for stdout, hence this is equivalent to printf("%s", str);
        write(1, str, strlen(str));
    }

    printf("\n");
    close(fd1);
    return 0;
}
