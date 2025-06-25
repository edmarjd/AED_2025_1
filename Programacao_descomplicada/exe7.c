/*Fac ̧a um programa que simule a memoria de um computador: o usu  ́ ario ir  ́ a especificar o  ́
tamanho da memoria, ou seja, quantos bytes ser  ́ ao alocados do tipo inteiro. Para tanto,  ̃
a memoria solicitada deve ser um valor m  ́ ultiplo do tamanho do tipo inteiro. Em seguida,  ́
o usuario ter  ́ a 2 opc ̧  ́ oes: inserir um valor em uma determinada posic ̧  ̃ ao ou consultar o  ̃
valor contido em uma determinada posic ̧ao. A mem  ̃ oria deve iniciar com todos os dados  ́
zerados.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *array = NULL, tamanho;
    int op;

    do{
        printf("Insira o tamanho da memoria que pretendes alocar:\n");
        scanf("%d", &tamanho);

        if (tamanho %sizeof(int) != 0) {
            printf("Nao e multiplo de %d\n", sizeof(int));
            continue;
        }

    }while(tamanho %sizeof(int) != 0);

    int num_int = tamanho / sizeof(int);

    array = (int *) calloc(num_int , sizeof(int));


    do{
        printf("\n-------MENU-------\n");
        printf("\n1.Inserir um valor em uma posicao do array\n2.Consultar o valor de uma determinada posicao\n3.Sair\n");
        printf("\nDigite a opcao\n");
        scanf("%d", &op);

        switch(op){
            case 1:{
                int n, valor;

                do{
                    printf("Digite a posicao da memoria que desejas inserir dados:\n");
                    scanf("%d", &n);
                    if (n < 0 || n > num_int) {
                        printf ("Posicao invalida insira um valor entre (0 a %d)", num_int - 1);
                        continue;
                    }
                }while(n < 0 || n > num_int);

                printf("Digite o valor a ser inserirdo:\n");
                scanf("%d", &valor);
                array[n] = valor;
                printf("Valor armazenado!\n");
                break;
            }

            case 2: {
                int j;

                do{
                    printf("Digite a posicao (0 a %d)\n", num_int -1);
                    scanf("%d", &j);

                    if (j < 0 || j > num_int) {
                        printf("Posicao invalida, digite uma entre (0 a %d)\n", num_int - 1);
                        continue;
                    }

                }while(j < 0 || j > num_int);
                printf("O valor da posicao %d , e %d ", j, array[j]);
                break;

            }
            

            case 3: {
                printf("Encerrado!\n");
                break;
            }

            default:
            printf("Insira o valor de uma das opcoes do MENU\n");
            break;
        }

    }while(op != 3);

    free(array);

    return 0;
}