/*
8. Fac ̧a um programa para armazenar em memoria um vetor de dados contendo 1500 va-  ́
lores do tipo int, usando a func ̧ao de alocac ̧  ̃ ao din  ̃ amica de mem ˆ oria CALLOC:  ́
(a) Fac ̧a um loop e verifique se o vetor contem realmente os 1500 valores inicializados  ́
com zero (conte os 1500 zeros do vetor).
(b) Atribua para cada elemento do vetor o valor do seu  ́ındice junto a este vetor.
(c) Exibir na tela os 10 primeiros e os 10 ultimos elementos do vetor.  ́
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *array = NULL, n = 1500, count = 0;

    array = (int *) calloc (n , sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
        count++;
    }
    printf("\nO numeror de elementos do vetor e: %d", count);

    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
    printf("\n");
    printf("Os primeiros dez numeros do vetor sao: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\nOs ultimos dez numeros do vetor sao: ");
    for(int i = 1500 - 10; i < 1500; i++) {
        printf("%d ", array[i]);
    }
}