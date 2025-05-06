/*
Faca um programa que leia um vetor de 10 numeros. Leia um numero x. Conte os
 multiplos de um numero inteiro x num vetor e mostre-os na tela.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    int count = 0;
    int v[10], s[count], i, x;

    printf ("Digite o valor de x:\n");
    scanf ("%d", &x);

    printf("Digite os numeros de cada indice do vetor:\n");
    for (i = 0 ; i < 10; i++) {
        scanf("%d", &v[i]);
    }

    printf("Os numeros encontrados sao: ");
    for (i = 0; i < 10; i++) {
        if (v[i] % x == 0) {
            printf("%d ", v[i]);
            count++;
        }
    }

    printf("\nO total de numeros encontrados sao: %d", count);

    return 0;

}
