#include <stdio.h>
#include <stdlib.h>
void foo(double argument){
    // static allocation: memory is made available on the stack. fixed size
    int my_array[10];
    double a_number = argument; //This is also static allocation
}

int main(int argc, char const *argv[])
{
    // dynamically allocated on heap
    int *dynamic_array = (int *)malloc(10 * sizeof(int));
    free(dynamic_array);

    foo(42.0); //Stack frame is pushed on function entry and discarded after function exit
    
    return 0;
}
