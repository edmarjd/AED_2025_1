/*Faca um programa que receba uma palavra e a imprima de tras-para-frente.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char nome[11];

    printf("Digite o nome:\n");
    fgets(nome, 11, stdin);

    printf("O nome e: %s", nome);

    printf("\nO nome invertido e:");
    for (int i = strlen(nome) - 1; i >= 0; i--) {
        printf("%c", nome[i]);
    }

    return 0;
}