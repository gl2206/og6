#include <stdio.h>

int main() {
    int b, h;
    float a;
    printf("Aire d'un triangle : A = 1/2 * B * H\n");
    printf("B = ");
    scanf("%d", &b);
    printf("H = ");
    scanf("%d", &h);
    a = 0.5*b*h;
    printf("A = %f", a);
    return 0;
}
