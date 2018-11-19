#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int lireDigits(char str[], int *i) {
    int v;
    while(isdigit(str[*i])) {
        v*=10;
        v+=atoi(str[i]);
    }
    return v;
}

void calc(int *op1, int op2, char op) {
    switch(op) {
        case '+' : *op1+=op2;
        case '-' : *op1-=op2;
    }
}

void streval(char str[], int *resultat) {
    int i=0, operande;
    char operation;
    *resultat=lireDigits(str, &i)
    while(i<strlen(str)) {
        operation=str[i];
        operande=lireDigits(txt, &i);
        calc(res, operande, operation);
    }
}

int exo32()
{
    printf("Evaluation d'une somme simple :\n");
    char txt[30];
    printf("(char[])$ ");
    fflush(stdin);
    gets(txt);
    printf("%s = ", txt);
    streval(txt, &res);
    printf("%d\n", res);
    return 0;
}
