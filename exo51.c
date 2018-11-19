#include <stdio.h>
#include <string.h>

typedef enum {prete, disponible} etatLivre;

typedef struct {
    int jour;
    int mois;
    int annee;
} date;

typedef struct {
    char auteur[20];
    char titre[100];
    char cote[9];
    int annee;
    char editeur[10];
    etatLivre enPret;
    date DateDePret;
} BibLivres;

void sgets(char *str, int taille) {
    int i;
    char c;
    fflush(stdin);
    for(i=0; i<taille-1; i++) {
        c = getchar();
        if(c == '\n') {
            str[i]='\0';
            return;
        }
        else str[i]=c;
    }
    str[taille-1]='\0';
}

BibLivres newLivre() {
    BibLivres l;
    printf("Auteur : ");
    sgets(l.auteur, 20);
    printf("Titre : ");
    sgets(l.titre, 100);
    printf("Cote : ");
    sgets(l.cote, 9);
    printf("Annee : ");
    fflush(stdin);
    scanf("%d", &l.annee);
    printf("Editeur : ");
    sgets(l.editeur, 10);
    l.enPret = disponible;
    l.DateDePret.jour=0;
    l.DateDePret.mois=0;
    l.DateDePret.annee=0;
    return l;
}

void printLivre(BibLivres l) {
    printf("Auteur : ");
    printf("%s\n", l.auteur);
    printf("Titre : ");
    printf("%s\n", l.titre);
    printf("Cote : ");
    printf("%s\n", l.cote);
    printf("Annee : ");
    printf("%d\n", l.annee);
    printf("Editeur : ");
    printf("%s\n", l.editeur);
    printf("Etat : ");
    switch(l.enPret) {
        case prete : printf("prete\n");
        case disponible : printf("disponible\n");
    }
}


int exo51() {
    printf("Structures, pointeurs et fichiers :\n");
    char car;
    BibLivres l;
    while(1) {
        printf("(char)$ ");
        fflush(stdin);
        car = getchar();
        switch(car) {
            case 'q' : return 0;
            case 'n' : l = newLivre(); printLivre(l); break;
        }
    }
}
