## Variáveis Locais (Automáticas)

Variáveis declaradas dentro de uma função são **privadas** a ela — nenhuma outra função pode acessá-las diretamente. A variável `i` em `getline` não tem nada a ver com a variável `i` em `copy`.

Essas variáveis são chamadas de **automáticas**: elas existem apenas enquanto a função está em execução e desaparecem quando ela retorna. Por isso, **não guardam seus valores entre chamadas**.

---

## Variáveis Externas (Globais)

Variáveis externas são declaradas fora de qualquer função. Elas:

- São acessíveis por qualquer função do programa
- Persistem durante toda a execução
- Mantêm seus valores entre chamadas de função

### Regras

- **Definição** (cria a variável e aloca memória): feita **uma única vez**, fora de qualquer função
- **Declaração** (informa o tipo para a função): feita em cada função que usa a variável, com a palavra-chave `extern`
- Se a variável for definida no mesmo arquivo, o `extern` pode ser omitido — basta declarar todas as globais no topo do arquivo

### Múltiplos arquivos

Se uma variável for definida em `arquivo1.c` e usada em `arquivo2.c`, o `arquivo2.c` precisa de uma declaração `extern`. A prática comum é reunir todas essas declarações em um **arquivo de cabeçalho** (`.h`) e incluí-lo com `#include`.

---

## Exemplo — Linha mais longa com variáveis externas

```c
#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline(void);
void copy(void);

int main()
{
    int len;
    extern int max;
    extern char longest[MAXLINE];

    max = 0;

    while ((len = getline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }

    if (max > 0)
        printf("%s", longest);
}

int getline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
```

---

## Cuidado com o uso excessivo de variáveis externas

Usar globais indiscriminadamente parece conveniente, mas torna o código **difícil de entender e manter**: qualquer função pode alterar a variável de forma inesperada, e as dependências entre funções ficam ocultas.

A segunda versão do programa de "linha mais longa" é considerada **pior** que a primeira justamente por isso — e também porque amarra as funções `getline` e `copy` a nomes de variáveis específicos, destruindo sua generalidade.

---

## Definição vs. Declaração

| Termo | Significado |
|---|---|
| **Definição** | Cria a variável e aloca memória (ocorre uma vez) |
| **Declaração** | Informa o tipo à função, sem alocar memória (pode ocorrer várias vezes, com `extern`) |
