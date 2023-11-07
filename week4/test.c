#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 4;
    
    printf("int size: %ld\n", sizeof(int));
    printf("int pointer size: %ld\n", sizeof(int*));
    printf("float size: %ld\n", sizeof(float));
    printf("long size: %ld\n", sizeof(long));
    return 0;
}
