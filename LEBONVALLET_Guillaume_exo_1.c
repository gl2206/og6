/* DEBUT  DU CODE */

#include <stdio.h>
    // Header de librairie <stdlib.h> manquant

void main() {   // Le type de retour de la fonction main doit etre  : int
    int degre = 0;
    int indice;
    double accumulateur;
    double valeur_X = 0     // Point-virgule manquant en fin de ligne
    printf("Bonjour , entrez  le degre  de votre  polynome : ");
    scanf("%d", degre);     // Le deuxieme argument du scanf doit etre : &degre
    double* coefficients = (double *)  malloc (degre * sizeof(degre));  // L'argument du malloc doit etre : (degre + 1) * sizeof(double)
    printf("Bien  recu. Entrez  maintenant  les  coefficients  de votre polynome (en  commencant  par  celui  de plus  petit  degre) :");
    for (indice = 0 ; indice <= degre ; indice++) {
        scanf("%d", &coefficients[indice]);     // Le premier argument du scanf doit etre : "%f"
    }
    printf("Voici  votre  polynome : \n");
    printf(" %.2f + ", coefficients [0]);
    for (indice = 1;  indice < degre ; indice  ++) {
        printf(" %.2f X^%d   + ", indice, coefficients[indice]); // Le deuxieme argument du printf doit etre : coefficients[indice]. Le troisieme argument du printf doit etre : indice
    }
    printf(" %.2f X^%d ", coefficients[indice], indice);
    printf("A present  entrez  des  valeurs  pour x ou  ’0’ pour  quitter  le programme ");
    while (valeur_X  != 0) {
        scanf("%lf" ,&valeur_X);
        for (indice=degre ; indice  > 0 ; indice --)
            accumulateur  *=  valeur_X ;
        accumulateur  +=  coefficients[indice] ;
        printf("La  valeur  du  polynome  en x=%f \t est : %f \n", valeur_X, accumulateur);
        printf("Entrez  une  nouvelle  valeur  pour x (ou  ’0’ pour quitter  le  programme )");
    }
    printf("Au  revoir \n");
    return(0);
}

/* FIN DU CODE */
