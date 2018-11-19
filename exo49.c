#include <stdio.h>

struct element {
    int value;
    struct element* next_element;
};

typedef struct element* liste;

void ajouterElement(liste *l, int v) {
    struct element e = {v, NULL};
    if(*l == NULL) {
        *l=&e;
        return;
    }
    struct element* e1 = *l;
    struct element* e2 = *l;
    while(e2!=NULL) {
        e1=e2;
        e2=e1->next_element;
    }
    e1->next_element = &e;
}

void afficherListe(liste l) {
    struct element* e = l;
    while(e != NULL) {
        printf("%d ", e->value);
        e=e->next_element;
    }
}

int exo49() {
    printf("Listes lineaires chainees :\n");
    liste l = NULL;
    ajouterElement(&l, 1);
    ajouterElement(&l, 2);
    ajouterElement(&l, 3);
    afficherListe(l);
    return 0;
}
