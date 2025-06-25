/*9. Fac ̧a um programa que leia uma quantidade qualquer de numeros armazenando-os na  ́
memoria e pare a leitura quando o usu  ́ ario entrar um n  ́ umero negativo. Em seguida,  ́
imprima o vetor lido. Use a func ̧ao REALLOC.  ̃
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *array = NULL, n;
    int capacidade = 5;
    int count = 0;

    array = (int *) malloc(capacidade * sizeof(int));
    
    for (;;) {
        
        printf("Digite um numero (Se negativo para o programa) :\n");
        scanf("%d", &n);
        while ( getchar() != '\n');

        if (n < 0) {
            break;
        }

        array[count] = n;
        count++;

        if (count == capacidade) {
            capacidade *= 2;
            int *temp = (int*)realloc(array, capacidade * sizeof(int));
            array = temp;
        }

    }

    int *temp = (int *) realloc(array, count * sizeof(int));

    array = temp;

    printf("Valor lido: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }

    free(temp);
    free(array);

    return 0;
    
}