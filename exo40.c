#include "TD5.h"

void getMat(Matrice *m);
void printMat(Matrice m);

int maxinlineMat(Matrice m, int l) {
    int i, max=m.mat[l][0];
    for(i=1; i<m.size; i++) if(max<m.mat[l][i]) max=m.mat[l][i];
    return max;
}

int minincolMat(Matrice m, int c) {
    int i, min=m.mat[0][c];
    for(i=1; i<m.size; i++) if(min>m.mat[i][c]) min=m.mat[i][c];
    return min;
}

void colpointsMat(Matrice m) {
    int i, j;
    printMat(m);
    for(i=0; i<m.size; i++) for(j=0; j<m.size; j++) if(maxinlineMat(m, i)==m.mat[i][j] && minincolMat(m, j)==m.mat[i][j]) printf("L'element (%d,%d) est un point-col.\n", i+1, j+1);
}

int exo40()
{
    printf("Points-cols d'une matrice :\n");
    Matrice m= {.size=0};
    printf("(int)$ ");
    scanf("%d", &(m.size));
    getMat(&m);
    colpointsMat(m);
    return 0;
}
