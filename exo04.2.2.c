#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a = rand(), b = rand(), temp;
    printf("a = %c et b = %c\n", a, b);
    printf("Debut permutation\n");
    temp = a;
    a = b;
    b = temp;
    printf("Fin permutation\n");
    printf("a = %c et b = %c", a, b);
    return 0;
}
