#include "TD5.h"

int getTab(int tab[], int *i);
void printTab(int t[], int lg);

void swapTab(int t[], int lg, int a, int b) {
    int tmp=t[a];
    t[a]=t[b];
    t[b]=tmp;
}

int exo35()
{
    printf("Swap dans un tableau :\n");
    int tab[10];
    int l=0, a, b;
    if(getTab(tab, &l)) return 1;
    printf("(int)$ ");
    scanf("%d", &a);
    printf("(int)$ ");
    scanf("%d", &b);
    printTab(tab, l);
    swapTab(tab, l, a-1, b-1);
    printTab(tab, l);
    return 0;
}
