#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *array_of_ints = (int *) malloc(sizeof(int) * 10);
   int i;

   // Here the issue is that the array runs from 0 to 9, but the loop runs to 10 inclusive.
   // for (i = 0; i <= 10; i++) {
   for (i = 0; i < 10; i++) {
      array_of_ints[i] = i;
   }
   free(array_of_ints);
   return 0;
}
