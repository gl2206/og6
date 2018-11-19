#include <stdio.h>

void fibonacci(int n, int *res)
{
    if(n==0)
    {
        *res=0;
        return;
    }
    if(n==1)
    {
        *res=1;
        return;
    }
    int i, v=0, tmp;
    for(i=1; i<n; i++)
    {
        tmp=*res+v;
        v=*res;
        *res=tmp;
    }
}

void fibonacciRec(int n, int *res)
{
    if(n==0)
    {
        *res=0;
        return;
    }
    if(n==1)
    {
        *res=1;
        return;
    }
    int u, v;
    fibonacciRec(n-1, &u);
    fibonacciRec(n-2, &v);
    *res=u+v;
}

int exo28()
{
    printf("Suite de Fibonacci :\n");
    int n, r=1;
    printf("(int)$ ");
    scanf("%d", &n);
    fibonacci(n, &r);
    printf("Procedure iterative : %d\n", r);
    fibonacciRec(n, &r);
    printf("Procedure recursive : %d\n", r);
    return 0;
}
