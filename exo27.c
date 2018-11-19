#include <stdio.h>

int iszeroinNumber(int n) {
    if(n==0 || n%10==0) return 1;
    else if(n/10==0 && n%10!=0) return 0;
    else return iszeroinNumber(n/10);
}

int exo27() {
    printf("Chiffres en base 10 :\n");
    int nb;
    printf("(int)$ ");
    scanf("%d", &nb);
    if(iszeroinNumber(nb)) printf("Presence de zero\n");
    else printf("Absence de zero\n");
    return 0;
}
