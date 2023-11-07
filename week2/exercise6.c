#include <stdio.h>
#include <stdlib.h>

/**
 * Compiler debugging
 * gcc -Wall -o test test.c
 * : 실행은 되지만 warning은 띄움
 * 
 * gcc -Wall -Werror -o test test.c
 * : 실행되 안되고 warning도 띄움
 * 
 * gcc -g -o helloworld helloworld.c
 * : 디버깅 info를 준다
 * : gdb ./helloworld
 * : 맥의 경우 lldb ./helloword
*/

int main(int argc, char const *argv[])
{
    int *my_array = (int *)malloc(5 * sizeof(int));

    int i;

    for (int i = 0; i < 1000000; i++){
        my_array[i] = i;
    }

    free(my_array);
    return 0;
}
