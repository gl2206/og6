#include <stdio.h>
#define PI 3.1416

int main() {
    int r, h;
    float a;
    printf("Aire d'un cone : A = 1/3 * B * H, B = PI * R˛\n");
    printf("PI = %.4f\n", PI);
    printf("R = ");
    scanf("%d", &r);
    printf("H = ");
    scanf("%d", &h);
    a = 1.0/3.0*PI*r*r*h;
    printf("A = %.2f", a);
    return 0;
}
