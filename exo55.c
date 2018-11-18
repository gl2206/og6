#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char nom[20];
    char prenom[100];
    int identifiant;
    char specialite[4];
    struct student *suivant;
} etudiant;

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

etudiant *getDataEtudiant()
{
    etudiant *e = (etudiant*) malloc(sizeof(etudiant));
    printf("Nom de l'etudiant : ");
    sgets(e->nom, 20);
    printf("Prenom de l'etudiant : ");
    //sgets(e->prenom, 100);
    printf("Identifiant de l'etudiant : ");
    //scanf("%d", &e->identifiant);
    printf("Specialite de l'etudiant : ");
    //sgets(e->specialite, 4);
    e->suivant = NULL;
    return e;
}

etudiant *creerListe(int nbEtudiant)
{
    if(nbEtudiant < 1)
        return NULL;
    int i;
    etudiant *L; // = getDataEtudiant();
    etudiant *temp1 /*= L*/, *temp2;
    for(i = 0; i < nbEtudiant; i++)
    {
        temp2 = getDataEtudiant();
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
/*    printf("apres=%s\n",apres->nom);
    printf("prec=%s\n",precedent->nom);
    printf("L=%s\n",(*L)->nom);
*/  e->suivant = apres->suivant;
    apres->suivant = e;
    if(e == *L)
        *L = apres;
    else
        precedent->suivant = apres;
//    printf("apres=%s\n",apres->nom);
//    printf("prec=%s\n",precedent->nom);
//    printf("L=%s\n",(*L)->nom);
}

void trier(etudiant **L)
{
    int flag = 1;
    etudiant *precedent, *ptr = *L, *apres;
    while(flag)
    {
        ptr = *L;
        precedent = *L;
        flag = 0;
        while(!dernierElement(ptr))
        {
            apres = ptr->suivant;
            if(strcmp(ptr->nom, apres->nom) > 0)
            {
                inverser(L, precedent, ptr);
                //printf("ds inv L=%s\n",(*L)->nom);
                flag = 1;
            }
            precedent=ptr;
            ptr = apres;
        }
    }
    //printListeEtudiant(*L);
}

void printEtudiant(etudiant *e)
{
    printf("\t-----\n");
    printf("Nom de l'etudiant : %s\n", e->nom);
    /*    printf("Prenom de l'etudiant : %s\n", e->prenom);
        printf("Identifiant de l'etudiant : %d\n", e->identifiant);
        printf("Specialite de l'etudiant : %s\n", e->specialite);
    */
}

void printListeEtudiant(etudiant *L)
{
    etudiant *e = L;
    printf("Affichage de la liste : %s\n", L->nom);
    while(e != NULL)
    {
        printEtudiant(e);
        e = e->suivant;
    }
    printf("\t*****\n");
}

int exo55()
{
    printf("Operations sur les listes chainees :\n");
    etudiant *L = creerListe(4);
    printf("==========\n");
    printListeEtudiant(L);
    trier(&L);
    printf("==========\n");
    printListeEtudiant(L);
    return 0;
}
