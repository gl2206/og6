#include "TD5.h"

void strstat(char str[]) {
    int i, min=0, maj=0, space=0;
    for(i=0; i<strlen(str); i++) {
        if(islower(str[i])) min++;
        else if(isspace(str[i])) space++;
        else if(isupper(str[i])) maj++;
    }
    printf("Statistiques de la chaine \"%s\" :\n", str);
    printf("Nombre de minuscules : %d\n", min);
    printf("Nombre d'espaces : %d\n", space);
    printf("Nombre de majuscules : %d\n", maj);
}

int exo36()
{
    printf("Nombre de majuscules :\n");
    char txt[10];
    printf("(char[])$ ");
    fflush(stdin);
    gets(txt);
    strstat(txt);
    return 0;
}
