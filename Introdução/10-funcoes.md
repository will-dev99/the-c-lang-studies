Uma função encapsula um cálculo: quem usa não precisa saber *como* ela funciona, só *o que* ela faz. Em C, funções são convenientes ao ponto de ser comum criar uma função pequena usada uma única vez — só para deixar o código mais claro.

---

## Exemplo: `power(base, n)`

C não tem operador de exponenciação, então vamos escrever um. `power(m, n)` eleva `m` à potência `n` (inteiros positivos pequenos — para uso geral existe `pow(x, y)` na biblioteca padrão).

```c
#include <stdio.h>

int power(int m, int n);

int main()
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}

int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;

    return p;
}
```

---

## Estrutura de uma função

```
tipo-de-retorno nome-da-função(declarações de parâmetros)
{
    declarações
    instruções
}
```

Funções podem aparecer em qualquer ordem e em um ou mais arquivos — mas nenhuma função pode ser dividida entre arquivos.

---

## Parâmetros e variáveis locais

Os nomes dos parâmetros de `power` (`base`, `n`) são locais a ela — não existem fora, e outras funções podem usar os mesmos nomes sem conflito. O mesmo vale para `i` e `p`: o `i` de `power` não tem nada a ver com o `i` de `main`.

> Os termos *argumento formal* (o parâmetro na definição) e *argumento real* (o valor passado na chamada) às vezes são usados para fazer essa distinção.

---

## `return`

```c
return expressão;
```

Devolve um valor para quem chamou a função. Uma função não é obrigada a retornar valor — um `return` sem expressão (ou chegar no `}` final) encerra a função sem retornar nada útil.

`main` também retorna um valor para o sistema operacional: `0` indica encerramento normal, qualquer outro valor indica erro.

---

## Protótipos de função

A linha antes do `main`:

```c
int power(int base, int n);
```

é o **protótipo** de `power`. Ele avisa ao compilador os tipos dos parâmetros e do retorno antes que a função seja usada. A definição e todas as chamadas precisam bater com o protótipo — caso contrário, é um erro.

Os nomes dos parâmetros no protótipo são opcionais; isso também seria válido:

```c
int power(int, int);
```

Mas nomes bem escolhidos servem como documentação, então é uma boa prática mantê-los.

---

## Nota histórica: sintaxe antiga (pré-ANSI)

Antes do ANSI C, funções eram declaradas assim:

```c
power(base, n)
int base, n;
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;

    return p;
}
```

Os tipos dos parâmetros vinham *depois* dos parênteses, e parâmetros sem tipo declarado eram assumidos como `int`. O protótipo no topo seria apenas:

```c
int power();
```

Sem lista de parâmetros, o compilador não conseguia verificar se a função estava sendo chamada corretamente. A nova sintaxe com protótipos resolve isso e é o padrão a seguir.