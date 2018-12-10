#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int nombre;
	int priorite;
	struct element *precedent;
	struct element *suivant;
} element;

typedef element* File;

void enfiler(File *f, int nb, int prio) {
	element *e = (element*) malloc(sizeof(element));
	e->nombre = nb;
	e->priorite = prio;
	if (*f == NULL) {
		e->precedent = e;
		e->suivant = e;
		*f = e;
	} else {
		(*f)->precedent->suivant = e;
		e->precedent = (*f)->precedent;
		(*f)->precedent = e;
		e->suivant = *f;
	}
}

int defiler(File *f) {
	int nb;
	File t = *f;
	if (*f == NULL)
		return 0;
	nb = (*f)->nombre;
	(*f)->precedent->suivant = (*f)->suivant;
	(*f)->suivant->precedent = (*f)->precedent;
	*f = (*f)->suivant;
	free(t);
	return nb;
}

int defilerPriorite(File *f) {
	File e = *f;
	int temp = 0;
	do {
		if (e->priorite > temp)
			temp = e->priorite;
		e = e->suivant;
	} while (e != *f);
	while (e->priorite != temp)
		e = e->suivant;
	if (e == *f) temp = defiler(f);
	else temp = defiler(&e);
	return temp;
}

int exo62() {
    printf("File d'attente avec priorite :\n");
    int i;
	File f = NULL;
	for (i = 0; i < 100; i++)
		enfiler(&f, i, i);
	for (i = 0; i < 100; i++)
		printf("%d ", defilerPriorite(&f));
	return 0;
}
