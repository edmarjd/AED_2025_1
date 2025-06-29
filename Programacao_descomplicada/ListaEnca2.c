/* Faca uma funcao para concatenar duas listas em uma terceira lista que devera ser retor
nada pela funcao. Nao use funcoes ja implementadas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dados;
}SDado;

typedef struct SNodo{
    SDado info;
    struct SNodo *pNext;
}SNodo;

typedef struct{
    SNodo *pFirst;
}SLista;

void InicializarLista(SLista *lista);
SNodo *CriarNodo(SDado info);
void InserirInicio(SLista *lista, SDado info);
void Lista(SLista *lista);
void LimparLista(SLista *lista);

int main() {

    SLista lista1, lista2;

    InicializarLista(&lista1);
    InicializarLista(&lista2);

    SDado d1, d2;
    
    printf("Digite o numero que seram concatenados:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &d1.dados);
        scanf("%d", &d2.dados);

        InserirInicio(&lista1, d1);
        InserirInicio(&lista2, d2);
    }

    printf("Lista 1:\n");
    Lista(&lista1);

    printf("\nLista 2:\n");
    Lista(&lista2);

    ConcatenarLista(&lista1, &lista2);

    printf("Lista concatenada:\n");
    Lista(&lista1);

    LimparLista(&lista1);
    LimparLista(&lista2);
    return 0;

}

void InicializarLista(SLista *lista) {
    lista->pFirst = NULL;
}

SNodo *CriarNodo(SDado info) {
    SNodo *novo = (SNodo*) malloc(sizeof(SNodo));
    if (novo == NULL) {
        printf("Erro de alocacao!");
        exit(1);
    }
    novo->info = info;
    novo->pNext = NULL;
    return novo;
}

void InserirInicio(SLista *lista, SDado info) {
    SNodo *novo = CriarNodo(info);
    if (novo != NULL) {
        novo->pNext = lista->pFirst;
        lista->pFirst = novo;
    } else {
        printf("Erro de alocacao!");
        exit(1);
    }
}

void Lista(SLista *lista) {
    SNodo *atual = lista->pFirst;
    while (atual != NULL) {
        printf("%d ", atual->info.dados);
        atual = atual->pNext;
    }
    printf("\n");
}

void LimparLista(SLista *lista) {
    SNodo *atual  = lista->pFirst;
    while (atual != NULL) {
        SNodo *temp = atual->pNext;
        free(atual);
        atual = temp;
    }
    lista->pFirst = NULL;
}

void ConcatenarLista(SLista *lista1, SLista *lista2) {
    if (lista1->pFirst == NULL) {
        lista1->pFirst = lista2->pFirst;
    } else {
        SNodo *atual = lista1->pFirst;
        while (atual->pNext != NULL) {
            atual = atual->pNext;
        }
        atual->pNext = lista2->pFirst;
    }

    lista2->pFirst = NULL;
}
