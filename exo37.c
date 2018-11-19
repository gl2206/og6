#include "TD5.h"

void getMat(Matrice *m);
void printMat(Matrice m);

void calcMat(Matrice m1, Matrice m2, char op, Matrice *res)
{
    int i, j, k;
    switch(op)
    {
    case '+' :
        for(i=0; i<m1.size; i++) for(j=0; j<m1.size; j++) res->mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
        break;
    case '-' :
        for(i=0; i<m1.size; i++) for(j=0; j<m1.size; j++) res->mat[i][j]=m1.mat[i][j]-m2.mat[i][j];
        break;
    case '*' :
        for(i=0; i<m1.size; i++) for(j=0; j<m1.size; j++)
            {
                res->mat[i][j]=0;
                for(k=0; k<m1.size; k++) res->mat[i][j]+=m1.mat[i][k]*m2.mat[k][j];
            }
        break;
    default :
        printf("E: Operateur incorrect !\n");
    }
}

int exo37()
{
    printf("Addition, soustraction et multiplication de matrices :\n");
    Matrice m1= {.size=0};
    char c;
    printf("(int)$ ");
    scanf("%d", &(m1.size));
    Matrice m2= {.size=m1.size};
    Matrice m3= {.size=m1.size};
    printf("Matrice 1 :\n");
    getMat(&m1);
    printf("Matrice 2 :\n");
    getMat(&m2);
    printf("(char)$ ");
    fflush(stdin);
    scanf("%c", &c);
    calcMat(m1, m2, c, &m3);
    printf("Matrice resultat :\n");
    printMat(m3);
    return 0;
}
