#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int n;
    char nome[20], temp[20];
    char name[20];

    
    do{

        printf("\n-----------MENU----------\n1.Adicionar nome\n2.Remover nome\n3.Listar nome\n4.Sair\n");
        printf("\nDigite uma opcao do menu:\n");
        scanf("%d", &n);

        switch(n){
    
            case 1:
            printf("Digite o nome: ");
            scanf("%s", temp);
            while(getchar() != '\n');

            strcat(nome, temp);
                
            break;

            case 2:

            printf("Insira o nome que desejas remover:\n");
            scanf("%s", name);
            while(getchar () != '\n');

            if(strcmp(name, nome) == 0){
                nome[0] = '\0';
            }

            break;

            case 3:

            printf("%s", nome);

            break;

            case 4:
            break;
        }

    }while(n != 4);
}