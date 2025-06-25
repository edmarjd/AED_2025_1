/*Escreva um programa que recebe uma string S e inteiros n˜ ao-negativos I e J e imprima
 o segmento S[I..J].
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S[100];
    int i, j;

    printf("Digite os caracteres para a string:\n");
    fgets(S, sizeof(S), stdin);

    printf("Digite os valores de i e j:\n");
    scanf("%d%d", &i,&j);

    printf("A string nesse segmento e: ");
    while (i <= j) {
        printf("%c", S[i]);
        i++;
    }
}