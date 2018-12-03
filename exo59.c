#include "TD10.h"

void inverserListe(element **liste) {
    element *e = NULL;
    element *t = *liste;
    while(t!=NULL) {
        e = add_first(e, t->nom);
        t = remove_first(t);
    }
    *liste = e;
}

int exo59() {
    int i;
    element *l = NULL;
    char str[10];
    for(i = 0; i < 130; i++) {
        sprintf(str, "%d", i+1);
        l = add_first(l, str);
    }
    afficher(l);
    inverserListe(&l);
    afficher(l);
    return 0;
}
