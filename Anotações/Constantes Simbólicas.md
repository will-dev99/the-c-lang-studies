- Uma observação final antes de sairmos do programa de conversão de temperatura para sempre. Não é uma boa prática tirar "números mágicos" como 300 e 20 em um programa; eles possuem pouca informação para alguém que está lendo o código por fora sem contexto, e também são difíceis de mudar de uma forma sistemática. Uma maneira de lidar com números mágicos é dar-lhes nomes significativos. Uma linha #define define um nome simbólico ou constante simbólica como uma sequência específica de caracteres:

```c
#define name replacement list
```

- Posteriormente, qualquer ocorrência de *name* (não entre aspas ou parte de outro nome) será substituída pelo texto *replacement* correspondente. O *name* tem a mesma forma de uma variável: Uma sequência de letras e dígitos que começa com uma letra. O texto *replacement* pode ser qualquer sequência de caracteres; não está limitado apenas a números.

```C
#include <stdio.h>

#define LOWER 0 /* limite mínimo da tabela */
#define UPPER 300 /* limite máximo */
#define STEP 20 /* tamanho do salto */

int main()
{
    for (int fahr = 0; fahr <= UPPER; fahr += STEP) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}
```
- **LOWER**, **UPPER** e **STEP** não são variáveis, são constantes simbólicas, então elas não aparecem em declarações. Nomes de constantes simbólicas são escritos em maiúsculo por conveniência para que elas possam ser distinguidas com mais facilidade de nomes de variáveis em minúsculo. Note que não existe um ponto e vírgula (;) no fim de um #define, não é necessário.
