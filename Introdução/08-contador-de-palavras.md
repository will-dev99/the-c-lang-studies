Uma versão simples do comando `wc` do Unix. O programa lê a entrada e conta caracteres, linhas e palavras — onde "palavra" é qualquer sequência de caracteres sem espaço, tab ou newline.

```c
#include <stdio.h>

#define IN  1  /* dentro de uma palavra */
#define OUT 0  /* fora de uma palavra */

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == '\n')
            ++nl;

        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}
```

---

## Como funciona a contagem de palavras

A variável `state` rastreia se o programa está **dentro** (`IN`) ou **fora** (`OUT`) de uma palavra. A cada novo caractere não-espaço após um espaço, uma nova palavra começou — e `nw` é incrementado. Usar `IN` e `OUT` em vez de `1` e `0` diretamente torna o código mais legível, e facilita muito alterações futuras (evita "números mágicos" espalhados pelo código).

---

## Atribuição múltipla

```c
nl = nw = nc = 0;
```

Em C, atribuição é uma expressão com valor, associada da direita para a esquerda. Essa linha é equivalente a:

```c
nl = (nw = (nc = 0));
```

Primeiro `nc` recebe `0`, depois `nw` recebe o resultado (`0`), e por fim `nl` recebe o resultado (`0`). É uma forma compacta de zerar várias variáveis de uma vez.

---

## Operadores `||` e `&&`

`||` significa **OU** e `&&` significa **E**. No teste:

```c
if (c == ' ' || c == '\n' || c == '\t')
```

Basta **uma** das condições ser verdadeira para o `if` ser satisfeito. O `&&` exige que **todas** sejam verdadeiras, e tem precedência maior que `||`.

Um detalhe importante: a avaliação para assim que o resultado é conhecido. Se `c == ' '` já for verdade, as outras condições nem são checadas — não tem como o resultado mudar. Isso é chamado de **avaliação em curto-circuito** e pode ser importante em expressões mais complexas (como evitar acesso inválido a ponteiro nulo).

---

## if-else

```c
if (condição) {
    // executado se verdadeiro
} else {
    // executado se falso
}
```

No programa, o `else if` só incrementa `nw` quando `state == OUT` — ou seja, só na **primeira** letra de cada palavra, não em todas as letras dela.
