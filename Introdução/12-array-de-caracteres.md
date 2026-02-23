O tipo de array mais comum em C é o **array de caracteres**. Para ilustrar seu uso, o livro constrói um programa que lê várias linhas de texto e exibe a mais longa.

## Esboço do algoritmo

```
enquanto (existir outra linha)
    se (for maior que a maior linha anterior)
        salve ela
        salve o seu tamanho

exibir maior linha
```

O programa se divide naturalmente em três responsabilidades: **ler** a linha, **guardar** a maior, e **controlar** o processo. Faz sentido separar isso em funções.

---

## As funções

**`getline`** — lê a próxima linha da entrada e retorna seu tamanho, ou zero ao encontrar EOF. Zero nunca é um tamanho válido de linha (toda linha tem ao menos um caractere, mesmo que seja só o `\n`), então serve bem como sinal de fim de arquivo.

**`copy`** — copia a linha atual para um lugar seguro quando ela for maior que todas as anteriores.

**`main`** — controla as duas funções acima.

---

## Código

```c
#include <stdio.h>
#define MAXLINE 1000 /* tamanho máximo de uma linha */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* exibe a maior linha da entrada */
int main()
{
    int len;            /* tamanho da linha atual */
    int max;            /* tamanho máximo visto até então */
    char line[MAXLINE];    /* linha atual */
    char longest[MAXLINE]; /* maior linha encontrada */

    max = 0;

    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0)
        printf("%s", longest);

    return 0;
}

/* lê uma linha em s, retorna o comprimento */
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* copia 'from' para 'to'; assume que 'to' é grande o suficiente */
void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}
```

---

## Sobre os argumentos de `getline`

```c
int get_line(char s[], int lim);
```

- `s[]` — array de caracteres onde a linha será armazenada
- `lim` — tamanho máximo a ler

Não é preciso informar o tamanho de `s` na declaração da função — ele não é usado internamente, pois `lim` já cumpre esse papel. O tamanho real do array fica na responsabilidade de quem chama a função (`main`).

`getline` retorna um `int` (o comprimento da linha lida). Como `int` é o tipo de retorno padrão em C, ele poderia ser omitido — mas é boa prática deixar explícito.

---

## Observações sobre strings e segurança

O `%s` do `printf` espera que o argumento seja uma string terminada em `'\0'`. A `copy` também depende disso: ela copia caractere por caractere até encontrar o `'\0'`, incluindo ele na saída.

### Limites e checagem de erros

`getline` para de ler quando o array está cheio, mesmo que a linha ainda não tenha terminado — então opera com segurança. O `main` consegue detectar se uma linha era muito longa checando o comprimento retornado e o último caractere, e agir conforme necessário. O programa acima ignora isso por simplicidade.

`copy`, por outro lado, não faz checagem de estouro — e isso é intencional. Quem chama `copy` já sabe (ou consegue descobrir) o tamanho das strings envolvidas, então a responsabilidade fica com o chamador.
