#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_UV_MAX 6

enum Mode {normal, reduit};

typedef struct student
{
    char nom[20];
    char prenom[100];
    int identifiant;
    char specialite[4];
    char UV[NB_UV_MAX][5];
    struct student *suivant;
} etudiant;

void cgets(char *s, int l)
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

etudiant *getDataEtudiant(enum Mode mode)
{
    if(mode == normal) printf("\nCreation d'un nouvel etudiant :\n");
    else if(mode == reduit) printf("\nSuppression d'un etudiant :\n");
    int i;
    char str[5];
    etudiant *e = (etudiant*) malloc(sizeof(etudiant));
    printf("Nom de l'etudiant : ");
    cgets(e->nom, 20);
    printf("Prenom de l'etudiant : ");
    cgets(e->prenom, 100);
    printf("Identifiant de l'etudiant : ");
    scanf("%d", &e->identifiant);
    printf("Specialite de l'etudiant : ");
    cgets(e->specialite, 4);
    if(mode == normal) for(i = 0; i < NB_UV_MAX; i++) {
        printf("UV %d de l'etudiant : ", i+1);
        cgets(str, 5);
        if(!strcmp(str, "----")) for(; i < NB_UV_MAX; i++) strcpy(e->UV[i], "----");
        else strcpy(e->UV[i], str);
    }
    e->suivant = NULL;
    return e;
}

etudiant *creerListe(int nbEtudiant)
{
    if(nbEtudiant < 1) return NULL;
    int i;
    etudiant *L, *temp1, *temp2;
    printf("\nCreation d'une liste de %d etudiant(s) :\n", nbEtudiant);
    for(i = 0; i < nbEtudiant; i++)
    {
        temp2 = getDataEtudiant(normal);
        if (i==0)
        {
            L=temp2;
            temp1=L;
        }
        else
        {
            temp1->suivant = temp2;
            temp1 = temp2;
        }
    }
    return L;
}

etudiant *creerNouvelleListe() {
    int n;
    printf("\nCreation d'une liste d'etudiants :\n");
    printf("(int)$ ");
    scanf("%d", &n);
    return creerListe(n);
}

int compterEtudiant(etudiant *L)
{
    etudiant *e = L;
    int cpt = 0;
    while(e != NULL)
    {
        cpt++;
        e = e->suivant;
    }
    return cpt;
}

void printEtudiant(etudiant *e)
{
    int i;
    printf("\t-----\n");
    printf("Nom de l'etudiant : %s\n", e->nom);
    printf("Prenom de l'etudiant : %s\n", e->prenom);
    printf("Identifiant de l'etudiant : %05d\n", e->identifiant);
    printf("Specialite de l'etudiant : %s\n", e->specialite);
    for(i = 0; i < NB_UV_MAX; i++) printf("UV %d de l'etudiant : %s\n", i+1, e->UV[i]);
}

void printListeEtudiant(etudiant *L)
{
    etudiant *e = L;
    int cpt = compterEtudiant(L);
    printf("\nAffichage de la liste (%d etudiant(s)): \n", cpt);
    if(cpt == 0) printf("\nListe vide !\n");
    else while(e != NULL)
    {
        printEtudiant(e);
        e = e->suivant;
    }
    printf("\n\t*****\n");
}

void supprimerListe(etudiant *L) {
    etudiant *ptr = L, *precedent = L;
    while(ptr != NULL) {
        precedent = ptr;
        ptr = ptr->suivant;
        free(precedent);
    }
}

/*
int dernierElement(etudiant *e)
{
    if(e != NULL && e->suivant == NULL)
        return 1;
    else
        return 0;
}

void inverser(etudiant **L, etudiant *precedent, etudiant *e)
{
    etudiant *apres = e->suivant;
    printf("inverser %s <-> %s\n", e->nom, apres->nom);
    e->suivant = apres->suivant;
    apres->suivant = e;
    if(e == *L)
        *L = apres;
    else
        precedent->suivant = apres;
}
*/

void trier(etudiant **L)
{
    int flag = 1;
    etudiant *precedent, *e, *apres;
    while(flag)
    {
        e = *L;
        precedent = *L;
        flag = 0;
        while(e != NULL && e->suivant != NULL)
        {
            apres = e->suivant;
            if(strcmp(e->nom, apres->nom) > 0)
            {
                printf("inversion %s <-> %s\n", e->nom, apres->nom);
                e->suivant = apres->suivant;
                apres->suivant = e;
                if(e == *L)
                    *L = apres;
                else
                    precedent->suivant = apres;
                flag = 1;
            }
            precedent = e;
            e = apres;
        }
    }
}

