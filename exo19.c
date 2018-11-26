#include <stdio.h>
#include <math.h>

double f(float x) {
    return exp(-x)/(x*x*x);
}

int main() {
    float i;
    float s=0;
    for(i=0.1; i<10; i+=0.01) {
        s+=f(i)*0.01;
    }
    printf("Integrale de f(x)=exp(-x)/x^3 a 10^-2 pres = %f\n", s);
    return 0;
}
