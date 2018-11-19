#include <stdio.h>

int strcomp(char s1[], char s2[], int taillemax) {
    int i;
    for(i=0; i<taillemax; i++) {
        if(s1[i]!=s2[i]) return 0;
        if(s1[i]=='\n') break;
    }
    return 1;
}

int main() {
    int taillemax=10;
    char s1[taillemax+1], s2[taillemax+1];
    printf("Comparateur de chaines :\n");
    while(1) {
        printf("s1: ");
        fgets(s1, taillemax, stdin);
        printf("s2: ");
        fgets(s2, taillemax, stdin);
        if(strcomp(s1, s2, taillemax)) printf("chaines s1 et s2 identiques\n");
        else printf("chaines s1 et s2 differentes\n");
    }
    return 0;
}
