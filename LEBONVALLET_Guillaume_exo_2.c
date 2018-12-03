#include <stdio.h>

#define LIM_SUITE 3.359885666

int fibonacci(int k) {
    if(k==0) return 0;
    if(k==1) return 1;
    return fibonacci(k-1)+fibonacci(k-2);
}

double sommeSuiteInverseFibonacci(int n) {
    double resultat = 0;
    int i;
    for(i = 0; i < n; i++) {
        resultat+=1.0/fibonacci(i+1);
    }
    return resultat;
}

int nbTermesMin(float precision) {
    int n;
    double somme;
    for(n = 1; LIM_SUITE-somme > precision; n++) {
        somme+=1.0/fibonacci(n);
    }
    return n;
}

int main() {
    printf("%.9f\n", sommeSuiteInverseFibonacci(43));
    printf("%d", nbTermesMin(0.000000007));
    return 0;
}
