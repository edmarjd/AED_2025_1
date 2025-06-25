 /*Escreva um algoritmo, usando uma Pilha, que inverte as letras de cada palavra de um
 texto terminado por ponto (.) preservando a ordem das palavras. Por exemplo, dado o
 texto:
 ESTE EXERCICIO E MUITO FACIL.
 A saıda deve ser:
 ETSE OICICREXE E OTIUM LICAF*/

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <stdbool.h>

 typedef struct {
    char *dados;
    int topo;
    int capacidade;
 }Pilha;

 Pilha *RESET(int capacidade) {
    Pilha *p = (Pilha*) malloc (sizeof(Pilha));
    if (!p) {
        return NULL;
    }
    p->dados = (char*) malloc(capacidade * sizeof(char));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

bool PUSH(Pilha *p, char s) {
    if (p->topo == p->capacidade - 1) {
        return false;
    } else {
        p->dados[++p->topo] = s;
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

void Troca (Pilha *pDestino, char *frase) {
   // Pilha *auxiliar = RESET(100);

    int tam = strlen(frase);

    for (int i = 0; i < tam; i++) {

        if (frase[i] != ' ' && frase[i] != '.') {
            PUSH(pDestino, frase[i]);
        } else {
        
            while (pDestino->topo != -1) {
                printf("%c", POP(pDestino));
            }

            printf("%c", frase[i]);

        }

    }

    while (pDestino->topo != -1) {
        printf("%c", POP(pDestino));
    }
    printf("\n");
}

int main() {
    char frase[100];

    printf("Digite a frase a ser modificada:\n");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = 0;

    Pilha *pDestino = RESET(100);

    if (!pDestino) {
        printf("Erro de memoria!");
        return 1;
    }

    Troca(pDestino, frase);

    
    free(pDestino->dados);
    free(pDestino);

    return 0;

} 