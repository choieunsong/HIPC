#include <stdio.h>
#include "prime.h"

int main(int argc, char const *argv[])
{
    int n;

    printf("Enter a integer number: ");
    scanf("%d", &n);

    printf("The sum of all prime numbers from 2 to %d: %d\n", n, prime(n));

    return 0;
}
