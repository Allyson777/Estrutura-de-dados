#include <stdio.h>
#include <stdlib.h>

// 1- é uma especificação de um conjunto de dados e operações que podem
// ser executadas sobre esses dados

// 2 - Tem a principal caracterisca o LIFO ultimo a entrar e primeiro a sair
//  um exemplo é a pilha de pratos

// 3- Inserir em uma pilha

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *criaNo(int ch)
{
    No *novo;
    novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        exit(1);
    }
    novo->chave = ch;
    novo->prox = NULL;
    return novo;
}

No *enfilera(No *L, int valor)
{
    No *novo = criaNo(valor);
    No *aux = L;
    if (aux == NULL)
        return novo;
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

No *desenfilera(No *L)
{
    if (L == NULL)
        return NULL;
    No *aux = L;
    L = L->prox;
    free(aux);
    return L;
}