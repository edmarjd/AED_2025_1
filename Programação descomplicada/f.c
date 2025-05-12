/*
5. Fac ̧a um programa que leia um numero N e:  ́
• Crie dinamicamente e leia um vetor de inteiro de N posic ̧oes;  ̃
• Leia um numero inteiro X e conte e mostre os m  ́ ultiplos desse n  ́ umero que existem  ́
no vetor.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int N, X, *array = NULL;
    int count = 0;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &N);
    printf("Digite o numero X para comparacao de multuplos no vetor:\n");
    scanf("%d", &X);

    array = (int *) malloc(N * sizeof(int));

    printf("Digite o valor de cada indice do vetor:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < N; i++) {
        if (array[i] %X == 0) {
            count++;
        }
    }

    printf("O numero de multiplos de X que existem no vetor sao: %d", count);

    free(array);
    return 0;
}