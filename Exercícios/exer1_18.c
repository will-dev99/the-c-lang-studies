/*Exercício 1-18. Escreva um programa para remover espaços em branco e tabs do final de cada linha de entrada, e para deletar completamente as linhas em branco.*/

#include <stdio.h>
#define MAXLINE 1000

int get_line(char linha[], int maxline);

int main() {
    int contador;
    int tam;
    char linha[MAXLINE];
    
    while ((tam = get_line(linha, MAXLINE)) > 0) {
        contador = tam - 2;
        
        // enquanto contador for maior que 0 e linha[contador] for um espaço em branco OU um tab, decrementa 1 em contador
        while (contador >= 0 && (linha[contador] == ' ' || linha[contador] == '\t'))
            --contador;
        
        if (contador >= 0) {
            linha[contador+1] = '\n';
            linha[contador+2] = '\0';
            printf("%s", linha);
        }
    }
    return 0;
}

int get_line(char linha[], int lim)
{
    int c, pos_atual;

    for (pos_atual = 0; pos_atual < lim - 1 &&(c = getchar()) != EOF &&c!='\n'; ++pos_atual)
        linha[pos_atual] = c;
    if (c == '\n')
    {
        linha[pos_atual] = c;
        ++pos_atual;
    }
    linha[pos_atual] = '\0';
    return pos_atual;
}
