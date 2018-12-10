#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int nombre;
	struct element *suivant;
} element;

typedef element* Liste;

Liste* newTable() {
	int i;
	Liste *t = (Liste*) malloc(9*sizeof(Liste));
	for(i = 0; i < 10; i++) {
		t[i] = NULL;
	}
	return t;
}

void afficherTable(Liste *t) {
	int i;
	element *e;
	for(i = 0; i < 10; i++) {
		e = t[i];
		printf("\nCase %d : ", i);
		while(e != NULL) {
			printf("%d ", e->nombre);
			e = e->suivant;
		}
	}
	printf("\n");
}

void insererListe(Liste *l, int nb) {
	element *e = (element*) malloc(sizeof(element));
	element *t = *l;
	e->nombre = nb;
	e->suivant = NULL;
	if(*l == NULL) {
		*l = e;
	} else {
		while(t->suivant != NULL) t = t->suivant;
		t->suivant = e;
	}
}

void insererTable(Liste t[9], int nb) {
	insererListe(&t[nb%9], nb);
}

int exo65 () {
    printf("Premiere table de hachage :\n");
	Liste *t = newTable();
	insererTable(t, 5);
	insererTable(t, 28);
	insererTable(t, 19);
	insererTable(t, 15);
	insererTable(t, 20);
	insererTable(t, 33);
	insererTable(t, 12);
	insererTable(t, 17);
	insererTable(t, 10);
	afficherTable(t);
	return 0;
}
