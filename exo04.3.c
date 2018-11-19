#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[10];
    str[0] = NULL;
    str[4] = NULL;
    printf("Calculatrice a deux caracteres :\n");
    while(1)
    {
        printf("$ ");
        gets(str);
        if(str[0] != NULL && str[4] != NULL)
        {
            switch(str[2])
            {
            case '+' :
                printf("%c\n", str[0]+str[4]);
                break;
            case '-' :
                printf("%c\n", str[0]-str[4]);
                break;
            default :
                if(ispunct(str[2])) printf("E: Operateur non reconnu\n");
                else printf("E: Format incorrect\n");
            }
            str[0] = NULL;
            str[4] = NULL;
        }
        else printf("E: Format incorrect\n");
    }
}
