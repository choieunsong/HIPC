#include <stdio.h>
#include <stdlib.h>

struct Book
{
    char *title;
    double price;
};

int main(int argc, char const *argv[])
{
    struct Book b = {"Charlotte's Web", 10.88};
    printf("struct b - %s, %.2f\n", b.title, b.price);
    
    b.price = 10.99;
    printf("struct b - %s, %.2f\n", b.title, b.price);

    return 0;
}
