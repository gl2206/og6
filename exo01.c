#include <stdio.h>
#include <time.h>

int main()
{
    printf("Hello world!\n");
    time_t rawtime;
    struct tm *info;
    char sem[3];
    time( &rawtime );
    info = localtime( &rawtime );
    printf("%d/%d/%d\n", info->tm_mday, info->tm_mon+1, info->tm_year+1900);
    strftime(sem, 3, "%U", info);
    printf("%s\n", sem);
    printf("guillaume.lebonvallet@utt.fr");
    return 0;
}
