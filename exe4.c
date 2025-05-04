/* Ler nome, sexo e idade. Se sexo for feminino e idade menor que 25, imprime o nome da
 pessoa e a palavra “ACEITA”, caso contr´ ario imprimir “NAO ACEITA”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nome[20], sexo[20];
    int idade;

    printf("Digite o nome:\n");
    fgets(nome, 20, stdin);
    nome[strcspn(nome, "\n")] = '\0';

	printf("Digite o sexo:\n");
	fgets(sexo, 20, stdin);
    sexo[strcspn(sexo, "\n")] = '\0';
    

    printf("Digite a idade do induvido:\n");
    scanf("%d", &idade);

    if((strcmp(sexo, "feminino") == 0) && idade < 25){
        printf("\nA idade da pesssoa e %d e o nome e %s",idade, nome);
        printf("\nACEITA\n");
    }else{
        printf("NAO ACEITA");
    }

    return 0;
}
