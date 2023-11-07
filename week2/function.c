#include <stdio.h>

int factorial(int m){
    int i, prod = 1;

    for(i = 2; i <= m; i++){
        prod = prod * i;
    }

    return prod;
}

int main(){
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    printf("The factorial of %d is %d\n", n, factorial(n));
    return 0;
}