/*Crie um programa que compara duas strings (nao use a funcao strcmp).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nome1[10], nome2[10];

    printf("Digite o primeiro nome:\n");
    fgets(nome1, 10, stdin);
    nome1[strcspn(nome1, "\n")] = '\0';

    printf("Digite o primeiro nome:\n");
    fgets(nome2, 10, stdin);
    nome2[strcspn(nome2, "\n")] = '\0';

    int iguais = 1;

    for(int i = 0; nome1[i] != '\0' || nome2[i] != '\0'; i++){
        if(nome1[i] != nome2[i]){
            iguais = 0;
            break;
        }

    }
    
    if(iguais){
            printf("\nIGUAIS!");
        }else{
            printf("FALSO!");
    }
    

    return 0;
}
