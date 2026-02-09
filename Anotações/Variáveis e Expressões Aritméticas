- O programa abaixo usa a fórmula °C = (5 / 9) * (°F - 32) para exibir uma tabela de temperaturas Fahrenheit de 0 a 300 com um salto de 20 e os seus equivalentes em graus centígrados ou celsius.

```c
#include <stdio.h>

/* print fahrenheit - celsius table 
    for fahr = 0, 20, ..., 300 */

int main()
{
    int fahr, celsius;
    int lower, upper, step;
    
    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    
    fahr = lower;
    
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

- As duas linhas:
- 
  /* print fahrenheit - celsius table 
    for fahr = 0, 20, ..., 30*0 */
    
- São comentários, que nesse caso, explicam brevemente o que o programa faz, qualquer caractere entre um /* Caracter*e */* é ignorado pelo compilador. Eles servem e podem ser usados livremente para explicar a funcionalidade do código.

- Em C, todas as variáveis devem ser declaradas antes de serem usadas, geralmente no começo da função antes de qualquer trecho de código executar. Uma declaração anuncia as propriedades de uma variável, consiste em um nome e uma lista de variáveis, assim como;

  int fahr, celsius;
  int lower, upper, step;
  
- O tipo **int** significa que as variáveis listadas são inteiras, armazenam apenas números inteiros. Em contraste, existe o **float**, que significa ponto flutuante, números com uma parte fracionária, como 10.5, 11.2, 5.5, 18.5, 67.67
- O alcance de **int** e **float** depende da máquina em que você está usando.
- Inteiros de 16-bits tem alcance de -32768 até +32767.
- Floats tipicamente são 32-bit, com ao menos seis dígitos significantes e magnitude geralmente entre -10³⁸ até +10³⁸

- C disponibiliza vários outros tipos de dados além de **int** e **float**, esses são:

- **char** -> Caractere (Um único byte)
- **short** -> Inteiro curto
- **long** -> Inteiro longo
- **double** -> Float de dupla precisão 

- O tamanho desses objetos também dependem da máquina. Também existem *arrays*, *structures* e *unions* desses tipos básicos, *ponteiros* para eles e *funções* que os retornam.

- O cálculo no programa de conversão de temperatura começa quando atribuímos valores as variáveis lower (0), upper (300) e step (20).
- Cada linha da tabela é calculado da mesma forma, então usamos um *loop* que se repete uma vez por linha de saída; esse é o propósito do *loop while*

```c
while (fahr <= upper) {
    /* ... */
}
```

- O *loop while* opera da seguinte maneira: A condição entre os parenteses é testada. Se for verdadeira (fahr é menor OU igual a upper), o corpo do loop (o que está dentro das chaves {}) é executado. Então a condição é testada mais uma vez, se for verdadeira, o corpo do loop é executado mais uma vez. Quando o teste vira falso (fahr é maior que upper), o loop encerra e a execução do programa continua fora do loop. Como não existem mais declarações após o loop neste programa, ele apenas encerra.

- O corpo de um loop while pode conter uma ou mais declarações dentro dos parenteses, como no conversor de temperaturas, ou uma única declaração sem as chaves:

```c
while (i < j)
    i = 2 * i
