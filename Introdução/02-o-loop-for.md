## Versão compacta do conversor de temperatura

```c
#include <stdio.h>

int main()
{
    for (int fahr = 0; fahr <= 300; fahr += 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

Produz a mesma saída que a versão anterior, mas sem variáveis auxiliares — `lower`, `upper` e `step` viraram constantes direto no `for`. O cálculo da temperatura em Celsius também foi movido para dentro do `printf`, o que é válido porque o `printf` aceita qualquer expressão `float` onde espera um `%6.1f`.

Essa é uma regra geral em C: onde um valor de certo tipo é esperado, uma expressão que resulte nesse tipo também funciona.

---

## Estrutura do `for`

```c
for (inicialização; condição; incremento)
    corpo;
```

| Parte | O que faz | Quando executa |
|---|---|---|
| `fahr = 0` | inicialização | uma única vez, antes do loop |
| `fahr <= 300` | condição | antes de cada iteração |
| `fahr += 20` | incremento | após cada iteração |

Se a condição for falsa logo de início, o corpo nunca executa. O corpo pode ser uma única instrução ou um bloco entre `{ }`.

---

## `for` vs `while`

O `for` é uma generalização do `while` — tudo que um faz, o outro também consegue. A escolha é questão de clareza: quando inicialização, condição e incremento são logicamente ligados e simples, o `for` é mais compacto e mantém o controle do loop em um único lugar.
