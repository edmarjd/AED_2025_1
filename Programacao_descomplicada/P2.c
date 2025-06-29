#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    char *dados;
    //int x;
    //int y;
    int topo;
    int capacidade;
}Pilha;

Pilha *RESET(int capacidade) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->dados = (char*) malloc(capacidade * sizeof(char));
    //p->x = 4;
    //p->y = 5;
    p->topo = -1;
    p->capacidade = capacidade;

    return p;
}

bool EMPTY(Pilha *p) {

    if(p->topo == -1) {
        return true;

    } else {

        return false;
    }
}

bool FULL (Pilha *p) {
    if(p->topo == p->capacidade - 1) {
        return true;
    } else {
        return false;
    }
}

bool PUSH (Pilha *p, char s) {
    if (!FULL(p)) {
        p->dados[++p->topo] = s;
        return true;
    } else {
        printf("Pilha cheia!");
        return false;
    }
}

char POP (Pilha *p) {

    if (!EMPTY(p)) {
      return p->dados[--p->topo];
    } else {
        return '\0';
    }
}

void CLEAR(Pilha *p) {
    free(p->dados);
    free(p);
}

int maximumGain(char* s, int x, int y) {
    int len = strlen (s);

    x = 4;
    y = 5;
    Pilha *p = RESET(len * 2);

    for (int i = 0; i < len; i++) {
        PUSH(p, s[i]);
    }

    int resultado;
    while (!EMPTY(p)) {

        char c = POP(p);
        char v = POP(p);

        if (c != 'a' || c != 'b' ) {
            break;

        }
        if ((c == 'a' || c == 'b') && (v !='a' || v != 'b' )) {
            break;

        }
        if (c == 'a' && v == 'b') {
            resultado += x ;

        } else if (c == 'b' && v == 'a') {
            resultado += y;
        }
    }


    CLEAR (p);
    return resultado;
}