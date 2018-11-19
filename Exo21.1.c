#include <stdio.h>

int main() {
    int taillemax=10;
    while(1) {
        char str[taillemax];
        printf("$ ");
        gets(str);
        str[taillemax]='\0';
        puts(str);
    }
    return 0;
}
