#include <stdio.h>

int main() {
    int n=0;
    float nb;
    float m=0;
    float v=0;
    printf("Calcul de la moyenne et de la variance d'une serie :\n");
    while(1) {
        printf("$ ");
        scanf("%f", &nb);
        m+=nb;
        v+=nb*nb;
        n++;
        printf("Moyenne = %f\n", m/n);
        printf("Variance = %f\n", v/n-(m/n)*(m/n));
    }
    return 0;
}
