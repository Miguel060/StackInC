#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_pilha {
    char cor[20];
    struct st_pilha *prox;
    struct st_pilha *ant;
};

typedef struct st_pilha pilha;
pilha *topo;
void iniciarPilha(pilha *p) {
    p->prox = NULL;
    topo = p;
}
void imprimir(pilha *p) {
    pilha *aux;
    aux = topo->cor;
    printf("Pilha: \n");
    while (aux->ant!= NULL) {
        printf("%s \n", aux->cor);
        aux = aux->ant;
    }
}
void push(pilha *p) {
    pilha *novoElemento = (pilha *) malloc(sizeof(pilha));
    printf("Digite a cor: ");
    scanf("%s", novoElemento->cor);
    topo->prox = novoElemento;
    novoElemento->ant = topo;
    topo = novoElemento;
}
void pop(pilha *p) {
    topo = topo->ant;
}

int menu() {
    int opt;
    printf("\nSwitch option: \n");
    printf("1. Mostrar pilha\n");
    printf("2. Inserir na pilha\n");
    printf("3. Remover da pilha\n");
    printf("4. Encerrar\n");
    printf("Option: ");
    scanf("%d", &opt);
    printf("\n");
    return opt;
}
void option(pilha *p, int option) {
    switch (option) {
        case 1:
            imprimir(p);
        break;
        case 2:
            push(p);
        break;
        case 3:
            pop(p);
        break;
        case 4:
            printf("Encerrando...\n");
        exit(0);
        default:
            printf("Invalid option\n");
    }
}
int main() {
   pilha *p = (pilha *) malloc(sizeof(pilha));
    int opt;
    if (!p) {
        printf("Sem memoria\n");
        exit(1);
    }
    iniciarPilha(p);
    do {
        opt = menu();
        option(p, opt);
    } while (opt);
    free(p);-
}