```

- Em ambos os casos, nós sempre indentamos as declarações controladas pelo *while* para uma tabulação (4 espaços) para que você possa ver com clareza quais declarações estão dentro do loop. A indentação da ênfase na estrutura lógica do programa. Mesmo que os compiladores da linguagem C não se importem com o visual de um programa (como ele está organizado), uma indentação e espaçamento bem feitos são críticos para a legibilidade de um programa, deixando-os mais fáceis para uma pessoa de fora entender.

- O recomendado é:

1. Apenas uma declaração por linha
2. Usando espaços em brancos em volta dos operadores para indicar agrupamento
3. A posição das chaves é menos importante, mesmo que algumas pessoas "discutam" por isso. Apenas escolha um estilo que você goste, e use-o

- A maioria do trabalho é realizado dentro do corpo do loop *while*. A temperatura em Celsius é calculada e atribuída a variável celsius pela declaração:

```c
celsius = 5 * (fahr - 32) / 9;
```

- A razão para multiplicar por 5 e dividir por 9 ao invés de apenas multiplicar por 5 / 9 é que, na linguagem C, assim como muitas outras linguagens, a divisão de números inteiros *trunca*; qualquer parte fracionária seria descartada. Como 5 e 9 são inteiros, 5 / 9 seria truncado para 0, então todas as temperaturas em Celsius seriam retornadas como 0

- O exemplo também mostra como o printf funciona. printf é uma função de formatação de saída de propósito geral. O seu primeiro argumento é uma string de caracteres a ser exibida, com cada % indicando onde um dos outros (segundo, terceiro...) argumentos estão para ser substituídos, e em qual forma eles estão para ser exibidos. Por exemplo;
- %d indica um argumento **inteiro**, então a declaração:

```c
printf("%d\t%d\n", fahr, celsius);
```

- Faz os valores de **fahr** e **celsius** serem exibidos com uma tabulação (\t) entre eles e uma quebra de linha (\n) no final.

- Cada construção % no primeiro argumento do printf é emparelhado com o segundo argumento correspondente, terceiro argumento, etc.; Eles devem combinar adequadamente por número e tipo, ou você receberá respostas erradas.

- Existem alguns problemas no programa de conversão de temperaturas. O mais simples é que a saída não é tão agradável visualmente já que os números não estão bem posicionados. Isso é fácil de resolver; se aumentarmos cada %d na instrução printf com uma largura, os números serão colocados devidamente em seus lugares e alinhados.
```c
printf("%3d %6d\n", fahr, celsius);

/* Saída:
  0    -17
 20     -6
 40      4
 60     15
 80     26
100     37
120     48
140     60
160     71
180     82
200     93
220    104
240    115
260    126
280    137
300    148
*/
```

- Um outro problema, esse é ainda mais sério já que usamos números inteiros, a temperatura em Celsius não está correta. 0°F é -17.8°C, não -17. Para resolvermos isso e conseguir respostas mais corretas, alteramos os valores das variáveis no programa para float e alteramos também devidamente as chamadas do printf:

```c
#include <stdio.h>

/* print fahrenheit - celsius table 
    for fahr = 0, 20, ..., 300 */

int main()
{
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    
    fahr = lower;
    
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

- Este programa, é bem parecido com o anterior, a única diferença significativa são os tipos das variáveis e a forma com que o printf chama eles. Também a fórmula é escrita de uma forma mais natural, já que agora como os números aceitam partes fracionárias, o programa não vai truncar e removê-las

- Se um operador aritmético possui operandos **int**, uma operação aritmética inteira é executada. Se um operador aritmético possui um operando **float** e um operando **int**, o inteiro será convertido para **float** antes da operação ser completada. Por isso, (fahr - 32) não deu qualquer tipo de erro, o 32 foi automaticamente convertido para 32.0.
- No entanto, escrever constantes de ponto flutuante com pontos decimais explícitos, mesmo quando têm valores inteiros, enfatiza sua natureza para leitura humana.

- O %3.0f no printf diz que um número **float** (nesse caso, **fahr**), deve ser imprimido com ao menos 3 caracteres de largura, sem um ponto decimal e sem dígitos fracionários. %6.1f diz que um número **float** (nesse caso, **celsius**) deve ser imprimido com ao menos 6 caracteres de largura, com um ponto decimal e um dígito após o ponto decimal.

- Largura e precisão podem ser omitidas de uma especificação: %6f diz que o número precisa ter no mínimo 6 caracteres de largura; %.2f específica dois caracteres após o ponto decimal (67.67, exemplo), mas a largura não é restringida, e %f apenas indica para exibir o número como um **float**

```txt
%6d -> Exibe um inteiro, com pelo menos 6 caracteres de largura
%f -> Exibe um float
%6f -> Exibe um float, com pelo menos 6 caracteres de largura
%.2f -> Exibe um float, com 2 números após o ponto decimal
%6f.2f -> Exibe um float, com pelo menos 6 caracteres de largura e 2 números após o ponto decimal
```

- Junto a outros, printf também reconhece %o para octal, %x para hexadecimal, %c para caractere, %s para uma string de caracteres, `%%` para ele mesmo
