#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a = rand(), b = rand(), temp;
    printf("a = %f et b = %f\n", a, b);
    printf("Debut permutation\n");
    temp = a;
    a = b;
    b = temp;
    printf("Fin permutation\n");
    printf("a = %f et b = %f", a, b);
    return 0;
}
