O programa mais simples possível com `getchar` e `putchar`: copia tudo que lê na entrada direto para a saída, um caractere por vez.

```c
#include <stdio.h>

int main()
{
    int c;

    c = getchar();

    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
```

---

## Por que `int` e não `char`?

`getchar` retorna um `int`, não um `char`. O motivo é o **EOF**.

EOF é um valor especial que `getchar` retorna quando não há mais entrada. Ele precisa ser diferente de qualquer caractere válido — e como `char` nem sempre consegue representar todos os valores possíveis de `int`, usar `char` para guardar o retorno de `getchar` pode fazer EOF ser confundido com um caractere real.

Usando `int`, `c` consegue guardar qualquer `char` **e** o EOF sem ambiguidade. O valor numérico exato do EOF não importa — é definido em `<stdio.h>` e usar a constante simbólica `EOF` garante que o programa não depende desse número.

---

## Versão mais compacta

Em C, uma atribuição é uma expressão com valor — o valor atribuído. Então `c = getchar()` dentro do `while` já lê *e* testa em uma linha só:

```c
#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
}
```

A lógica é a mesma: lê um caractere, guarda em `c`, e testa se é EOF. Se não for, exibe e repete.

---

## Por que os parênteses são obrigatórios?

`!=` tem **precedência maior** que `=`. Sem os parênteses:

```c
c = getchar() != EOF
```

seria interpretado como:

```c
c = (getchar() != EOF)
```

Ou seja, `c` receberia `0` ou `1` (falso/verdadeiro) em vez do caractere lido — o programa quebraria silenciosamente. Os parênteses forçam a atribuição acontecer primeiro:

```c
(c = getchar()) != EOF
```

Primeiro lê e guarda o caractere em `c`, depois compara `c` com EOF. Esse é o comportamento correto.

