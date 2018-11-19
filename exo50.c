#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vect {
    float *tab;
    int lenght;
} Vect;

FILE* fileOpen() {
    FILE *f;
    char str[20];
    printf("(char[20])$ ");
    fflush(stdin);
    fgets(str, 20, stdin);
    char *name = (char*)malloc(strlen(str));
    memcpy(name, str, strlen(str)-1);
    name[strlen(str)-1]='\0';
    f = fopen(name, "w+b");
    return f;
}

Vect sumVect(Vect a, Vect b) {
    Vect c;
    if(a.lenght != b.lenght) {
        c.tab = NULL;
        c.lenght = 0;
        return c;
    }
    int i;
    c.tab = (float*)malloc(a.lenght*sizeof(float));
    c.lenght = a.lenght;
    for(i=0; i<a.lenght; i++) {
        c.tab[i] = a.tab[i] + b.tab[i];
    }
    return c;
}

void getVect(Vect *v, int n) {
    int i;
    v->lenght = n;
    v->tab=(float*)malloc(n * sizeof(float));
    for(i=0; i<n; i++) {
        printf("(float)[%d]$ ", i+1);
        scanf("%f", &v->tab[i]);
    }
}

void printVect(Vect v) {
    int i;
    printf("(");
    for(i=0; i<v.lenght; i++) printf(" %f ", v.tab[i]);
    printf(")\n");
    printf("Lenght = %d\n", v.lenght);
}

void writeTabVect(FILE *f) {
    int m, n, i;
    printf("(int)[m]$ ");
    scanf("%d", &m);
    printf("(int)[n]$ ");
    scanf("%d", &n);
    Vect *tab = (Vect*)malloc(m * sizeof(Vect));
    for(i = 0; i < m; i++) {
        getVect(&tab[i], n);
    }
    fwrite(&m, sizeof(int), 1, f);
    fwrite(&n, sizeof(int), 1, f);
    fwrite(tab, sizeof(Vect), m, f);
}

int exo50() {
    printf("Fichiers :\n");
    char car;
    FILE *f;
    while(1) {
        printf("(char)$ ");
        fflush(stdin);
        car = getchar();
        switch(car) {
            case 'q' : return 0;
            case 'o' : f = fileOpen(); if(f == NULL) { printf("E: Ouverture du fichier impossible !"); return 1; } break;
            case 'c' : fclose(f); break;
            case 'w' : writeTabVect(f); break;
            default : printf("E: Numero d'exercice non reconnu !\n");
        }
    }
    return 0;
}
