#include <stdio.h>

typedef struct elementPile {
    int nombre;
    struct elementPile *suivant;
} elementPile;

typedef elementPile* Pile;

Pile newPile();
void pushp(Pile *p, int nb);
int popp(Pile *p);
void printPile(Pile p);
void copiePile(Pile s, Pile *copie);

int taillePile(Pile p) {
    elementPile *e = p;
    int cpt = 0;
    while(e != NULL) {
        cpt++;
        e = e->suivant;
    }
    return cpt;
}

elementPile* dernierElementPile(Pile p) {
    elementPile *e = p;
    if(p == NULL) return NULL;
    while(e->suivant != NULL) e = e->suivant;
    return e;
}

Pile pile_circperm(Pile p, int n) {
    int i;
    elementPile *e;
    n %= taillePile(p);
    for(i = 0; i < n; i++) {
        e = dernierElementPile(p);
        e->suivant = p;
        p = p->suivant;
        e->suivant->suivant = NULL;
    }
    return p;
}

int exo63() {
    printf("Permutations circulaires :\n");
    Pile p = newPile(), copie;
    int i;
    for(i = 0; i < 10; i++) {
        pushp(&p, i);
    }
    printf("\nPile p :\n");
    printPile(p);
    for(i = 0; i <= 10; i++) {
        copiePile(p, &copie);
        printf("\nPile permute %d fois :\n", i);
        printPile(pile_circperm(copie, i));
    }
    return 0;
}
