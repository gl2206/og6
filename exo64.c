#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define WINDOWS
HANDLE hConsole;
#endif // defined(_WIN32) || defined(_WIN64)

typedef struct element {
	char caractere;
	struct element *suivant;
} element;

typedef element* Pile;

void sgets(char *s, int l)
{
    int i;
    char c;
    fflush(stdin);
    for(i = 0; i < l-1; i++)
    {
        c = getchar();
        if(c == '\n')
            break;
        s[i] = c;
    }
    s[i] = '\0';
}

Pile nouvellePile() {
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

void localiserErreur(char *s, int i) {
    int j;
#ifdef WINDOWS
    SetConsoleTextAttribute(hConsole, 12);
#endif // WINDOWS
    printf("\nE: Dans expression : %s\n", s);
    printf("E: c=%02d              ", i+1);
    for(j = 0; j < i; j++) {
        putchar(' ');
    }
    printf("^\n");
}

void verifierParentheses(char *s) {
	int i;
	char c;
	Pile p = nouvellePile();
	for (i = 0; i < strlen(s); i++) {
		if (isParentheseOuvrante(s[i]))
			empiler(&p, s[i]);
		else if (isParentheseFermante(s[i])) {
			c = depiler(&p);
			switch (c) {
			case '(':
				if (s[i] != ')') {
                    localiserErreur(s, i);
					printf("E: Erreur de parenthese !\n");
					return;
				}
				break;
			case '{':
				if (s[i] != '}') {
					localiserErreur(s, i);
					printf("E: Erreur d'accolade !\n");
					return;
				}
				break;
			case '[':
				if (s[i] != ']') {
					localiserErreur(s, i);
					printf("E: Erreur de crochet !\n");
					return;
				}
				break;
			case '<':
				if (s[i] != '>') {
                    localiserErreur(s, i);
					printf("E: Erreur de chapeau !\n");
					return;
				}
				break;
			case '\0':
			    localiserErreur(s, i);
				printf("E: %c en trop !\n", s[i]);
				return;
			}
		}
	}
	c = depiler(&p);
	if (c != '\0') {
        localiserErreur(s, i);
		printf("E: %c ouvert mais non ferme !\n", c);
		return;
	}
}

int exo64() {
#ifdef WINDOWS
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // WINDOWS
    printf("Expression correctement parenthesee :\n");
	char s[50];
	printf("\n(char[50])$ ");
	sgets(s, 50);
	verifierParentheses(s);
#ifdef WINDOWS
	SetConsoleTextAttribute(hConsole, 7);
#endif // WINDOWS
	return 0;
}
