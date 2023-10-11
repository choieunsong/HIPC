#include <stdio.h>
#include <stdbool.h>

/* Write a C program that asks the user to enter an integer, n, and then prints 
the primes between 2 and n. 
The program should use a function to determine if a given integer is a prime.*/

bool isPrimeNumber(int n){

    int i;
    bool isPrime = true;

    for(i=2; i<n-1; i++){
        if(n%i == 0){
            isPrime = false;
            return isPrime;
        }
    }
    return isPrime;
}

int main(){
    int n=0;

    printf("Enter a integer number: ");
    scanf("%d", &n);
    
    printf("Prime numbers between: ");
    int i;
    for(i = 2; i <= n; i++){
        if(isPrimeNumber(i)){
            printf("%d, ", i);
        }
    }
    printf("\n");

    return 0;
}