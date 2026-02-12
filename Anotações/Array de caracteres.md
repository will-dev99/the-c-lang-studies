- O tipo mais comum de arrays em C é o array de caracteres. Para ilustrar o uso de arrays de caracteres e funções para os manipular, vamos escrever um programa que lê uma série de linhas de texto e exibe o mais longo. O esboço é simples:

```c
enquanto(existir outra linha)
    se(for maior que a maior linha anterior)
        (salve ela)
        (salve o seu tamanho)
    
exibir maior linha
```

- Este esboço deixa claro que o programa se divide naturalmente em partes. Uma parte recebe uma nova linha, outra a guarda e o resto controla o processo.
- Já que as coisas se dividem de maneira organizada, seria bom escrevê-las dessa mesma forma. Em ordem, vamos primeiro escrever uma função separada **getline** para buscar a próxima linha da entrada. Tentaremos fazer a função ser útil em outros contextos. No minimo, **getline** deve retornar um sinal do possível fim de arquivo; um design mais útil seria retornar o tamanho da linha ou zero se o fim do arquivo for encontrado. Zero é um valor aceitável para retornar EOF porque nunca é um comprimento de linha válido. Toda linha de texto tem ao menos um caractere; até mesmo uma linha contendo um newline (\n) possui 1 caractere.
- Quando encontrarmos uma linha que é maior que a maior linha anterior, deveremos guardá-la em algum lugar. Isso sugere uma segunda função, **copy**, para copiar a linha para um lugar seguro.
- E finalmente, precisamos de um programa para controlar **getline** e **copy**:

```c
#include <stdio.h>
#define MAXLINE 1000 /* tamanho máximo de uma linha da entrada. */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* Exibe a maior linha da entrada */
int main()
{
    int len; /* tamanho da linha atual */
    int max; /* tamanho máximo visto até então */
    char line[MAXLINE]; /* Atual linha da entrada */
    char longest[MAXLINE]; /* maior linha é salva aqui */
    
    max = 0;
    
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* tinha uma linha */
        printf("%s", longest);
    return 0;
}

/* lê uma linha em s, retorna o comprimento */
int get_line(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copia 'from' para 'into'; assumindo que 'to' é grande o suficiente. */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    
    while ((to[i] = from[i]) != '\0')
        ++i;
}
```

- As funcoes **getline** e **copy** são declaradas no início do programa, que nós assumimos que está em um arquivo.
- **main** e **getline** se comunicam através de um par de argumentos e um valor retornado. Em **getline**, os argumentos são declarados pela linha:


```c
int getline(char s[] int lim);
```

- Esse trecho especifica que o primeiro argumento **s** é um array, e o segundo argumento **lim** é um inteiro. O objetivo de fornecer o tamanho de um array numa declaração é reservar espaço de armazenamento. O comprimento do array **s** não é necessário em **getline** já que o seu tamanho é especificado na **main**. **getline** usa um return para enviar um valor de volta a quem o chamou, assim como a função **power** fez. Essa linha também declara que **getline** retorna um valor inteiro; já que **int** é o valor padrão de retorno, poderia ser omitido.
- Algumas funções retornam valores que podem ser úteis, já outra, como **copy**, são usadas apenas para seu efeito e não retornam nenhum valor. O tipo de retorno de **copy** é *void*, que declara explicitamente que nenhum valor é retornado.

- **getline** coloca o caractere `'\0'` (o caractere nulo, de valor 0) no final do array que está criando, para marcar o fim da string caracteres. Essa conversão também é usada pela linguagem C; quando uma string constante como: "hello\n" aparece em um programa C, ela é armazenada em um array de caracteres contendo os caracteres na string e é terminado com um `'\0'` para sinalizar o fim: "hello\n\0"

- A especificação de formato %s no printf espera que o argumento correspondente seja uma string representada em sua forma. **copy** também depende no fato de que seu argumento de entrada é finalizado com um '\0', e copia esse caractere para a saída.

- Vale a pena mencionar de passagem que mesmo um programa tão pequeno como este apresenta alguns problemas de design complicados. Por exemplo, o que o **main** deveria fazer se encontrar uma linha maior que o seu limite? O **getline** funciona com segurança, já que para de recolher quando o array está cheio, mesmo que nenhuma outra linha tenha sido vista. Ao testar o comprimento e o último caractere retornado, o main pode determinar se a linha era muito longa e, então, lidar com isso como desejar. Por uma questão de brevidade, ignoramos isso.

- Não tem uma forma do usuário de **getline** saber anteriormente quão longo uma linha de entrada deve ser, então **getline** checa por estouro. Por outro lado, o usuário de **copy** já sabe (ou pode descobrir) quão longo as strings são, então decidimos não adicionar checagem de erros para ele.