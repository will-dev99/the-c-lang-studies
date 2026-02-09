#include <stdio.h>

/* Conta caracteres na entrada; segunda versão */

int main() {

    double nc;

    for (nc = 0; getchar() != EOF; ++nc);

    printf("%.0f\n", nc);
}
