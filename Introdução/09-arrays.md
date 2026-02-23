## Exemplo: contando dígitos e espaços

O programa abaixo lê caracteres e conta quantas vezes cada dígito (`0`–`9`), espaço em branco e "outros" aparecem na entrada.

```c
#include <stdio.h>

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;

    printf("Digits:");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);

    printf("\nWhite space: %d\nOther: %d\n", nwhite, nother);
}
```

---

## Arrays

`int ndigit[10]` declara um array de 10 inteiros. Em C, índices **sempre começam em 0**, então os elementos vão de `ndigit[0]` até `ndigit[9]`. Um índice pode ser qualquer expressão inteira — uma variável, uma constante, ou até uma operação aritmética.

---
## `c - '0'`?

Em C, `char` é apenas um inteiro pequeno. Cada caractere tem um valor numérico definido pela tabela ASCII. Os dígitos `'0'` a `'9'` têm valores **consecutivos e crescentes** nessa tabela:

| Caractere | Valor ASCII |
|-----------|-------------|
| `'0'`     | 48          |
| `'1'`     | 49          |
| `'2'`     | 50          |
| ...       | ...         |
| `'9'`     | 57          |

Então se `c` contém o caractere `'7'` (valor 55), a expressão `c - '0'` resulta em `55 - 48 = 7` — exatamente o valor numérico do dígito. Isso transforma qualquer dígito em um índice válido para `ndigit[0..9]`.

O teste `c >= '0' && c <= '9'` verifica se o caractere é um dígito usando essa mesma lógica: se o valor de `c` está entre os valores de `'0'` e `'9'`, é um dígito.

---

## Cadeia if-else if-else

```c
if (c >= '0' && c <= '9')
    ++ndigit[c-'0'];
else if (c == ' ' || c == '\t' || c == '\n')
    ++nwhite;
else
    ++nother;
```

Esse padrão expressa uma decisão com múltiplos caminhos. As condições são avaliadas **de cima para baixo** até uma ser satisfeita — só essa ramificação é executada, e o restante é ignorado. Se nenhuma condição bater, o bloco `else` final é executado (quando presente).

```
if (condição1)
    ...
else if (condição2)
    ...
else if (condição3)
    ...
else
    ...         ← executado se nenhuma das anteriores for verdadeira
```

Cada ramificação pode conter múltiplas instruções se estiverem entre `{ }`. O `else` final é opcional — se omitido e nenhuma condição bater, nada acontece.

> **Dica de estilo:** manter todos os `else if` no mesmo nível de indentação (como acima) evita que cadeias longas de decisões "escorregem" para fora da tela.

---

##  `switch`?

Para decisões onde se compara **uma única variável** contra um conjunto de constantes, C oferece o `switch` como alternativa mais legível ao `if-else if`. Veremos isso mais adiante.
