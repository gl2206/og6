#include <stdio.h>
#include <stdlib.h>

enum Etat {
	libre, occupe
};

typedef struct {
	int nombre;
	enum Etat etat;
} element;

element* newDoubleTable() {
	int i;
	element *t = (element*) malloc(13 * sizeof(element));
	for (i = 0; i < 13; i++)
		t[i].etat = libre;
	return t;
}

void afficherDoubleTable(element t[]) {
	int i;
	for (i = 0; i < 13; i++) {
		printf("Case %02d (", i);
		if (t[i].etat == occupe) printf("occupe) : %02d\n", t[i].nombre);
        else printf("libre)  : --\n");
	}
}

void insererDoubleTable(element t[], int nb) {
	int i, index;
	for (i = 0; i <= 10; i++) {
		index = (nb % 13 + i * (1 + nb % 12)) % 13;
		if (t[index].etat == libre) {
			t[index].nombre = nb;
			t[index].etat = occupe;
			return;
		}
	}
	exit(1);
}

int exo66() {
    printf("Double hachage :\n\n");
	element *t = newDoubleTable();
	insererDoubleTable(t, 5);
	insererDoubleTable(t, 28);
	insererDoubleTable(t, 19);
	insererDoubleTable(t, 15);
	insererDoubleTable(t, 20);
	insererDoubleTable(t, 33);
	insererDoubleTable(t, 12);
	insererDoubleTable(t, 17);
	insererDoubleTable(t, 10);
	afficherDoubleTable(t);
	return 0;
}
