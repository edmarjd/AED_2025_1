#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incluirPessoa(void **pBuffer);
void apagarPessoa(void **pBuffer);
void buscarPessoa(void *pBuffer);
void listarPessoas(void *pBuffer);

int main() {
    void *pBuffer = malloc(sizeof(int));
    *(int *)pBuffer = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir\n2. Apagar\n3. Buscar\n4. Listar\n5. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirPessoa(&pBuffer);
                break;
            case 2:
                apagarPessoa(&pBuffer);
                break;
            case 3:
                buscarPessoa(pBuffer);
                break;
            case 4:
                listarPessoas(pBuffer);
                break;
            case 5:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    free(pBuffer);
    return 0;
}

void incluirPessoa(void **pBuffer) {
    int *numPessoas = (int *)*pBuffer;
    int novoNum = *numPessoas + 1;
    size_t novoSize = sizeof(int) + novoNum * 18;

    void *novoBuffer = realloc(*pBuffer, novoSize);
    if (!novoBuffer) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    *pBuffer = novoBuffer;
    numPessoas = (int *)*pBuffer;

    char *nome = (char *)(*pBuffer + sizeof(int) + (*numPessoas) * 18);
    int *idade = (int *)(nome + 10);
    int *tel = idade + 1;

    printf("Nome (max 10 letras): ");
    char tempNome[11];
    scanf("%10s", tempNome);
    strncpy(nome, tempNome, 10);

    printf("Idade: ");
    scanf("%d", idade);

    printf("Telefone: ");
    scanf("%d", tel);

    (*numPessoas)++;
}

void apagarPessoa(void **pBuffer) {
    int *numPessoas = (int *)*pBuffer;
    if (*numPessoas == 0) {
        printf("Agenda vazia.\n");
        return;
    }

    char nomeBusca[11];
    printf("Nome a apagar: ");
    scanf("%10s", nomeBusca);

    int encontrado = -1;
    for (int i = 0; i < *numPessoas; i++) {
        char *nome = (char *)(*pBuffer + sizeof(int) + i * 18);
        if (strcmp(nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Não encontrado.\n");
        return;
    }

    // Mover dados para trás
    for (int i = encontrado; i < *numPessoas - 1; i++) {
        void *dest = *pBuffer + sizeof(int) + i * 18;
        void *src = *pBuffer + sizeof(int) + (i + 1) * 18;
        memmove(dest, src, 18);
    }

    (*numPessoas)--;
    size_t novoSize = sizeof(int) + (*numPessoas) * 18;
    void *novoBuffer = realloc(*pBuffer, novoSize);
    if (novoBuffer == NULL && *numPessoas > 0) {
        printf("Erro ao realocar.\n");
        return;
    }
    *pBuffer = novoBuffer;
}

void buscarPessoa(void *pBuffer) {
    int numPessoas = *(int *)pBuffer;
    if (numPessoas == 0) {
        printf("Agenda vazia.\n");
        return;
    }

    char nomeBusca[11];
    printf("Nome a buscar: ");
    scanf("%10s", nomeBusca);

    for (int i = 0; i < numPessoas; i++) {
        char *nome = (char *)(pBuffer + sizeof(int) + i * 18);
        if (strcmp(nome, nomeBusca) == 0) {
            int *idade = (int *)(nome + 10);
            int *tel = idade + 1;
            printf("Nome: %s\nIdade: %d\nTelefone: %d\n", nome, *idade, *tel);
            return;
        }
    }

    printf("Não encontrado.\n");
}

void listarPessoas(void *pBuffer) {
    int numPessoas = *(int *)pBuffer;
    if (numPessoas == 0) {
        printf("Agenda vazia.\n");
        return;
    }

    printf("Contatos:\n");
    for (int i = 0; i < numPessoas; i++) {
        char *nome = (char *)(pBuffer + sizeof(int) + i * 18);
        int *idade = (int *)(nome + 10);
        int *tel = idade + 1;
        printf("%d: Nome: %s, Idade: %d, Tel: %d\n", i + 1, nome, *idade, *tel);
    }
}
