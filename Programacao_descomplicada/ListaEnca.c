#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int cod;
    char nome[40];
    float preco;
}SDado;

typedef struct SNodo{
    SDado info;
    struct SNodo *pNext;
}SNodo;

typedef struct {
    SNodo *pFirst;
}SLista;

void Inicializar(SLista *lista);
SNodo *CriarNodo(SDado info);
void InserirInicio (SLista *lista, SDado info);
void InserirOrdem(SLista *lista, SDado info);
void Listar(SLista *lista);
void LimparLista(SLista *lista);

int main() {

    SLista lista;
    Inicializar(&lista);

    SDado produto;
    for (int i = 0; i < 3; i++) {
        printf("Insere o codigo do produto:\n");
        scanf("%d", &produto.cod);

        printf("Insere o nome do produto:\n");
        scanf(" %[^\n]", produto.nome);

        printf("Insire o preco do produto:\n");
        scanf("%f", &produto.preco);

        InserirOrdem(&lista, produto);
        printf("\n");
    }

    printf("Listar produtos:\n");
    Listar(&lista);

    LimparLista(&lista);
}

void Inicializar(SLista *lista) {
    lista->pFirst = NULL;
}

SNodo *CriarNodo(SDado info) {
    SNodo *novo = (SNodo*) malloc(sizeof(SNodo));
    if (novo != NULL) {
        novo->info = info;
        novo->pNext = NULL;
    }

    return novo;
}

void InserirInicio (SLista *lista, SDado info) {
    SNodo *novo = CriarNodo(info);
    if (novo != NULL) {
        novo->pNext = lista->pFirst;
        lista->pFirst = novo;
    } else {
        printf("Erro de alocacao!");
        exit(1);
    }
}

void InserirOrdem(SLista *lista, SDado info) {
    SNodo *novo = CriarNodo(info);
    
    if (novo == NULL) {
        printf("Erro de alocacao!");
        exit(1);
    }

    if  (lista->pFirst == NULL || strcmp(info.nome, lista->pFirst->info.nome) < 0) {
        novo->pNext = lista->pFirst;
        lista->pFirst = novo;
        return;
    }

    SNodo *atual = lista->pFirst;
    while (atual->pNext != NULL && strcmp(info.nome , atual->pNext->info.nome) > 0) {
        atual = atual->pNext;
    }

    novo->pNext = atual->pNext;
    atual->pNext = novo;
}

void Listar(SLista *lista) {
    SNodo *atual = lista->pFirst;
    while (atual != NULL) {
        printf("\n--------------------------------");
        printf("\nO codigo e : %d", atual->info.cod);
        printf("\nO nome e : %s", atual->info.nome);
        printf("\nO preco e: %.2f", atual->info.preco);
        printf("\n---------------------------------\n");
        atual = atual->pNext;
    }
}
void LimparLista(SLista *lista) {
    SNodo *atual = lista->pFirst;
    while (atual != NULL) {
        SNodo *temp = atual->pNext;
        free(atual);
        atual = temp;
    }
    lista->pFirst = NULL;
}
