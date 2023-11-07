#include <stdio.h>

void sort(int *arr, int length){
    int i, j;
    int temp;

    for(i=0; i<length; i++){
        for (j=i+1; j<length; j++){
            if(*(arr+j) < *(arr+i)){
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int x[] = {4, 1, 4, 3, 10, 5};
    int i;

    sort(x, 6);

    for(i=0; i<6; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}