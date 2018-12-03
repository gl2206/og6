#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct bagage {
    char nom[50];
    char numero_vol[7];
    float poids;
} bagage;

int verifierNumero_vol(char numero_vol[]) {
    int i;
    for(i = 0; i < 6; i++) {
        if((i < 2) && !isalpha(numero_vol[i])) {
            printf("E: Numero de vol incorrect !\n");
            return 0;
        }
        else if((i >= 2) && !isdigit(numero_vol[i])) {
            printf("E: Numero de vol incorrect !\n");
            return 0;
        }
    }
    return 1;
}

bagage enregistrerBagage() {
    bagage b;
    printf("Enregistrement d'un bagage :\n");
    printf("Nom du proprietaire : ");
    fflush(stdin);
    gets(b.nom);
    do {
        printf("Numero du vol : ");
        fflush(stdin);
        fgets(b.numero_vol, 7, stdin);
    } while(!verifierNumero_vol(b.numero_vol));
    printf("Poids : ");
    scanf("%f", &b.poids);
    return b;
}

int trouverBagage(bagage tab[], int taille_tab) {
    char str[50];
    char numero[7];
    int i;
    printf("Recherche d'un bagage :\n");
    printf("Nom du proprietaire : ");
    fflush(stdin);
    gets(str);
    do {
        printf("Numero du vol : ");
        fflush(stdin);
        fgets(numero, 7, stdin);
    } while(!verifierNumero_vol(numero));
    for(i = 0; i < taille_tab; i++) if(!strcmp(tab[i].nom, str) && !strcmp(tab[i].numero_vol, numero)) return 1;
    return 0;
}

int main() {
    bagage b[10];
    int index = 0;
    char car;
    printf("Gestion des bagages : \n");
    printf("e : enregistrer un bagage, t : trouver un bagage, q : quitter le programme\n\n");
    while(1) {
        printf("# ");
        fflush(stdin);
        car = getchar();
        switch(car) {
            case 'q' : return 0;
            case 't' : if(trouverBagage(b, 10)) printf("Bagage trouve !\n"); else printf("Bagage non trouve !\n"); break;
            case 'e' : b[index] = enregistrerBagage(); index++; break;
            default : printf("E: Commande non reconnue !\n");
        }
    }
}
