#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 10

/**
 * read file and write in another file
*/
// Version1: using filestream onlys
int main(int argc, char const *argv[])
{
    FILE *fptr1 = fopen("./textfile1.txt", "r");

    if(fptr1 == NULL){
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    FILE *fptr2 = fopen("./textfile2.txt", "w");
    char str[BUFSIZE];

    // create and write into a new file
    while(fgets(str, BUFSIZE, fptr1) != NULL){
        fprintf(fptr2, "%s", str);
    }

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
