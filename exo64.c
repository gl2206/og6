#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
	char caractere;
	struct element *suivant;
} element;

typedef element* Pile;

Pile newPile() {
	Pile p = NULL;
	return p;
}

int isParentheseOuvrante(char c) {
	if (c == '(' || c == '{' || c == '[' || c == '<')
		return 1;
	else
		return 0;
}

int isParentheseFermante(char c) {
	if (c == ')' || c == '}' || c == ']' || c == '>')
		return 1;
	else
		return 0;
}

void empiler(Pile *p, char c) {
	element* e = (element*) malloc(sizeof(element));
	e->caractere = c;
	e->suivant = *p;
	*p = e;
}

char depiler(Pile *p) {
	if (*p == NULL)
		return '\0';
	char c = (*p)->caractere;
	Pile e = *p;
	*p = (*p)->suivant;
	free(e);
	return c;
}

void verifierParentheses(char *s) {
	int i;
	char c;
	Pile p = newPile();
	for (i = 0; i < strlen(s); i++) {
		if (isParentheseOuvrante(s[i]))
			empiler(&p, s[i]);
		else if (isParentheseFermante(s[i])) {
			c = depiler(&p);
			switch (c) {
			case '(':
				if (s[i] != ')') {
					printf("E: Erreur de parenthese !\n");
					return;
				}
				break;
			case '{':
				if (s[i] != '}') {
					printf("E: Erreur d'accolade !\n");
					return;
				}
				break;
			case '[':
				if (s[i] != ']') {
					printf("E: Erreur de crochet !\n");
					return;
				}
				break;
			case '<':
				if (s[i] != '>') {
					printf("E: Erreur de chapeau !\n");
					return;
				}
				break;
			case '\0':
				printf("E: %c en trop !\n", s[i]);
				return;
			}
		}
	}
	c = depiler(&p);
	if (c != '\0') {
		printf("%c ouvert mais non ferme !\n", c);
		return;
	}
}

int exo64() {
	char s[] = "sqrt(x^2+y^2";
	verifierParentheses(s);
	return 0;
}
