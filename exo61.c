#include <stdio.h>
#include <stdlib.h>

typedef struct elementPile {
    int nombre;
    struct elementPile *suivant;
} elementPile;

typedef elementPile* Pile;

typedef struct elementFile {
    int nombre;
    struct elementFile *suivant;
    struct elementFile *precedent;
} elementFile;

typedef elementFile* File;

Pile newPile() {
    Pile p = NULL;
    return p;
}

File newFile() {
    File f = NULL;
    return f;
}

void pushp(Pile *p, int nb) {
	elementPile* e = (elementPile*) malloc(sizeof(elementPile));
	e->nombre = nb;
	e->suivant = *p;
	*p = e;
}

int popp(Pile *p) {
	if (*p == NULL)
		return 0;
	int nb = (*p)->nombre;
	Pile e = *p;
	*p = (*p)->suivant;
	free(e);
	return nb;
}

void pushf(File *f, int nb) {
	elementFile* e = (elementFile*) malloc(sizeof(elementFile));
	e->nombre = nb;
	if(*f == NULL) {
        e->suivant = e;
        e->precedent = e;
        *f = e;
	} else {
        e->suivant = *f;
        e->precedent = (*f)->precedent;
        (*f)->precedent->suivant = e;
        (*f)->precedent = e;
	}
}

int popf(File *f) {
	if (*f == NULL)
		return 0;
	int nb = (*f)->nombre;
	(*f)->suivant->precedent = (*f)->precedent;
	(*f)->precedent->suivant = (*f)->suivant;
	File e = *f;
	*f = (*f)->suivant;
	free(e);
	return nb;
}

void printPile(Pile p) {
    elementPile *e = p;
    while(e != NULL) {
        printf("%d\n", e->nombre);
        e = e->suivant;
    }
}

void printFile(File f) {
    elementFile *e = f;
    if(f == NULL) return;
    do {
        printf("%d\n", e->nombre);
        e = e->suivant;
    } while(e != f);
}

void copiePile(Pile s, Pile *copie) {
    if(s == NULL) *copie = NULL;
    else {
        *copie = (elementPile*) malloc(sizeof(elementPile));
        (*copie)->nombre = s->nombre;
        (*copie)->suivant = NULL;
        elementPile *precedent = *copie;
        s = s->suivant;
        while(s != NULL) {
            elementPile *e = (elementPile*) malloc(sizeof(elementPile));
            e->nombre = s->nombre;
            e->suivant = NULL;
            precedent->suivant = e;
            precedent = e;
            s = s->suivant;
        }
    }
}

void copieFile(File s, File *copie) {
    if(s == NULL) *copie = NULL;
    else {
        *copie = (elementFile*) malloc(sizeof(elementFile));
        (*copie)->nombre = s->nombre;
        (*copie)->suivant = *copie;
        (*copie)->precedent = *copie;
        elementFile *precedent = *copie;
        elementFile *f = s->suivant;
        while(f != s) {
            elementFile *e = (elementFile*) malloc(sizeof(elementFile));
            e->nombre = f->nombre;
            e->precedent = precedent;
            e->suivant = precedent->suivant;
            precedent->suivant->precedent = e;
            precedent->suivant = e;
            precedent = e;
            f = f->suivant;
        }
    }
}

int exo61() {
    printf("Copie d'une pile/file :\n");
    Pile p = newPile(), copiep;
    File f = newFile(), copief;
    int i;

    for(i = 0; i < 50; i++) {
        pushp(&p, i);
    }
    printf("\nPile p :\n");
    printPile(p);
    copiePile(p, &copiep);
    printf("\nPile copie :\n");
    printPile(copiep);

    for(i = 0; i < 50; i++) {
        pushf(&f, i);
    }
    printf("\nFile f :\n");
    printFile(f);
    copieFile(f, &copief);
    printf("\nFile copie :\n");
    printFile(copief);
    return 0;
}
