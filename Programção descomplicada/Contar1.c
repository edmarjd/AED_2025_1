/*
Faca um programa que conte o numero de 1’s que aparecem em um string. Exemplo:
“0011001” -> 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nome[100];
    int count = 0;
    
    printf("Digite a palavra:\n");
	fgets(nome, sizeof(nome), stdin);

    for (int i = 0 ; nome[i] != '\0'; i++) {
        if (nome[i] == '1') {
            count++;
        }
    }

    printf("O numero de 1's e: %d", count);
}