int insererEtudiant(etudiant **L, etudiant *e)
{
    etudiant *ptr = *L, *precedent = *L;
    if(*L == NULL) {
        *L = e;
        return 1;
    }
    while(ptr != NULL)
    {
        if(!strcmp(ptr->nom, e->nom) && !strcmp(ptr->prenom, e->prenom) && ptr->identifiant == e->identifiant && !strcmp(ptr->specialite, e->specialite)) return 0;
        precedent = ptr;
        ptr = ptr->suivant;
    }
    precedent->suivant = e;
    trier(L);
    return 1;
}

int supprimerEtudiant(etudiant **L, etudiant *e)
{
    etudiant *ptr = *L, *precedent = *L;
    while(ptr != NULL)
    {
        if(!strcmp(ptr->nom, e->nom) && !strcmp(ptr->prenom, e->prenom) && ptr->identifiant == e->identifiant && !strcmp(ptr->specialite, e->specialite))
        {
            printf("Etudiant a supprimer :\n");
            printEtudiant(ptr);
            if(ptr == *L)
                *L = ptr->suivant;
            else
                precedent->suivant = ptr->suivant;
            return 1;
        }
        precedent = ptr;
        ptr = ptr->suivant;
    }
    return 0;
}

void recupererSelonSpecialite(etudiant *L, etudiant **GSI, etudiant **GSM, etudiant **ISI)
{
    etudiant *ptr = L;
    while(ptr != NULL) {
        if(!strcmp(ptr->specialite, "GSI")) {
            etudiant *e = (etudiant*) malloc(sizeof(etudiant));
            *e = *ptr;
            e->suivant = NULL;
            insererEtudiant(GSI, e);
        }
        else if(!strcmp(ptr->specialite, "GSM")) {
            etudiant *e = (etudiant*) malloc(sizeof(etudiant));
            *e = *ptr;
            e->suivant = NULL;
            insererEtudiant(GSM, e);
        }
        else if(!strcmp(ptr->specialite, "ISI"))  {
            etudiant *e = (etudiant*) malloc(sizeof(etudiant));
            *e = *ptr;
            e->suivant = NULL;
            insererEtudiant(ISI, e);
        }
        ptr = ptr->suivant;
    }
}

int exo55()
{
    char c;
    printf("Operations sur les listes chainees :\n");
    etudiant *L, *GSM = NULL, *GSI = NULL, *ISI = NULL;
    L = creerNouvelleListe();
    printListeEtudiant(L);
    while(1)
    {
        printf("\n(char)$ ");
        fflush(stdin);
        c = getchar();
        switch(c)
        {
        case 'q' :
            return 0;
        case 'c' :
            supprimerListe(L);
            L = creerNouvelleListe();
            printf("\nNouvelle liste :\n");
            printListeEtudiant(L);
            break;
        case 't' :
            trier(&L);
            printf("\nNouvelle liste :\n");
            printListeEtudiant(L);
            break;
        case 'i' :
            if(!insererEtudiant(&L, getDataEtudiant(normal))) printf("\nE: Insertion impossible !\n");
            printf("\nNouvelle liste :\n");
            printListeEtudiant(L);
            break;
        case 's' :
            if(!supprimerEtudiant(&L, getDataEtudiant(reduit))) printf("\nE: Suppression impossible !\n");
            printf("\nNouvelle liste :\n");
            printListeEtudiant(L);
            break;
        case 'r' :
            supprimerListe(GSI);
            supprimerListe(GSM);
            supprimerListe(ISI);
            recupererSelonSpecialite(L, &GSI, &GSM, &ISI);
            printf("Liste originelle :\n");
            printListeEtudiant(L);
            printf("Liste des etudiants GSI :\n");
            printListeEtudiant(GSI);
            printf("Liste des etudiants GSM :\n");
            printListeEtudiant(GSM);
            printf("Liste des etudiants ISI :\n");
            printListeEtudiant(ISI);
            break;
        case 'p' :
            printListeEtudiant(L);
            break;
        default :
            printf("E: Commande non reconnue !\n");
        }
    }
    return 0;
}
