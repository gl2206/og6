#include <stdio.h>
#define PI 3.14159

int main() {
    float s=0;
    int i;
    for(i=1; PI*PI/6-s>=0.001; i++) {
        s+=1./(i*i);
    }
    printf("Somme des 1/n^2 à 10^-3 pres = %.3f", s);
    return 0;
}
