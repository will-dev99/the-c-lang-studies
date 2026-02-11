/*
Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion
*/

#include <stdio.h>

#define LOWER 0 /* limite mínimo da escala de temperatura */
#define UPPER 300 /* limite máximo */
#define STEP 20 /* tamanho do salto */

/* usei o tipo void já que a função convert
não precisa necessariamente retornar os valores,
apenas imprimir eles.
o tipo void em uma função não exige e não recebe
uma expressão return.*/
void convert(int lower, int upper, int step, int fahr);

int main()
{
     int fahr = LOWER;

     convert(LOWER, UPPER, STEP, fahr);
}

/* faz o cálculo, recebendo os valores de:
lower upper, step, fahr
todos são inteiros por sua vez, mas poderiam ser float/double.
*/
void convert(int lower, int upper, int step, int fahr)
{
    int celsius;

    while (fahr <= upper) {
         celsius = 5 * (fahr-32) / 9;
         printf("%d\t%d\n", fahr, celsius);
         fahr = fahr + step;
    }
}
