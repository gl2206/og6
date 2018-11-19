#include <stdio.h>
#include <stdlib.h>

typedef struct vect {
    float *tab;
    int lenght;
} Vect;

void getVect(Vect *v) {
    int i;
    printf("(int)$ ");
    scanf("%d", &v->lenght);
    v->tab=(float*)malloc(v->lenght*sizeof(float));
    for(i=0; i<v->lenght; i++) {
        printf("(float)[%d]$ ", i+1);
        scanf("%f", &v->tab[i]);
    }
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

Vect substVect(Vect a, Vect b) {
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
        c.tab[i] = a.tab[i] - b.tab[i];
    }
    return c;
}

float scalVect(Vect a, Vect b) {
    float scal=0;
    if(a.lenght != b.lenght) {
        scal=-1;
        return scal;
    }
    int i;
    for(i=0; i<a.lenght; i++) {
        scal+=a.tab[i]*b.tab[i];
    }
    return scal;
}

void printVect(Vect v) {
    int i;
    printf("(");
    for(i=0; i<v.lenght; i++) printf(" %f ", v.tab[i]);
    printf(")\n");
    printf("Lenght = %d\n", v.lenght);
}

int exo46() {
    printf("Operations sur les tableaux :\n");
    Vect a = {.lenght = 0}, b = {.lenght = 0}, c = {.lenght = 0};
    char car;
    while(1) {
        printf("(char)$ ");
        fflush(stdin);
        car = getchar();
        switch(car) {
            case 'q' : return 0;
            case 'p' : printf("a = "); printVect(a); printf("b = "); printVect(b); printf("c = "); printVect(c); break;
            case 'a' : getVect(&a); printf("a = "); printVect(a); break;
            case 'b' : getVect(&b); printf("b = "); printVect(b); break;
            case 'c' : getVect(&c); printf("c = "); printVect(c); break;
            case '+' : c = sumVect(a, b); printf("c = "); printVect(c); break;
            case '-' : c = substVect(a, b); printf("c = "); printVect(c); break;
            case 's' : printf("a.b = %f\n", scalVect(a, b)); break;
            default : printf("E: Commande non reconnue !\n");
        }
    }
}
