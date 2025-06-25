/*Faca um programa que leia uma palavra (maximo de 50 letras) e some 1 no valor ASCII
de cada caractere da palavra. Imprima a string resultante.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char palavra[51];

    printf("Digite a palavra:\n");

    fgets(palavra, 51, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    for (int i = 0; i < strlen(palavra); i++) {
        palavra[i] += 1;
    }

    printf("A palavra modificada e: %s", palavra);
    return 0;

}