/*Considere uma pilha que armazene caracteres. Escreva uma funcao que verifique se
 uma palavra e um palındromo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *dados;
    int capacidade;
    int topo;
}Pilha;

Pilha *RESET(int capacidade);
bool EMPTY(Pilha *p);
bool FULL(Pilha *p);
bool PUSH(Pilha *p, char str);
char POP(Pilha *p);
void CLEAR(Pilha *p);
bool ehPalidromo(const char *palavra);

int main() {

    char palavra[200];

    printf("Digete a palavra para saber se e um polidromo:\n");
    fgets(palavra, 200, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    if (ehPalidromo(palavra)) {
        printf("E um palidromo!");
    } else {
        printf("Nao e um palidromo!");
    }

    return 0;

}

Pilha *RESET(int capacidade) {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->dados = (char *) malloc (capacidade * sizeof(int));
    p->capacidade = capacidade;
    p->topo = -1;

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
    if (p->topo == p->capacidade) {
        return true;
    } else {
        return false;
    }
}

bool PUSH(Pilha *p, char str) {
    if(!FULL(p)) {
        p->dados[p->topo++] = str;
        return true;
    } else {
        return false;
    }
}

char POP(Pilha *p) {
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

bool ehPalidromo(const char *palavra) {
    int len = strlen(palavra);

    Pilha *p = RESET(len);

    for (int i = 0; i < len; i++) {
        PUSH(p, palavra[i]);
    }

    for (int i = 0; i < len; i++) {
        if (palavra[i] != POP(p)) {
            CLEAR(p);
            return false;
        }
    }

    CLEAR(p);
    return true;
}