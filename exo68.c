#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct element {
    int nombre;
    struct element *suivant;
} element;

typedef element* Pile;

typedef union {
    int key;
    char signe;
} valeur;

typedef struct node {
    valeur val;
    struct node *fg, *fd;
} Node;

Pile newPile() {
    Pile p = NULL;
    return p;
}

void push(Pile *p, int nb) {
	element* e = (element*) malloc(sizeof(element));
	e->nombre = nb;
	e->suivant = *p;
	*p = e;
}

int pop(Pile *p) {
	if (*p == NULL)
		return 0;
	int nb = (*p)->nombre;
	Pile e = *p;
	*p = (*p)->suivant;
	free(e);
	return nb;
}

void printPile(Pile p) {
    if(p == NULL) {
        printf("Pile vide !\n");
        return;
    }
    element *e = p;
    while(e != NULL) {
        printf("%d\n", e->nombre);
        e = e->suivant;
    }
}

Node* construire_feuille(int val) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->val.key = val;
    n->fg = NULL;
    n->fd = NULL;
    return n;
}

Node* construire_noeud(char operateur, Node *arbreGauche, Node *arbreDroit) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->val.signe = operateur;
    n->fg = arbreGauche;
    n->fd = arbreDroit;
    return n;
}

void affiche_noeud(Node *n) {
    if(n->fg == NULL && n->fd == NULL) printf("%d", n->val.key);
    else printf("%c", n->val.signe);
}

void infixe(Node *arbre) {
    if(arbre == NULL) return;
    putchar('(');
    infixe(arbre->fg);
    affiche_noeud(arbre);
    infixe(arbre->fd);
    putchar(')');
}

void prefixe(Node *arbre) {
    if(arbre == NULL) return;
    affiche_noeud(arbre);
    prefixe(arbre->fg);
    prefixe(arbre->fd);
}

void suffixe(Node *arbre) {
    if(arbre == NULL) return;
    suffixe(arbre->fg);
    suffixe(arbre->fd);
    affiche_noeud(arbre);
}

void suffixe_tab(Node *arbre, Node *t, int *i) {
    if(arbre == NULL) return;
    suffixe_tab(arbre->fg, t, i);
    suffixe_tab(arbre->fd, t, i);
    t[(*i)++] = *arbre;
}

Node* construire_arbre(char **str) {
    char cpy[20];
    strcpy(cpy, *str);
    char *tok = strtok(cpy, " ");
    if(isdigit(tok[0])) {
        *str = *str + strlen(tok) + 1;
        return construire_feuille(atoi(tok));
    }
    else {
        *str = *str + 2;
        Node *arbreGauche = construire_arbre(str);
        Node *arbreDroit = construire_arbre(str);
        return construire_noeud(tok[0], arbreGauche, arbreDroit);
    }
}

int eval(Node *arbre) {
    Pile p = newPile();
    Node t[10];
    int lg = 0, i, a, b;
    suffixe_tab(arbre, t, &lg);
    for(i = 0; i < lg; i++) {
        if(t[i].fg == NULL && t[i].fd == NULL)
            push(&p, t[i].val.key);
        else switch(t[i].val.signe) {
            case '+' :
                b = pop(&p);
                a = pop(&p);
                push(&p, a+b);
                break;
            case '-' :
                b = pop(&p);
                a = pop(&p);
                push(&p, a-b);
                break;
            case '*' :
                b = pop(&p);
                a = pop(&p);
                push(&p, a*b);
                break;
            case '/' :
                b = pop(&p);
                a = pop(&p);
                push(&p, a/b);
                break;
            case '%' :
                b = pop(&p);
                a = pop(&p);
                push(&p, a%b);
                break;
            default :
                printf("\nAborting !!! c = %c\n", t[i].val.signe);
                printPile(p);
                abort();
        }
    }
    return pop(&p);
}

int exo68() {
    printf("Expressions arithmetiques :\n");
    Node *n;
    char *str = (char*) malloc(50);
    while(1) {
        printf("(char[50])$ ");
        fflush(stdin);
        gets(str);
        n = construire_arbre(&str);
        infixe(n);
        printf("\nResultat = %d\n", eval(n));
    }
    return 0;
}
