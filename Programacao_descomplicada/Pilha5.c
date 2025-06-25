/* Escreva um programa que utilize uma pilha para verificar se express˜ oes aritm´ eticas est˜ ao
 comaparentizac¸˜ ao correta. O programa deve verificar express˜ oes para ver se cada “abre
 parˆ enteses” tem um “fecha parˆ enteses” correspondente. Ex.:
 Correto: ( ( ) )– ( ( )( ) )– ( ) ( )
 Incorreto: )(– ( ( ) (– ) ) ( (
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <string.h>

typedef struct {
    char *dados;
    int capacidade;
    int topo;
}Pilha;

Pilha *RESET(int capacidade);
bool EMPTY(Pilha *p);
bool PUSH(Pilha *p, char c);
bool FULL(Pilha *p);
char POP(Pilha *p);
void CLEAR(Pilha *p);
bool Verificar(const char *str);

int main(){

    char caracter[100];

    printf("Digite a sequencia de caracteres:\n");
    fgets(caracter, 100, stdin);
    caracter[strcspn(caracter,"\n")] = '\0';

    if (Verificar(caracter)) {
        printf("A sequencia de caracteres e igual!");
    } else {
        printf("A sequencia de caracteres nao sao iguais!");
    }

    return 0;
}

Pilha *RESET(int capacidade) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->dados = (char*) malloc(capacidade *sizeof(char));
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


bool PUSH(Pilha *p, char c) {
    if (!FULL(p)) {
        p->dados[p->topo++] = c;
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

bool Verificar(const char *str) {

    int len = strlen(str);
    Pilha *p = RESET(len);
    
    for (int i = 0; i < len; i++) {
        char c = str[i];

        if (c == '(') {
            PUSH(p, c);

        } else if (c == ')') {
            if (EMPTY(p)) {
                CLEAR(p);
                return false;
            }

            POP(p);
        }
    }

    bool resultdado = EMPTY(p);
    CLEAR(p);
    return resultdado;
}