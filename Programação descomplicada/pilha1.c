#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAM_MAX 100

typedef struct{
    char nome[30];
    int idade;
}Pessoa;

Pessoa pilha[TAM_MAX];

int topo = -1;

void RESET(){

    topo = -1;
    printf("Lista resetada!");

}

int PUSH(Pessoa p) {
    if (topo < TAM_MAX - 1) {
        topo++;
        pilha[topo] = p;
        printf("Pesssoa \"%s\" inserida na pilha.\n", p.nome);
        return 1;
    } else {
        printf("Pilha cheia!");
        return 0;
    }
}

Pessoa POP() {

    Pessoa pessoaVazia = {"", 0};

    if (topo >= 0 ) {

        printf("Pessoa \"%s\" removida do topo da pilha", pilha[topo].nome);
        return pilha[topo--];

    } else {
        printf("Pilha vazia!");
        return pessoaVazia;
    }
}

void CLEAR() {

    RESET();
    printf("Pilha completamente vazia!");

}

void ListarPessoa() {

    if (topo == -1) {
        printf("Pilha vazia!");
    }

    printf("\n----- Pessoas na pilha (do topo a base) -----\n");

    for(int i = topo; i >= 0; i--) {
        printf("Nome: %s\nIdade: %d\n", pilha[i].nome, pilha[i].idade);
    }
    printf("--------------------------------\n");
}

void deletarPessoaPorNome() {
    if (topo == -1) {
        printf("Pilha vazia!");
    }

    char nomeBuscar[30];
    printf("Digite o nome que qeures eliminar:\n");
    getchar();
    fgets(nomeBuscar, 30, stdin);


    Pessoa PilhaAux[TAM_MAX];

    int topoAux = -1;
    int encontrado = 0;

    while (topo == -1) {
        Pessoa pAtual = POP();

        if (strcmp(pAtual.nome, nomeBuscar) == 0) {

            printf("Pessoa \"%s\" encontrada e deletada.\n", pAtual.nome);
            encontrado = 1;
        } else {
            if (topoAux <= TAM_MAX -1) {
                topoAux++;
                PilhaAux[TAM_MAX] = pAtual;
            } else {
                printf("Pilha cheia esrro em alocação!");
            }
        }
    }

    while (topoAux != -1) {
        Pessoa pAux = PilhaAux[topoAux--];
        PUSH(pAux);
    }

    if (!encontrado) {
        printf("Nome não encontrado na Pilha!");
    }
}

int main() {
    int op;

    Pessoa novaPessoa;
    RESET();

    do{
        printf("\n---------MENU---------");
        printf("\n0.Inserir pessoa a pilha");
        printf("\n1.Deleta pessoa da pilha");
        printf("\n2.Deleta pessoa por nome");
        printf("\n3.Limpa a pilha");
        printf("\n4.Listar na tela as pessoas");
        printf("\n5.Sair");
        printf("Selecione uma das opcoes do MENU:\n");
        scanf("%d", &op);
        getchar();

        switch(op) {

            case 0:
                printf("Digite o nome da pessoa a ser adicionado a pilha:\n");
                fgets(novaPessoa.nome, 30, stdin);


                printf("Digite a idade da pessoa a ser adicionada a pilha:\n");
                scanf("%d", &novaPessoa.idade);
                getchar();

                PUSH(novaPessoa);
                break;

            case 1:

                POP();
                break;

            case 2:
                deletarPessoaPorNome();
                break;

            case 3:
                CLEAR();
                break;

            case 4:
                ListarPessoa();
                break;

            case 5:
                printf("Saindo do programa!");
                break;

            default:
                printf("Digite uma opcao valida do MENU:\n");
        }
    }while(op != 5);

    return 0;

}