- Um dos aspectos de funções em C pode não ser familiar para quem está acostumado com outras linguagens. Em C, todos os argumentos de funções são passados `por valor`. Isso significa que a função chamada recebe os valores de seus argumentos em variáveis temporárias, em vez das originais. Isso leva a algumas propriedades diferentes das observadas nas linguagens de *chamada por referência*.
- Chamadas por valor é um ativo, não um passivo. Usualmente, isso leva a programas mais compactos, com menos variáveis estranhas, já que parâmetros podem ser tratados como variáveis locais convenientemente inicializadas na rotina. Por exemplo, aqui está uma versão de **power** que usa esse conceito:

```c
int power(int base, int n)
{
    int p;
    
    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}
```

- A variável **n** é usada como uma variável temporária, e é contada em ordem decrescente (um *loop for* que anda para trás) até se tornar 0; não tem mais necessidade de uma variável i. Qualquer coisa que é feita com **n** dentro da função **power** não tem efeito no argumento que **power** originalmente foi chamado com.
- Quando necessário, é possível configurar uma função para modificar uma variável em uma rotina de chamada. O chamador deve passar o *endereço* da váriavel para modificação (um ponteiro para a variável) e a função chamada deve declarar o parâmetro como um ponteiro e acessar a variável indiretamente por meio dele. Veremos ponteiros mais tarde.