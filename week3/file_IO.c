#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 10

int main(int argc, char const *argv[])
{
    FILE *fptr1 = fopen("./textfile1.txt", "r");

    if(fptr1 == NULL){
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    char str[BUFSIZE];
    printf("Content of the opened file:\n");

    while(fgets(str, BUFSIZE, fptr1) != NULL){
        fprintf(stdout, "%s", str); // same with printf
    }

    printf("\n");
    fclose(fptr1);

    return 0;
}
