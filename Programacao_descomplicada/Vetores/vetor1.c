/*Faca um programa que leia um vetor de 8 posicoes e, em seguida, leia tambem dois va-
lores X e Y quaisquer correspondentes a duas posicoes no vetor. Ao final seu programa
devera escrever a soma dos valores encontrados nas respectivas posicoes X e Y*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int v[8], X, Y;

    printf("Digite os valores de cada indice do vetor:\n");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &v[i]);
    }

    printf("Digite os valores de X e Y correspondentes a posicoes do vetor(0 a 7):\n");
    scanf("%d%d", &X, &Y);

    int soma = v[X] + v[Y];

    printf("A soma dos valores encontrados nas resoectivas posicoes e: %d", soma);

    return 0;

}