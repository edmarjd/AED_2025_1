/*Crie um programa que l ˆe 6 valores inteiros pares e, em seguida, mostre na tela os valores
lidos na ordem inversa.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int v[6];

    printf("Le 6 numeros pares:\n");
    for (int i = 0; i < 6; i++) {
        do{
            scanf("%d", &v[i]);
            if ( v[i] %2 != 0) {
                printf("Numero impar, digite um par!\n");
                continue;
            }

        }while(v[i] %2 != 0);
    }

    
    printf("Valores lidos de forma inversa:\n");
    for (int i = 5; i >= 0; i--) {
        printf("%d ", v[i]);
    }

    return 0;
}