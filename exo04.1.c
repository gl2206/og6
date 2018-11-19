#include <stdio.h>
#include <ctype.h>

int main()
{
    int a, b;
    char op;
    printf("Calculatrice a deux entiers :\n");
    while(1)
    {
        printf("$ ");
        scanf("%d %c %d", &a, &op, &b);
        switch(op)
        {
        case '+' :
            printf("%d\n", a+b);
            break;
        case '-' :
            printf("%d\n", a-b);
            break;
        case '*' :
            printf("%d\n", a*b);
            break;
        case '/' :
            printf("%d\n", a/b);
            break;
        case '%' :
            printf("%d\n", a%b);
            break;
        default :
            if(ispunct(op)) printf("E: Operateur non reconnu\n");
            else printf("E: Format incorrect\n");
        }
    }
}
