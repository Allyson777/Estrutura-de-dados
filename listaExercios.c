#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *criaNo(int ch)
{
    No(*novo) = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("ERRODEALOCACAO");
        exit(1);
    }
    novo->chave = ch;
    novo->prox = NULL;
    return novo;
}

void imprime(No *L)
{
    No *aux = L;
    while (aux != NULL)
    {
        printf(" %d -> ", aux->chave);
        aux = aux->prox;
    }
}

No *insereInicio(No *L, int ch)
{
    No *novo = criaNo(ch);
    novo->prox = L;
    L = novo;
    return novo;
}

No *insereFim(No *L, int ch)
{

    No *novo = criaNo(ch);
    No *aux = L;
    if (aux == NULL)
    {
        L = novo;
    }
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return L;
}

No *excluiDuplicada(No *L)
{

    No *aux = L;
    No *proximo = NULL;
    No *anterior = NULL;
    if (L == NULL && L->prox == NULL)
    {
        return NULL;
    }
    while (aux != NULL && aux->prox != NULL)
    {
        proximo = aux->prox;
        anterior = aux;
        while (proximo != NULL)
        {
            if (proximo->chave == aux->chave)
            {
                anterior->prox = proximo->prox;
                free(proximo);
                proximo = anterior->prox;
            }
            else
            {
                anterior = proximo;
                proximo = proximo->prox;
            }
        }
        aux = aux->prox;
    }
    return L;
}

void imprimeOcorrencias(No *L, int x)
{
    No *aux = L;
    int cont = 0;
    if (aux == NULL)
    {
        printf("O numero %d teve um total de 0 ocorrencias", x);
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->chave == x)
            {
                cont++;
            }
            aux = aux->prox;
        }
        printf("O numero %d teve um total de %d ocorrencias", x, cont);
    }
}

No *multiplica(No *L)
{
    No *aux = L;
    if (aux == NULL)
    {
        return NULL;
    }
    else
    {
        while (aux != NULL)
        {
            aux->chave = aux->chave * 10;
            aux = aux->prox;
        }
    }
    return L;
}

void vericaOrd(No *L)
{
    No *aux = L;
    if (aux == NULL)
    {
        printf("Lista vazia");
    }
    while (aux->prox != NULL)
    {
        if (aux->chave > aux->prox->chave)
        {
            printf("Lista Nao ordenada");
            return;
        }
        else
        {
            aux = aux->prox;
        }
    }
    printf("Lista ordenada");
}

No *intercala(No *L1, No *L2)
{

    No *aux1 = L1;
    No *aux2 = L2;
    No *L3 = NULL;
    No *aux3 = L3;
    if (aux1 == NULL)
    {
        return L2;
    }
    if (aux2 == NULL)
    {
        return L1;
    }
    while (aux2 != NULL && aux1 != NULL)
    {
        if (aux1->chave <= aux2->chave)
        {
            aux3 = aux1;
            aux1 = aux1->prox;
        }
        else
        {
            aux3 = aux2;
            aux2 = aux2->prox;
        }
        aux3 = aux3->prox;
    }
    return L3;
}

int main()
{
    No *L1 = NULL;
    No *L2 = NULL;
    No *L3 = NULL;
    L1 = insereInicio(L1, 1);
    L1 = insereFim(L1, 3);
    L1 = insereFim(L1, 5);
    L1 = insereFim(L1, 7);
    L1 = insereFim(L1, 9);
    L2 = insereInicio(L2, 1);
    L2 = insereFim(L2, 3);
    L2 = insereFim(L2, 8);
    L2 = insereFim(L2, 7);
    L2 = insereFim(L2, 10);
    imprime(L1);
    printf("\n");
    imprime(L1);
    printf("\n");
    L3 = intercala(L1, L2);
    imprime(L3);
}