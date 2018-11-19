#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <curses.h>

typedef struct etudiant {
    char nom[30];
    float note_median;
    float note_final;
    float note_moyenne;
} Etudiant;

typedef struct liste_etudiant {
    Etudiant *liste;
    int effectif;
} Liste_Etudiants;

Liste_Etudiants getListe_Etudiants() {
    Liste_Etudiants l;
    int i;
    printf("(int)$ ");
    scanf("%d", &l.effectif);
    l.liste = (Etudiant*)malloc(l.effectif*sizeof(Etudiant));
    for(i=0; i<l.effectif; i++) {
        printf("(char[])[%d]$ ", i+1);
        fflush(stdin);
        fgets(l.liste[i].nom, 29, stdin);
        fflush(stdin);
        printf("(float)[%d]$ ", i+1);
        scanf("%f", &l.liste[i].note_median);
        printf("(float)[%d]$ ", i+1);
        scanf("%f", &l.liste[i].note_final);
        l.liste[i].note_moyenne = 0.4 * l.liste[i].note_median + 0.6 * l.liste[i].note_final;
    }
    return l;
}

void printListe_Etudiants(Liste_Etudiants l) {
    int i;//, pos;
    for(i=0; i<l.effectif; i++) {
        //pos=ftell(stdout);
        printf("%s\t", l.liste[i].nom);
        //fseek(stdout, pos+30, SEEK_SET);
        printf("%.02f\t%.02f\t%.02f\n", l.liste[i].note_median, l.liste[i].note_final, l.liste[i].note_moyenne);
    }
}

int stracmp(char s1[], char s2[]) {
    int i;
    for(i=0; i<strlen(s1) || i<strlen(s2); i++) {
        if(s1[i]==s2[i]) continue;
        if(s1[i]<s2[i]) return 0;
        if(s1[i]>s2[i]) return 1;
    }
    return 0;
}

Liste_Etudiants sortListe_Etudiants(Liste_Etudiants l) {
    int i, flag;
    Etudiant tmp;
    do {
        flag = 0;
        for(i=0; i<l.effectif-1; i++) {
            if(stracmp(l.liste[i].nom, l.liste[i+1].nom)) {
                tmp = l.liste[i];
                l.liste[i] = l.liste[i+1];
                l.liste[i+1] = tmp;
                flag = 1;
            }
        }
    } while(flag);
    return l;
}

int exo47(){
    printf("Pointeurs et structures :\n");
    Liste_Etudiants l = getListe_Etudiants();
    printListe_Etudiants(sortListe_Etudiants(l));
    return 0;
}
