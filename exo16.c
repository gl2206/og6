#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    printf("ax^2+bx+c=0\n");
    printf("a= ");
    scanf("%d", &a);
    printf("b= ");
    scanf("%d", &b);
    printf("c= ");
    scanf("%d", &c);
    if((b*b-4*a*c)<0)
        printf("Pas de solution reelle\n");
    else if((b*b-4*a*c)==0)
        printf("L'unique solution est : %.3f", (float)-b/(2.*a));
    else
        printf("Les deux solutions sont : %.3f et %.3f", (float)(-b-sqrt(b*b-4*a*c))/(2.*a), (float)(-b+sqrt(b*b-4*a*c))/(2.*a));
    return 0;
}
