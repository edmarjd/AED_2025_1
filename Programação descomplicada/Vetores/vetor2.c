/*Fac¸a um programa que preencha um vetor com 10 n ´umeros reais, calcule e mostre a
quantidade de n ´umeros negativos e a soma dos n ´umeros positivos desse vetor.*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int X[10], count = 0, soma = 0;

    printf("Preencha o vetor:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &X[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (X[i] < 0) {
            count++;
        } else {
            soma += X[i];
        }
    }

    printf("A quantidade de numeros negativos no vetor e: %d", count);
    printf("\nA soma da quantidade de numeros positivos no vetor e: %d", soma);

    return 0;
}