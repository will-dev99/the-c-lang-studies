Programa que exibe uma tabela de Fahrenheit (0 a 300, de 20 em 20) com os equivalentes em Celsius usando a fórmula `°C = (5/9) * (°F - 32)`.

```c
#include <stdio.h>

/* exibe tabela fahrenheit-celsius
   para fahr = 0, 20, ..., 300 */

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step  = 20;

    fahr = lower;

    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

---

## Comentários

Qualquer coisa entre `/*` e `*/` é ignorada pelo compilador. Use à vontade para explicar o que o código faz.

---

## Declaração de variáveis

Em C, toda variável precisa ser declarada antes de ser usada, geralmente no início da função:

```c
int fahr, celsius;
int lower, upper, step;
```

A declaração informa o nome e o tipo da variável.

---

## Tipos básicos

| Tipo | O que armazena |
|---|---|
| `int` | números inteiros |
| `float` | números com parte fracionária (ex: `3.14`) |
| `char` | um único caractere (1 byte) |
| `short` | inteiro curto |
| `long` | inteiro longo |
| `double` | ponto flutuante de dupla precisão |

O tamanho exato de cada tipo depende da máquina. Como referência comum: `int` de 16 bits vai de −32.768 a +32.767; `float` de 32 bits tem cerca de 6 dígitos significativos e suporta magnitudes entre −10³⁸ e +10³⁸.

Além dos tipos básicos, C também tem arrays, structs, unions, ponteiros e funções — isso fica para mais adiante.

---

## O loop `while`

```c
while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
}
```

O `while` testa a condição **antes** de cada iteração. Se for verdadeira, executa o corpo; quando ficar falsa, encerra. O corpo pode ter várias instruções entre `{ }` ou uma única instrução sem chaves:

```c
while (i < j)
    i = 2 * i;
```

---

## Estilo e indentação

O compilador não liga para espaços ou indentação, mas boas práticas fazem o código muito mais legível:

- Uma instrução por linha
- Indentar o corpo do loop (4 espaços ou 1 tab)
- Espaços em volta dos operadores para indicar agrupamento
- Posição das chaves: escolha um estilo e seja consistente

---

## Por que `5 * (fahr - 32) / 9` e não `(5/9) * (fahr - 32)`?

Em C, a divisão entre dois `int` **trunca** a parte fracionária. `5/9` resultaria em `0`, e todas as temperaturas em Celsius sairiam como `0`. Multiplicar por `5` primeiro e dividir por `9` depois contorna o problema.

---

## Formatando a saída com `printf`

`printf` exibe os argumentos no lugar de cada `%`, na ordem. `%d` é para inteiro, `\t` insere uma tabulação, `\n` quebra a linha:

```c
printf("%d\t%d\n", fahr, celsius);
```

Para alinhar os números na saída, adiciona-se uma largura mínima:

```c
printf("%3d %6d\n", fahr, celsius);
```

```
  0    -17
 20     -6
 40      4
...
300    148
```

---

## Versão com `float` — resultados precisos

Com `int`, `0°F` aparece como `-17°C` em vez de `-17.8°C`. Usando `float` os resultados ficam corretos:

```c
#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step  = 20;

    fahr = lower;

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

Agora `5.0 / 9.0` não trunca. Quando uma operação mistura `float` e `int`, o inteiro é convertido automaticamente para `float` — por isso `fahr - 32` funciona sem problemas (o `32` vira `32.0`).

Escrever `5.0` em vez de `5`, mesmo sendo o mesmo valor, deixa explícito para quem lê que se trata de um float.

---

## Especificadores de formato do `printf`

| Especificador | Significado |
|---|---|
| `%d` | inteiro |
| `%6d` | inteiro, mínimo 6 caracteres de largura |
| `%f` | float |
| `%6f` | float, mínimo 6 caracteres de largura |
| `%.2f` | float, 2 casas decimais |
| `%6.2f` | float, mínimo 6 de largura e 2 casas decimais |
| `%3.0f` | float, mínimo 3 de largura, sem casas decimais |
| `%o` | octal |
| `%x` | hexadecimal |
| `%c` | caractere |
| `%s` | string |
| `%%` | o próprio `%` |
