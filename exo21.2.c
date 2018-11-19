#include <stdio.h>

int main() {
    int taillemax=10;
    int i, j;
    while(1) {
        char str[taillemax+2];
        printf("$ ");
        for(i=0; i<taillemax; i++) {
            str[i]=getchar();
            if(str[i]=='\n') break;
        }
        str[10]='\n';
        str[11]='\0';
        for(j=0; j<=i; j++) putchar(str[j]);
    }
    return 0;
}
