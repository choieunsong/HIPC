#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *string_a = "This is a string in";
    char *string_b = "the C language";
    // strlen doens't count null character, so we should plus 1
    char *tmp_string = (char *) calloc(strlen(string_a) + strlen(string_b) + 1, sizeof(char));

    strcat(tmp_string, string_a);
    strcat(tmp_string, string_b);

    printf("%s\n", tmp_string);

    sprintf(tmp_string, "%s%s", string_a, string_b);
    printf("%s\n", tmp_string);

    char *s1 = "This is a string";
    char *s2 = "This is a string";
    char *s3 = "This is a third string";

    printf("cmp s1 s2 %d\n", strcmp(s1, s2)); //0
    printf("cmp s1 s3 %d\n", strcmp(s1, s3)); //-1
    printf("cmp a b %d\n", strcmp("a", "b")); //-1

    // strstr()
    s1 = "this is a string";
    s2 = "is a";
    s3 = "balloon";

    char *r1 = strstr(s1, s2); // return: is a string
    char *r2 = strstr(s1, s3); // return: null

    printf("rs: %s, r2: %s\n", r1, r2);

    return 0;
}
