## Versão com `while` e `long`

```c
#include <stdio.h>

int main()
{
    long nc;

    nc = 0;

    while (getchar() != EOF)
        ++nc;

    printf("%ld\n", nc);
}
```

---

## Operadores `++` e `--`

`++nc` incrementa `nc` em 1. É equivalente a `nc = nc + 1`, mas mais conciso. O operador correspondente `--` decrementa.

Ambos existem em duas formas:

| Forma | Nome | Comportamento em expressões |
|---|---|---|
| `++nc` | prefixo | incrementa *antes* de usar o valor |
| `nc++` | pós-fixo | incrementa *depois* de usar o valor |

Fora de uma expressão maior (como aqui, em `++nc;` isolado), os dois fazem a mesma coisa.

---

## Por que `long` e não `int`?

Em máquinas de 16 bits, `int` vai de −32.767 a +32.767 — um arquivo um pouco maior já estouraria o contador. `long` garante ao menos 32 bits, suportando valores até ~2 bilhões. O especificador `%ld` no `printf` indica que o argumento é um `long`.

---

## Versão com `for` e `double`

Para números ainda maiores, dá pra usar `double` (ponto flutuante de dupla precisão). Essa versão também mostra um `for` com corpo vazio:

```c
#include <stdio.h>

int main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;

    printf("%.0f\n", nc);
}
```

O `for` faz todo o trabalho nas suas próprias cláusulas — inicialização, teste e incremento. O corpo do loop não precisa fazer nada, mas a gramática do C exige que exista alguma coisa lá. O ponto e vírgula sozinho (`;`) é chamado de **instrução nula** e serve exatamente pra isso.

`%.0f` exibe o `double` sem casas decimais (a parte fracionária é sempre 0 aqui de qualquer forma).

---

## Teste no topo do loop

Tanto `while` quanto `for` testam a condição **antes** de executar o corpo. Se a entrada estiver vazia, `getchar()` já retorna `EOF` na primeira chamada — o loop nunca executa e o programa exibe `0`, que é a resposta certa.

Isso parece óbvio, mas é importante: programas devem se comportar corretamente mesmo com entrada vazia ou mínima, sem precisar de tratamento especial para esse caso.