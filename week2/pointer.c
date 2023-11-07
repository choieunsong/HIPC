#include <stdio.h>

int main(int argc, char *argv[]){
    int *a_pointer;
    int a_value = 5;
    int x[] = {10,1,2,5,-3};

    a_pointer = &a_value;

    printf("The value of a_value is %d\n", a_value);
    printf("The value of the pointer is %p\n",a_pointer);
    printf("The value pointed to by the pointer is %d\n", *a_pointer);

    *a_pointer = 10;

    printf("The value of a_value %d\n", a_value);
    printf("The start address of the array x is %p\n", &x);
    printf("The address of the first element is %p\n", &x[0]);

    for(int i=0; i<5; i++){
        printf("Value stored in address %p is %d\n", (x+i), x[i]);
    }
    printf("Size of each integer is %lu bytes\n", sizeof(int));
    return 0;
}


