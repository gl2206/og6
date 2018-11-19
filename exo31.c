#include <stdio.h>
#include <string.h>

void strinv(char str[]) {
    int i, l=strlen(str);
    char tmp;
    for(i=0; i<l/2; i++) {
        tmp=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=tmp;
    }
}

void strinvRec(char str[]) {
    static int i;
    if(i==strlen(str)/2) {
        i=0;
        return;
    }
    char tmp;
    tmp=str[i];
    str[i]=str[strlen(str)-i-1];
    str[strlen(str)-i-1]=tmp;
    i++;
    strinvRec(str);
}

int exo31()
{
    printf("Alteration d'une chaine de caracteres :\n");
    char txt[30];
    printf("(char[])$ ");
    fflush(stdin);
    gets(txt);
    printf("Procedure iterative : ");
    strinv(txt);
    printf("%s\n", txt);
    strinv(txt);
    printf("Procedure recursive : ");
    strinvRec(txt);
    printf("%s\n", txt);
    return 0;
}
