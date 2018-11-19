#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxi(a,b) a>b?a:b

int maxTab(int tab[], int l)
{
    int i, nbmax=tab[0];
    for(i=1; i<l; i++) nbmax=maxi(nbmax,tab[i]);
    return nbmax;
}

int getTab(int tab[], int *i) {
    char txt[10];
    int j;
    while((*i)<10)
    {
        printf("(char[])%d$ ", (*i)+1);
        fflush(stdin);
        gets(txt);
        if(txt[0]!='s')
        {
            for(j=0; j<strlen(txt); j++)
            {
                if(isdigit(txt[j])==0)
                {
                    printf("E: Erreur de format !\n");
                    return 1;
                }
            }
            tab[*i]=atoi(txt);
            (*i)++;
        }
        else return 0;
    }
    printf("E: Depassement de capacite !\n");
    return 1;

}

int exo26()
{
    printf("Fonctions generiques :\n");
    int tab[10];
    int l=0;
    if(getTab(tab, &l)) return 1;
    printf("Max = %d\n", maxTab(tab, l));
    return 0;
}
