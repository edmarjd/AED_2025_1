/* Faca um programa que receba do usuario o tamanho de uma string e chame uma  ́
funcao para alocar dinamicamente essa string. Em seguida, o usu  ̃ ario dever  ́ a informar o  ́
conteudo dessa string. O programa imprime a string sem suas vogais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Alocc (int x, char **array);

int main() {
    char *str = NULL;
    int n, j = 0;
    char v[] = "aeiouAEIOU";

    printf("Digite o tamanho da String:\n");
    scanf("%d", &n);
    getchar();

    Alocc(n, &str);

    printf("Digite o conteudo da string:\n");
    fgets(str, n, stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if(strchr(v, str[i]) == NULL) {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';

    printf("%s", str);
    free(str);
    return 0;
}

void Alocc (int x, char **array){
    *array = (char *) malloc(x * sizeof(char));
}