#include <stdio.h>
#include <string.h>

void strcnt(char car, char txt[], int *cpt) {
    if(strlen(txt)==0) return;
    int i;
    if(txt[0]==car) (*cpt)++;
    for(i=0; i<strlen(txt)-1; i++) txt[i]=txt[i+1];
    txt[strlen(txt)-1]='\0';
    strcnt(car, txt, cpt);
}

int exo30()
{
    printf("Nombre d'occurences dans une chaine :\n");
    char c, txt[30];
    int cpt=0;
    printf("(char)$ ");
    fflush(stdin);
    c=getchar();
    printf("(char[])$ ");
    fflush(stdin);
    gets(txt);
    strcnt(c, txt, &cpt);
    printf("Nombre d'occurences de %c = %d", c, cpt);
    return 0;
}
