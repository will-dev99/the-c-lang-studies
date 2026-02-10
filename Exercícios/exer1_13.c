/* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input... a vertical orientation is more challenging. */
#include <stdio.h>

#define MAX 100

int main() {
    int lengths[MAX];
    int i, j, c, maxfound, length, state;

    i = j = c = maxfound = length = 0;
    state = 0;

    /* inicializa o array com 0's */
    for (i = 0; i < MAX; ++i) {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        /* detecta um fim de palavra verificando se é
        um espaço em branco, um tab ou um caractere 
        de nova linha. */
        if (c == ' ' || c == '\t' || c == '\n') {
            /* se um separador for encontrado, 
            temos uma palavra em andamento (length > 0) 
            e o comprimento é válido (length < 10), 
            processamos a palavra */
            if (length > 0 && length < MAX) {
                if (length > maxfound)
                    maxfound = length;
                lengths[length]++;
            }
            length = 0;
        } else {
            length++;
        }
    }

    /* exibe o histograma */
    printf("Histograma\n");
    for (i = 0; i < maxfound; ++i)
        printf("____");
    printf("\n");

    for (i = maxfound; i > 0; --i) {
        printf("%2d", i);
        for (j = 0; j <= maxfound; ++j) {
            if (lengths[j] >= i) {
                printf("|%2s", "");
            } else {
                printf("|%3s", "");
            }
        }
        printf("\n");
    }

    for (i = 0; i <= maxfound; ++i) {
        if (i <= 10) {
            printf("%2s%d", "", i);
        } else {
            printf("%3d", i);
        }
    }

    printf("\n");
    for (i = 0; i < maxfound; ++i)
        printf("____");
    printf("\n");

    return 0;

}
