#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int *my_array = (int *)malloc(sizeof(int) * 10);

    my_array[0] = 1;
    *(my_array+1)=2;

    int *tmp_ptr = (int *) realloc(my_array, sizeof(int) * 20);

    if(tmp_ptr != NULL) my_array = tmp_ptr;
    else perror("Failed to reallocate memory");

    free(my_array);
    free(tmp_ptr);
    return 0;
}