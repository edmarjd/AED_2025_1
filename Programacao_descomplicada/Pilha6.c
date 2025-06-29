/*Dado uma pilha que armazene n´umeros, escreva uma func ¸˜ ao para ordenar os valores
 da pilha em ordem crescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *dados;
    int topo;
    int capacidade;
}Pilha;

Pilha *RESET(int capacidade);
bool EMPTY(Pilha *p);
bool FULL(Pilha *p);
bool PUSH(Pilha *p, int valor);
int POP(Pilha *p);
void Listar(Pilha *p);
void CLEAR(Pilha *p);
void Ordem(Pilha *p, int valor);
void OrdemPilha(Pilha *p);

int main() {

    int vetor[5];
    
    printf("Digite os numeros para pilha:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vetor[i]);
    }

    Pilha *p = RESET(5);

    for (int i = 0 ; i < 5; i++) {
        PUSH(p, vetor[i]);
    }    

    printf("Pilha original:\n");
    Listar(p);

    OrdemPilha(p);

    printf("Pilha Ordenada:\n");
    Listar(p);

    return 0;
}

Pilha *RESET(int capacidade) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->dados = (int *) malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

bool EMPTY(Pilha *p) {
    if (p->topo == -1) {
        return true;
    } else {
        return false;
    }
}

bool FULL(Pilha *p) {
    if (p->topo == p->capacidade -1) {
        return true;
    } else {
        return false;
    }
}

bool PUSH(Pilha *p, int valor) {
    if (!FULL(p)) {
       p->dados[++p->topo] = valor;
       return true;
    } else {
        return false;
    }
}

int POP(Pilha *p) {
    if (!EMPTY(p)) {
        return p->dados[p->topo--];
    } else {
        return -1;
    }
}

void CLEAR(Pilha *p) {
    free(p->dados);
    free(p);
}

void Listar (Pilha *p) {
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

void Ordem(Pilha *p, int valor) {
    if (EMPTY(p) || p->dados[p->topo] <= valor) {
            PUSH(p, valor);
        } else {
            int temp = POP(p);
            Ordem(p, valor);
            PUSH(p, temp);
        }
}

void OrdemPilha(Pilha *p) {
    if (!EMPTY(p)) {
        int temp = POP(p);
        OrdemPilha(p);
        Ordem(p, temp);
    }
}
