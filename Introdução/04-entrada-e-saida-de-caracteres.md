## Fluxo de texto

A biblioteca padrão de C trata toda entrada e saída como um **fluxo de texto**: uma sequência de caracteres organizada em linhas, onde cada linha termina com `\n`. Não importa se a entrada vem do teclado, de um arquivo ou de outro programa — o modelo é sempre o mesmo. O programador não precisa se preocupar com como as linhas são representadas internamente.

---

## `getchar` e `putchar`

As funções mais simples para lidar com esse fluxo são `getchar` e `putchar`.

**`getchar`** lê o próximo caractere da entrada e retorna seu valor:

```c
c = getchar();
```

Após essa linha, `c` contém o próximo caractere digitado (ou lido do arquivo).

**`putchar`** exibe um caractere na saída:

```c
putchar(c);
```

Exibe o conteúdo de `c` como um caractere. Chamadas a `putchar` e `printf` podem ser misturadas — a saída aparece na ordem em que as chamadas acontecem.