#include <stdio.h>

int main(int argc, char *argv[]){
    printf("Hello World!\n");

    // Unlikely java, you should declare loop iterations 'i' outside of the loop
    int sum=0;
    int i;
    for(int i=0; i<10; i++){
        sum = sum+i;
    }

    printf("The sum is: %d\n", sum);
    

    return 0;
}
