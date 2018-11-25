#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
	char nom[30];
	struct element* suivant;
} element;

void afficher(element *liste) {
	element *e = liste;
	do {
		printf("element: nom=%s\n", e->nom);
		e = e->suivant;
	} while(e != liste);
}

element* first_element(element *liste) {
	element *e = (element*) malloc(sizeof(element));
	printf("%x\n",e);
	strcpy(e->nom, liste->nom);
	e->suivant = e;
	return e;
}

int taille(element *liste) {
	element *e = liste;
	//printf("%s %x %x\n",liste->nom, liste->suivant,liste);
	int taille = 0;
	if(e == NULL) return 0;
	do {
		taille++;
		e = e->suivant;
		//printf("%d %x %x\n",taille, liste, e);
	} while(e != liste);
	return taille;
}

element* remove_first(element *liste) {
	element *dernier = liste;
	if(dernier->suivant == liste) {
		free(liste);
		return NULL;
		}
	do {
		dernier = dernier->suivant;
	} while(dernier->suivant != liste);
	dernier->suivant = liste->suivant;
	free(liste);
	return dernier->suivant;
}

element *dernier_element(element *liste) {
	element *dernier = liste;
	do {
		dernier = dernier->suivant;
	} while(dernier->suivant != liste);
	return dernier;
}

element *add_first(element *liste, char nom[]) {
	element *e = (element*) malloc(sizeof(element));
	element *fin;
	strcpy(e->nom, nom);
	e->suivant = liste;
	if(liste == NULL) {
		e->suivant = e;
		}
		else {
		fin=dernier_element(liste);
		fin->suivant=e;
		}
	return e;
}

void liberer(element *liste) {
	element *e = liste;
	if(e == NULL) return;
	do {
		e = e->suivant;
		free(liste);
		liste = e;
	} while(e->suivant != liste);
	free(e);
}

element *acceder(element *liste, char nom[]) {
	element *e = liste;
	if(e == NULL) return NULL;
	do {
		if(!strcmp(e->nom, nom)) return e;
		e = e->suivant;
	} while(e != liste);
	return NULL;
}

element *supprimer(element *liste, char nom[]) {
	element *e = liste;
	element *precedent = liste;
	if(e == NULL) return NULL;
	do {
		if(!strcmp(e->nom, nom)) {
			if(e == liste) { 
				do {
					precedent = precedent->suivant;
				} while(precedent->suivant != liste);
				precedent->suivant = e->suivant;
				free(e);
				return precedent->suivant;
			}
			else {
				precedent->suivant = e->suivant;
				free(e);
				return liste;
			}
		}
		precedent = e;
		e = e->suivant;
	} while(e != liste);
	return NULL;
}

void remove_last(element *liste) {
	element *e = liste;
	element *precedent = liste;
	if(e == NULL) return;
	do {
		precedent = e;
		e = e->suivant;
	} while(e->suivant != liste);
	precedent->suivant = liste;
	free(e);
}

int main() {
	int i;
	char str[20];
	element debut;
	strcpy(debut.nom,"toto");
	debut.suivant=&debut;
	printf("%d\n",taille(&debut));
	printf("tata\n");
	element* copie=first_element(&debut);
	printf("ds main, %s %x %x\n",copie->nom, copie->suivant, copie);
	printf("%d %d\n",taille(&debut),taille(copie));
	afficher(copie);
	printf("%x\n",remove_first(copie));
	copie=add_first(copie,"tyty");
	copie=add_first(copie,"titi");
	for(i=0;i<20;i++) {
		sprintf(str, "toto#%02d", i+1);
		copie = add_first(copie, str);
	}
	afficher(copie);
	printf("%d\n",taille(copie));
	copie=remove_first(copie);
	afficher(copie);
	
	return 0;
}


