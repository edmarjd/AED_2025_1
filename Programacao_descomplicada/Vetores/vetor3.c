/*Faca um programa que calcule o desvio padrao de um vetor v contendo n = 10 numeros,
onde m e a media do vetor.*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    float v[10];
    float m, soma = 0, resultado = 0, Desv;
    printf("Preencha o vetor:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%f", &v[i]);
        soma += v[i];
    }

    m = soma/10;

    for (int i = 0; i < 10; i++) {
       resultado += pow(v[i] - m, 2);
    }

    Desv = sqrt(resultado / (10 - 1));

    printf("A media do vetor e : %.2f", m);
    printf("\nO desvio padrao e: %.2f", Desv);

    return 0;
}