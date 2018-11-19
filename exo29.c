#include <stdio.h>
#include <string.h>

int ispalindrome(char mot[]) {
    int i, l=strlen(mot);
    for(i=0; i<l/2; i++){
        if(mot[i]!=mot[l-i-1]) return 0;
    }
    return 1;
}

int ispalindromeRec(char mot[]) {
    int l=strlen(mot);
    if(l<=1) return 1;
    char txt[l-1];
    if(mot[0]!=mot[l-1]) return 0;
    memcpy(txt, &mot[1], l-2);
    txt[l-2]='\0';
    return ispalindromeRec(txt);
}

int exo29()
{
    printf("Palindromes :\n");
    char txt[30];
    printf("(char[])$ ");
    fflush(stdin);
    gets(txt);
    printf("Fonction iterative : ");
    if(ispalindrome(txt)) printf("C'est un palindrome\n");
    else printf("Ce n'est pas un palindrome\n");
    printf("Fonction recursive : ");
    if(ispalindromeRec(txt)) printf("C'est un palindrome\n");
    else printf("Ce n'est pas un palindrome\n");
    return 0;
}
