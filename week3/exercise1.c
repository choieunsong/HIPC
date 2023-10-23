#include <stdio.h>
#include <string.h>

// minus 1 of null character
int count_words(char *str){
    return strlen(str) - 1;
}

int main(int argc, char const *argv[])
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    printf("Number of words in the entered string is %d\n", count_words(str));

    return 0;
}
