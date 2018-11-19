#include <stdio.h>

int main() {
    int a, b, max, min;
    printf("A = ");
    scanf("%d", &a);
    printf("B = ");
    scanf("%d", &b);
    if(a > b) {
        max = a;
        min = b;
        printf("MIN = %d ET MAX = %d", min, max);
    }
    else if(a < b) {
        max = b;
        min = a;
        printf("MIN = %d ET MAX = %d", min, max);
    }
    else {
        printf("E: A = B");
    }
    return 0;
}
