/*
Escreva um programa que recebe do usu ´ario uma string S, um caractere C, e uma
posic¸ ˜ao I e devolve o ´ındice da primeira posic¸ ˜ao da string onde foi encontrado o caractere
C. A procura deve comec¸ar a partir da posic¸ ˜ao I.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char S[100], c;
    int i;

    printf("Digite a string 'S' :\n");
    fgets(S, sizeof(S), stdin);

    printf("Digite o caracter: \n");
    scanf("%c", &c);

    printf("Digite o indice para começo de procura:\n");
    scanf("%d", &i);

    int j;
    int valor;

    for (j = i; j < strlen(S); j++ ){
        if (S[j] == c) {
            valor = j;
            break;
        }
    }

    printf("O indice em que o caracter e encontrado na string e: %d", valor);

    return 0;
}