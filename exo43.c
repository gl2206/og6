#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

int isinCircle(Point a) {
    if(a.x*a.x+a.y*a.y<=1) return 1;
    else return 0;
}

float approxPi(int n) {
    Point a;
    int i, p=0;
    for(i=0; i<n; i++) {
        a.x=(float)rand()/RAND_MAX;
        a.y=(float)rand()/RAND_MAX;
        if(isinCircle(a)) p++;
    }
    return 4.0*p/n;
}

int exo43() {
    printf("Nombre PI :\n");
    int n;
    printf("(int)$ ");
    scanf("%d", &n);
    float pi=approxPi(n);
    printf("PI = %f\n", pi);
    printf("deltaPI = %f\n", pi-M_PI);
    return 0;
}
