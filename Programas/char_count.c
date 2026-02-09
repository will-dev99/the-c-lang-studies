#include <stdio.h>

/* Conta caracteres na entrada */

int main()
{
    long nc;
    nc = 0;

    while (getchar() != EOF)
        ++nc;

    printf("%ld\n", nc);
}
