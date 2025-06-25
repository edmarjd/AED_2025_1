/*
7. Escreva um programa que leia primeiro os 6 numeros gerados pela loteria e depois os 6  ́
numeros do seu bilhete. O programa ent  ́ ao compara quantos n  ̃ umeros o jogador acertou.  ́
Em seguida, ele aloca espac ̧o para um vetor de tamanho igual a quantidade de numeros  ́
corretos e guarda os numeros corretos nesse vetor. Finalmente, o programa exibe os  ́
numeros sorteados e os seus n  ́ umeros corretos.  ́
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int v[6], x[6], *array = NULL;
    int count = 0;
    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        v[i] = rand() %21;
    }

    printf("Digite os numeros do seu bilhete(6 numeros(de 0 a 20)):\n");
    for (int i = 0; i < 6 ; i++) {
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (v[i] == x[j]) {
                count++;
                break;
            }
        }
    }

    printf("\n%d\n", count);
    
    array = (int *) calloc(count , sizeof(int));

    int k = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (v[i] == x[j]) {
                array[k++] = v[i];
                break;
            }
        }
    }

    printf("Os numeros sorteados sao: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", v[i]);
    }
    printf("\nOs numeros corretos sao: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}

