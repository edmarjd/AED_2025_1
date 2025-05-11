/*Escreva um programa que substitui as ocorr ˆencias de um caractere ‘0’ em uma string por
outro caractere ‘1’.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char name[100];

    printf("Digite os caracteres da string:\n");
    fgets(name, sizeof(name), stdin);

    printf("%s ", name);


    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '0') {
            name[i] = '1';
        }
    }

    printf("%s ", name);

    return 0;
}