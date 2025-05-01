/*Escreva o menu de opcoes abaixo. Leia a opcao do usuario e execute a operacao esco
lhida. Escreva uma mensagem de erro se a opc ao for invalida.
 Escolha a opcao:
 1- Soma de 2 numeros.
 2- Diferenca entre 2 numeros (maior pelo menor).
 3- Produto entre 2 numeros.
 4- Divisao entre 2 numeros (o denominador n~ao pode ser zero).
 Opc~a*/
#include <stdio.h>
#include <stdlib.h>

 int main(){

    int op;
    float n1, n2;
    float soma, div, sub, pro;


    printf("Insira os valores dos dois numeros: ");
    scanf("%f%f", &n1,&n2);

    do{

        printf("\n--------MENU--------\n");
        printf("\n1- Soma de 2 numeros\n");
        printf("\n2- Diferenca entre 2 numeros (maior pelo menor)\n");
        printf("\n3- Produto entre 2 numeros.\n");
        printf("\n4- Divis~ao entre 2 numeros (o denominador n~ao pode ser zero)\n");
        printf("\nOpcao:\n");
        scanf("%d", &op);

        switch(op){

            case 1:
            soma = n1 + n2;
            printf("\nA soma dos dois numeros e: %.2f\n", soma);

            break;

            case 2:
            if(n1 > n2){
                sub = n1 - n2;
                printf("\nA diferenca e: %.2f\n", sub);
            }else{
                sub = n2 - n1;
                printf("\nA diferenca e: %.2f\n", sub);
            }
            break;

            case 3:
            pro = n1 * n2;
            printf("\nO produto entre dois numeros e: %.2f\n", pro);
            break;

            case 4:
            if(n2 == 0 ){
                printf("O demoninador nao pode ser zero!");
                break;
            }else{
                div = n1/n2;
                printf("\nA divisao entre os dois numeros e: %.2f\n", div);
            }

        }


    }while(op != 4);

    return 0;    
}

   
