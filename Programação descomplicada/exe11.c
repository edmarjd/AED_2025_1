#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = NULL, num, i;
    int *temp = NULL;
    int capacidade = 10, new_cap, count = 0;

    array = (int *) malloc(capacidade * sizeof(int));
    if (array == NULL) {
        perror("Erro ao alocar memória inicial");
        return 1;
    }

    printf("Digite um número a ser alocado (0 para encerrar):\n");

    for (;;) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }

        if (count == capacidade) {
            new_cap = capacidade + 10;
            temp = (int *) malloc(new_cap * sizeof(int));
            if (temp == NULL) {
                perror("Erro ao expandir memória");
                free(array);
                return 1;
            }

           
            for (i = 0; i < count; i++) {
                temp[i] = array[i];
            }

            free(array);           
            array = temp;          
            capacidade = new_cap;  
        }

        array[count++] = num;  
    }


    printf("Os valores lidos são:\n");
    for (i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);  
    return 0;
}
