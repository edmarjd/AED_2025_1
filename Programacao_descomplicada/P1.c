#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *dados;
    int topo;
    int capacidade;
} Pilha;

Pilha *RESET(int capacidade) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->dados = (char*) malloc(capacidade * sizeof(char));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

bool EMPTY(Pilha *p) {
    return p->topo == -1;
}

bool FULL(Pilha *p) {
    return p->topo == p->capacidade - 1;
}

bool PUSH(Pilha *p, char s) {
    if (!FULL(p)) {
        p->dados[++p->topo] = s;
        return true;
    } else {
        printf("Pilha cheia!");
        return false;
    }
}

char POP(Pilha *p) {
    if (!EMPTY(p)) {
        return p->dados[p->topo--];
    } else {
        return '\0';
    }
}

void CLEAR(Pilha *p) {
    free(p->dados);
    free(p);
}

int remover(Pilha *p, char a, char b, int pontos) {
    Pilha *pAux = RESET(p->capacidade);
    int total = 0;
    for (int i = 0; i <= p->topo; i++) {
        char atual = p->dados[i];
        if (!EMPTY(pAux) && pAux->dados[pAux->topo] == a && atual == b) {
            POP(pAux);
            total += pontos;
        } else {
            (void)PUSH(pAux, atual); // CORREÇÃO AQUI
        }
    }
    p->topo = -1;
    for (int i = 0; i <= pAux->topo; i++) {
        p->dados[i] = pAux->dados[i];
    }
    p->topo = pAux->topo;
    CLEAR(pAux);
    return total;
}

int maximumGain(char* s, int x, int y) {
    int len = strlen(s);
    Pilha *p = RESET(len * 2);
    for (int i = 0; i < len; i++) {
        (void)PUSH(p, s[i]); // CORREÇÃO AQUI
    }
    int resultado = 0;
    if (x >= y) {
        resultado += remover(p, 'a', 'b', x);
        resultado += remover(p, 'b', 'a', y);
    } else {
        resultado += remover(p, 'b', 'a', y);
        resultado += remover(p, 'a', 'b', x);
    }
    CLEAR(p);
    return resultado;
}

int main() {
    char s[] = "cdbcbbaaabab";  
    int x = 4;
    int y = 5;
    int resultado = maximumGain(s, x, y);
    printf("Resultado maximo: %d\n", resultado);
    return 0;
}