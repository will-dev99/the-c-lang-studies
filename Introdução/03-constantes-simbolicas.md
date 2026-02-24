Números soltos no código como `300` ou `20` são chamados de **números mágicos**: quem lê o código sem contexto não sabe o que representam, e mudar esses valores exige caçar todas as ocorrências no programa.

A solução é usar `#define` para dar nomes a esses valores:

```c
#define name replacement
```

A partir daí, toda ocorrência de `name` no código é substituída por `replacement` antes da compilação. `name` segue as mesmas regras de nome de variável (letras e dígitos, começa com letra), e `replacement` pode ser qualquer sequência de caracteres.

---

## Exemplo: tabela de temperatura

```c
#include <stdio.h>

#define LOWER   0    /* limite mínimo da tabela */
#define UPPER 300    /* limite máximo */
#define STEP   20    /* tamanho do salto */

int main()
{
    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

`LOWER`, `UPPER` e `STEP` são constantes — não variáveis, então não aparecem em declarações. Por convenção, constantes simbólicas são escritas em **MAIÚSCULO** para se distinguirem visualmente das variáveis.

Note que `#define` não termina com `;` — não é necessário.
