
#include <stdio.h>
#include <stdlib.h>

// cria uma estrutura duplamente encadeada com uma chave, e dois ponteiros

typedef struct no
{
    int chave;
    struct no *prox, *ant;
} No;

// cria nó sem nó-cabeça:

No *criaNo(int ch)
{
    No *novo;
    novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("ERRO_de_ALOCAÇÃO");
        exit(1);
    }
    novo->chave = ch;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

No *insereInicio(No *L, int valor)
{
    No *novo = criaNo(valor);
    novo->prox = L;
    if (L != NULL)
    {
        L->ant = novo;
    }
    return novo;
}

No *excluiInicio(No *L)
{
    No *aux = L;
    if (L == NULL)
    {
        return NULL;
    }
    else
    {
        if (aux->prox == NULL)
        {
            L = NULL;
        }
        else
        {
            L = aux->prox;
            L->ant = NULL;
            free(aux);
        }
    }
    return L;
}
void imprime(No *L)
{
    No *aux = L;
    while (aux != NULL)
    {
        printf(" %d ->", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

No *buscaord(No *L, int valor)
{

    No *aux = L;
    if (L == NULL)
    {
        return NULL;
    }
    else
    {
        while (aux != NULL && valor > aux->chave)
        {
            aux = aux->prox;
        }
        return aux;
    }
}

No *insereOrdenada(No *L, int ch)
{

    No *novo = criaNo(ch);
    No *aux = buscaord(L, ch);
    if (aux == NULL)
    {
        L = novo;
    }
    else
    {

        if (ch > aux->chave)
        {
            aux->prox = novo;
            novo->ant = aux;
        }
        else
        {
            novo->prox = aux;
            if (aux->ant == NULL)
            {
                L = novo;
            }
            else
            {
                aux->ant = novo;
            }
        }
    }
    return L;
}

No *intercala(No *L1, No *L2)
{
    No *L3 = NULL;
    No *aux = NULL;
    if (L1 == NULL)
    {
        return L2;
    }
    if (L2 == NULL)
    {
        return L1;
    }

    if (L1->chave <= L2->chave)
    {
        L3 = L1;
        L1 = L1->prox;
    }
    else
    {
        L3 = L2;
        L2 = L2->prox;
    }

    aux = L3;

    while (L1 != NULL && L2 != NULL)
    {
        if (L1->chave)
            ;
    }
}

int main()
{
    No *L = NULL;
    L = insereInicio(L, 10);
    L = insereInicio(L, 30);
    L = insereInicio(L, 30);
    L = insereInicio(L, 30);
    imprime(L);
    L = excluiInicio(L);
    imprime(L);
}