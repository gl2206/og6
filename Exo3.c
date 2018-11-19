#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Taille d'un entier : %d octets\n", sizeof(int));
    printf("Taille d'un entier court : %d octets\n", sizeof(short));
    printf("Taille d'une chaine de caracteres : %d octets\n", sizeof(char));
    printf("Taille d'un decimal : %d octets\n", sizeof(float));
    printf("Taille d'un decimal long : %d octets", sizeof(double));
    return 0;
}
