Em C, todos os argumentos são passados **por valor**: a função recebe cópias dos valores originais em variáveis temporárias, não as variáveis em si. Isso é diferente das linguagens de *chamada por referência*, onde a função acessa diretamente as variáveis originais.

Isso é uma vantagem: parâmetros podem ser usados como variáveis locais já inicializadas, reduzindo a necessidade de variáveis extras. Um exemplo com `power`:

```c
int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}
```

Aqui `n` é decrementado diretamente no loop — sem precisar de uma variável auxiliar `i`. O `n` original de quem chamou `power` não é afetado.

Quando é necessário que a função **modifique** uma variável do chamador, passa-se o **endereço** dela (um ponteiro). A função então acessa e altera a variável indiretamente. Ponteiros são vistos mais adiante.
