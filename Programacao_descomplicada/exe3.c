/*Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros,  ́
(b) Pec ̧a para o usuario digitar os 5 n  ́ umeros no espac ̧o alocado,  ́
(c) Mostre na tela os 5 numeros,  ́
(d) Libere a memoria alocada.  ́
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *array;
        
    array = (int *) malloc(5 * sizeof(int));

    printf("Digite os 5 numeros para serem alocados:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }

    printf("Os 5 numeros alocados sao: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    free(array);

    array = NULL;

    return 0;    
}