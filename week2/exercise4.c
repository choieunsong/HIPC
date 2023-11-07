#include <stdio.h>
#include <stdlib.h>

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
    int length;

    printf("Enter the size of array you want to sort: ");
    scanf("%d", &length);

    int *x = (int *)malloc(sizeof(int) * length);

    int i;
    printf("Enter the elements: ");
    for(i=0; i<length; i++){
        scanf("%d", (x+i));
    }
    sort(x, length);

    for(i=0; i<length; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}