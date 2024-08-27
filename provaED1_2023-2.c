#include <stdlib.h>
#include <stdio.h>

// 1- declare uma estrutura struct

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *separa(No *L1, int n)
{
    No *aux = L1;
    No *L2 = NULL;
    if (aux == NULL)
    {
        return NULL;
    }
    while (aux != NULL && aux->chave != n)
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("Não existe ocorrencias de N na lista.");
        return aux;
    }

    L2 = aux->prox;
    aux->prox = NULL;
    return L2;
}

No *contida(No *L1, No *L2)
{

    No *aux = L1;
    No *aux2 = L2;

    if (L2 == NULL)
    {
        return 1;
    }
    while (L1 != NULL)
    {
        aux = L1;

        while (aux2 != NULL && aux->chave == aux2->chave)
        {
            aux2 = aux2->prox;
            aux = aux->prox;
        }
        if (aux2 == NULL)
        {
            return 1;
        }
        L1 = L1->prox;
    }
    return 0;
}
