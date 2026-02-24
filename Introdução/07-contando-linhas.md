Como toda linha termina com `\n`, contar linhas é simplesmente contar quantos `\n` aparecem na entrada.

```c
#include <stdio.h>

int main()
{
    int c, nl;

    nl = 0;

    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;

    printf("%d\n", nl);
}
```

---

## `==` vs `=`

`==` testa igualdade. `=` atribui um valor. São coisas diferentes — confundi-los é um erro clássico em C:

```c
if (c == '\n')  // correto: testa se c é newline
if (c = '\n')   // errado: atribui '\n' a c e testa o resultado
```

---

## Constantes de caractere

Um caractere entre aspas simples, como `'\n'` ou `'A'`, é uma **constante de caractere** — na prática, só um jeito de escrever um inteiro pequeno. `'A'` vale `65` em ASCII, mas escrever `'A'` é preferível: o significado fica óbvio e não depende de saber o valor numérico.

Sequências de escape funcionam tanto em strings quanto em constantes de caractere. Alguns exemplos:

| Constante | Valor ASCII | Significado |
|---|---|---|
| `'\n'` | 10 | nova linha |
| `'\t'` | 9 | tabulação |
| `'A'` | 65 | letra A |

Um detalhe importante: `'\n'` (aspas simples) é um **único caractere**; `"\n"` (aspas duplas) é uma **string** que contém esse caractere seguido de `\0`. São tipos diferentes em C.
