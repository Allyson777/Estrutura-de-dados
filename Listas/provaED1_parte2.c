
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox, *ant;
} No;

No *excluiEspecifica(No *L, int x)
{

    No *aux = L;

    if (L == NULL)
    {
        return NULL;
    }
    while (aux != NULL && aux->chave != x)
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("Chave nao encontrada");
        return;
    }
    if (aux->ant = NULL)
    {
        L = NULL;
    }
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
}

// No *intercala(No *L1, No *L2)
// {
//     No *aux = NULL;
//     No *aux2 = NULL;
//     if (L1 == NULL)
//     {
//         return L2;
//     }
//     if (L2 == NULL)
//     {
//         return L1;
//     }
//     if (L1->chave < L2->chave)
//     {
//         aux = L1;
//         aux2 = L2;
//     }
//     else
//     {
//         aux = L2;
//         aux2 = L1;
//     }
//     aux = aux->prox;
//     while (aux != NULL)
//     {
//         if (aux->chave < aux2->chave)
//         {
//             aux = aux->prox;
//         }
//         else
//         {
//         }
//     }
//     L1->prox = aux2;
//     aux2->ant = L1;
//     return L1;
// }