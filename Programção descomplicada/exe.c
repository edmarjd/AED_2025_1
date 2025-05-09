/*
Leia 10 n ´umeros inteiros e armazene em um vetor v. Crie dois novos vetores v1 e v2.
Copie os valores ´ımpares de v para v1, e os valores pares de v para v2. Note que cada
um dos vetores v1 e v2 t ˆem no m ´aximo 10 elementos, mas nem todos os elementos s ˜ao
utilizados. No final escreva os elementos UTILIZADOS de v1 e v2.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int v[10], v1[10], v2[10], i, count1 = 0, count2 = 0;

    printf("Digite os numeros de cada celula do vetor:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
    }

    for (i = 0; i < 10; i++) {
        if (v[i] %2 != 0) {
            v1[count1] = v[i];
            count1++;

        } if ( v[i] %2 == 0) {
            v2[count2] = v[i];
            count2++;
        }
    }

    printf("Os valores impares do vetor sao: ");
    for (i = 0; i < count1; i++) {
        printf("%d ", v1[i]);
    }

    printf("\nOs valores pares do vetor sao: ");
    for (i = 0 ; i < count2; i++) {
        printf("%d ", v2[i]);
    }

    return 0;
}