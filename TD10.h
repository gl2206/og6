#ifndef TD10_H_INCLUDED
#define TD10_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct element {
	char nom[30];
	struct element* suivant;
} element;

void afficher(element *liste);
element* first_element(element *liste);
int taille(element *liste);
element* remove_first(element *liste);
element *dernier_element(element *liste);
element *add_first(element *liste, char nom[]);
void liberer(element *liste);
element *acceder(element *liste, char nom[]);
element *supprimer(element *liste, char nom[]);
void remove_last(element *liste);

#endif // TD10_H_INCLUDED
