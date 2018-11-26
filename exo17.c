#include <stdio.h>

int premier(int nb) {
    int i;
    for(i=nb/2; i>1; i--) {
        if(nb%i==0) return 0;
    }
    return 1;
}

int main() {
    int i;
    printf("Liste des entiers premiers inferieurs a 50 :\n");
    for(i=1; i<=50; i++) {
        if(premier(i)) printf(" %d\n", i);
    }
    return 0;
}
