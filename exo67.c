#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char c;
    struct node* fils[26];
} Node;

Node* newDico() {
    int i;
    Node *d = (Node*) malloc(sizeof(Node));
    d->c = '#';
    for(i = 0; i < 26; i++) {
        d->fils[i] = (Node*) calloc(sizeof(Node), 1);
        d->fils[i]->c = 'a' + i;
    }
    return d;
}

void afficher(Node *d) {
    int i;
    if(d == NULL) return;
    putchar(d->c);
    for(i = 0; i < 26; i++) {
        afficher(d->fils[i]);
    }
}

int exo67() {
    printf("Dictionnaires :\n");
    Node *d = newDico();
    afficher(d);
    return 0;
}
