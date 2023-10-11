#include <stdbool.h>

bool isPrime(int n) {
    int i;
    bool flag = true;

    for(i=2; i<n-1; i++){
        if(n%i == 0){
            flag = false;
            return flag;
        }
    }
    return flag;
}

int prime(int n){
    int sum = 0;
    
    int i;
    for(i = 2; i <= n; i++){
        if(isPrime(i)){
                sum += i;
            }
    }
    
    return sum;
}