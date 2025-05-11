#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int custo;
    int prio;
    struct no *prox;
}celula;

celula *criar(void);
void inserir(celula *p, int prio, int custo);
void imprimir(celula *p);
celula *buscar(celula *ini, int x);
void remover(celula *ini, int y);
void liberar(celula *p);

int main(){
    
    FILE *file;
    int i, n, custo, prio;
    int c, p;

    celula *lista = criar();
    printf("Insira a quantidade de vezes que ques inserir:\n");
    scanf("%d" , &n);
    printf("Insira os digitos a inseir:\n");
    for(i = 0; i < n; i++){
        scanf("%d%d",&prio, &custo);
        inserir(lista, prio, custo);
    }

    if((file = fopen("edmar.txt", "w")) != NULL){
        celula *atual = lista->prox;
        while(atual != NULL){
            fprintf(file ,"%d  %d\n", atual->prio, atual->custo);
            atual = atual->prox;
        }
    }

    fclose(file);

    if((file = fopen("edmar.txt", "r")) != NULL){
        while(fscanf(file, "%d%d",&p, &c) != EOF){
            printf("%d  %d\n", p, c);
        }
    }

    fclose(file);
    

    return 0;
}

celula *criar(void){
    celula *start = (celula *) malloc (sizeof(celula));
    start->prox = NULL;
    return start;
}

void inserir(celula *p, int prio, int custo){
    celula *novo = (celula *) malloc (sizeof(celula));
    novo->custo = custo;
    novo->prio = prio;
    celula *atual = p;
   // while(atual->prox != NULL){
    //    atual = atual->prox;
   // }
   // novo->prox = NULL;
   // atual->prox = novo;
   while(atual->prox != NULL && (atual->prox->prio < prio||(
     atual->prox->prio == prio && atual->prox->custo < custo))){
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
}

void imprimir(celula *p){
    celula *atual = p->prox;
    while(atual != NULL){
        printf("%d  %d\n", atual->prio, atual->custo);
        atual = atual->prox;
    }

}
celula *buscar(celula *ini, int x){
    celula *q = ini->prox;
    while( q != NULL && q->prio != x){
        q = q->prox;
    }
    return(q);
}
void remover(celula *ini, int y){
    celula *p, *q;
    p = ini;
    q = ini->prox;
    while(q != NULL && q->prio != y){
        p = q;
        q = q->prox;
    }
    if(q != NULL){
        p->prox = q->prox;
        free(q);
    }
}
void liberar(celula *p){
    celula *atual = p->prox;
    while(atual != NULL){
        celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}