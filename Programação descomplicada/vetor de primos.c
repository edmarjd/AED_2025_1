/* Leia 10 numeros inteiros e armazene em um vetor. Em seguida escreva os elementos
 que sao primos e suas respectivas posicoes no vetor.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool par(int nums);

int main(){

    int valor[10];
    printf("Digite os valores de cada indice do vetor:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &valor[i]);
	}
	
	for (int i = 0; i < 10; i++){
        if (par(valor[i])) {
            printf("Numero primo %d , posicao %d\n", valor[i], i);
        } else {
            continue;
        }
    }
    return 0;
}
bool par(int nums){
    if (nums <= 1) return false;
    if (nums == 2) return true;   
    if (nums %2 == 0)return false;
        
    int ponto = sqrt(nums);
    for(int  i = 3; i <= ponto; i+= 2){
		if (nums % i == 0) {
			return false;
		}
    }
    return true;
}
