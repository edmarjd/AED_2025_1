 /*Considere uma pilha que armazene caracteres. Fac ¸a uma func¸˜ ao para determinar se
 uma string ´ e da forma XY, onde X ´ e uma cadeia formada por caracteres arbitr´ arios e Y
 ´
 e o reverso de X. Por exemplo, se x = ABCD, ent˜ ao y = DCBA. Considere que x e y s˜ ao
 duas strings distintas.*/

 #include <string.h>
 #include <stdlib.h>
 #include <stdbool.h>

#define TAM_MAX 100

typedef struct {
    char dados[TAM_MAX];
    int topo;
}Pilha;

void RESET(Pilha *p) {
    p->topo = -1;
}

bool PUSH(Pilha *p, char c) {
    if (p->topo == TAM_MAX - 1) {
        return false;
    } else {
        p->topo++;
        p->dados[p->topo] = c;
        return true;
    }
}

char POP(Pilha *p) {
    if (p->topo == -1) {
        return '\0';
    } else {
        return p->dados[p->topo--];
    }
}

bool Reverso(char *str) {
    int len = strlen(str);

    if (len %2 != 0) {
        return false;
    }

    int meio = len / 2;
    Pilha p;
    RESET(&p);

    for (int i = 0; i < meio; i++) {
        PUSH(&p,str[i]);
    }

    for (int i = meio; i < len; i++) {
        if (POP(&p) != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[TAM_MAX];

    printf("Digite a string:\n");
    scanf("%s", str);

    if (Reverso(str)) {
        printf("A string e da forma XY, com Y sendo reverso de X.\n");
    } else {
        printf("A string nao e da forma XY.\n");
    }

    return 0;
}