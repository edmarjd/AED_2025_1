/*Faca um programa que leia um vetor de 15 posicoes e o compacte, ou seja, elimine as
posicoes com valor zero. Para isso, todos os elementos `a frente do valor zero, devem ser
movidos uma posicao para tras no vetor.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[15];

    printf("Preencha o vetor:\n");
    for (int i = 0; i < 15; i++) {
        scanf("%d", &v[i]);
    }

    int j = 0;
    for (int i = 0; i < 15; i++) {
        if (v[i] != 0) {
           v[j] = v[i]; 
           j++;
        }
    }
    printf("\n");
    for (int i = 0; i < j; i++) {
        printf("%d ", v[i]);
    }
}