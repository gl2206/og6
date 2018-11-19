#include <stdio.h>
#include <math.h>

typedef struct {
    float r;
    float i;
} cartCpl;

typedef struct {
    float m;
    float a;
} polCpl;

typedef struct {
    int type;
    union {
        cartCpl c;
        polCpl p;
    } Cpl;
} Cplx;

Cplx newCplx() {
    Cplx c;
    c.type=0;
    c.Cpl.c.r=0;
    c.Cpl.c.i=0;
    return c;
}

int getCplx(Cplx *c) {
    printf("(int)$ ");
    scanf("%d", &(c->type));
    switch(c->type) {
        case 0 : printf("(float)$ "); scanf("%f", &(c->Cpl.c.r)); printf("(float)$ "); scanf("%f", &(c->Cpl.c.i)); break;
        case 1 : printf("(float)$ "); scanf("%f", &(c->Cpl.p.m)); printf("(float)$ "); scanf("%f", &(c->Cpl.p.a)); break;
        default : printf("E: Type de complexe incorrect !"); return 1;
    }
    return 0;
}

void printCplx(Cplx c) {
    if(c.type==0) printf("%f + i * %f\n", c.Cpl.c.r, c.Cpl.c.i);
    else printf("%f * e^(i * %f)\n", c.Cpl.p.m, c.Cpl.p.a);
}

Cplx reelToCplx(float r) {
    Cplx c={.type=0, .Cpl.c.r=r, .Cpl.c.i=0};
    return c;
}

void cartTopol(Cplx *c) {
    if(c->type==0) {
        float r=c->Cpl.c.r, i=c->Cpl.c.i;
        c->Cpl.p.m=sqrt(r*r+i*i);
        c->Cpl.p.a=atan2(i, r);
        c->type=1;
    }
}

void polTocart(Cplx *c) {
    if(c->type==1) {
        float m=c->Cpl.p.m, a=c->Cpl.p.a;
        c->Cpl.c.r=m*cos(a);
        c->Cpl.c.i=m*sin(a);
        c->type=0;
    }
}

Cplx sommeCplx(Cplx a, Cplx b) {
    int t=a.type;
    Cplx c;
    c.type=0;
    polTocart(&a);
    polTocart(&b);
    c.Cpl.c.r=a.Cpl.c.r+b.Cpl.c.r;
    c.Cpl.c.i=a.Cpl.c.i+b.Cpl.c.i;
    if(t==1) cartTopol(&c);
    return c;
}

Cplx sousCplx(Cplx a, Cplx b) {
    int t=a.type;
    Cplx c;
    c.type=0;
    polTocart(&a);
    polTocart(&b);
    c.Cpl.c.r=a.Cpl.c.r-b.Cpl.c.r;
    c.Cpl.c.i=a.Cpl.c.i-b.Cpl.c.i;
    if(t==1) cartTopol(&c);
    return c;
}

Cplx multCplx(Cplx a, Cplx b) {
    int t=a.type;
    Cplx c;
    c.type=1;
    cartTopol(&a);
    cartTopol(&b);
    c.Cpl.p.m=a.Cpl.p.m*b.Cpl.p.m;
    c.Cpl.p.a=a.Cpl.p.a+b.Cpl.p.a;
    if(t==0) polTocart(&c);
    return c;
}

Cplx divCplx(Cplx a, Cplx b) {
    int t=a.type;
    Cplx c;
    c.type=1;
    cartTopol(&a);
    cartTopol(&b);
    c.Cpl.p.m=a.Cpl.p.m/b.Cpl.p.m;
    c.Cpl.p.a=a.Cpl.p.a-b.Cpl.p.a;
    if(t==0) polTocart(&c);
    return c;
}

Cplx sqrtCplx(Cplx c) {
    int t=c.type;
    Cplx b;
    b.type=0;
    polTocart(&c);
    b.Cpl.c.r=sqrt(0.5*(c.Cpl.c.r+sqrt(c.Cpl.c.r*c.Cpl.c.r+c.Cpl.c.i*c.Cpl.c.i)));
    b.Cpl.c.i=((c.Cpl.c.i==fabs(c.Cpl.c.i))?1:-1)*sqrt(0.5*(-c.Cpl.c.r+sqrt(c.Cpl.c.r*c.Cpl.c.r+c.Cpl.c.i*c.Cpl.c.i)));
    if(t==1) cartTopol(&b);
    return b;
}

void equa2degreCplx(Cplx a, Cplx b, Cplx c) {
    Cplx d = sousCplx(multCplx(b, b), multCplx(multCplx(reelToCplx(4), a), c));
    d = sqrtCplx(d);
    Cplx z1 = divCplx(sommeCplx(sousCplx(reelToCplx(0), b), d), multCplx(reelToCplx(2), a));
    Cplx z2 = divCplx(sousCplx(sousCplx(reelToCplx(0), b), d), multCplx(reelToCplx(2), a));
    printf("z1 = ");
    printCplx(z1);
    printf("z2 = ");
    printCplx(z2);
}

int exo44() {
    printf("Nombre complexe :\n");
    Cplx a = newCplx(), b = newCplx(), c = newCplx();
    char car;
    while (1) {
        printf("(char)$ ");
        fflush(stdin);
        car = getchar();
        switch(car) {
            case 'q' : return 0;
            case 'a' : if(getCplx(&a)) return 1; break;
            case 'b' : if(getCplx(&b)) return 1; break;
            case 'c' : if(getCplx(&c)) return 1; break;
            case 'A' : if(a.type==0) cartTopol(&a); else polTocart(&a); printf("a = "); printCplx(a); break;
            case 'B' : if(b.type==0) cartTopol(&b); else polTocart(&b); printf("b = "); printCplx(b); break;
            case 'C' : if(c.type==0) cartTopol(&c); else polTocart(&c); printf("c = "); printCplx(c); break;
            case 'p' : printf("a = "); printCplx(a); printf("b = "); printCplx(b); printf("c = "); printCplx(c); break;
            case '+' : c = sommeCplx(a, b); printf("c = "); printCplx(c); break;
            case '-' : c = sousCplx(a, b); printf("c = "); printCplx(c); break;
            case '*' : c = multCplx(a, b); printf("c = "); printCplx(c); break;
            case '/' : c = divCplx(a, b); printf("c = "); printCplx(c); break;
            case 'r' : equa2degreCplx(a, b, c); break;
            default : printf("E: Commande incorrecte !\n");
        }
    }
    return 0;
}
