#include "TD5.h"

void getMat(Matrice *m);
void printMat(Matrice m);

void transposeMat(Matrice *m) {
    int i, j, tmp;
    for(i=0; i<m->size; i++) for(j=0; j<i; j++) {
        tmp=m->mat[i][j];
        m->mat[i][j]=m->mat[j][i];
        m->mat[j][i]=tmp;
    }
}

void multMat(Matrice *m) {
    int l, i, j;
    printf("(int)$ ");
    scanf("%d", &l);
    for(i=0; i<m->size; i++) for(j=0; j<m->size; j++) m->mat[i][j]*=l;
}

int exo38()
{
    printf("Transposee d'une matrice :\n");
    Matrice m= {.size=0};
    char c;
    printf("(int)$ ");
    scanf("%d", &(m.size));
    getMat(&m);
    printf("(char)$ ");
    fflush(stdin);
    scanf("%c", &c);
    switch(c) {
        case 't' : transposeMat(&m); break;
        case 'm' : multMat(&m); break;
        default : printf("E: Commande incorrecte !\n"); return 1;
    }
    printf("Matrice resultat :\n");
    printMat(m);
    return 0;
}
