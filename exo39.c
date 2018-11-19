#include "TD5.h"

void printTab(int t[], int lg);

int getsortTab(int tab[], int *i) {
    char txt[10];
    int j, k;
    while((*i)<10)
    {
        printf("(char[])%d$ ", (*i)+1);
        fflush(stdin);
        gets(txt);
        if(txt[0]!='e')
        {
            for(j=0; j<strlen(txt); j++)
            {
                if(isdigit(txt[j])==0)
                {
                    printf("E: Erreur de format !\n");
                    return 1;
                }
            }
            for(j=0; (atoi(txt)>tab[j]) && (j<*i); j++);
            for(k=*i;k>j; k--) {
                tab[k]=tab[k-1];
            }
            tab[j]=atoi(txt);
            (*i)++;
        }
        else return 0;
    }
    printf("E: Depassement de capacite !\n");
    return 1;
}

int exo39() {
    printf("Insertion ordonnee :\n");
    int tab[10];
    int l=0;
    if(getsortTab(tab, &l)) return 1;
    printTab(tab, l);
    return 0;
}
