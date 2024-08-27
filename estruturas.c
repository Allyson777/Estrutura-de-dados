#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int ch;
    struct no *prox, *ant;
} No;

typedef struct lista
{
    No *inicio, *fim;
} Lista;

Lista *criaLista()
{
    No *nova;
    nova = (Lista *)malloc(sizeof(Lista));
    if (nova == NULL)
    {
        printf("ERRO DE ALOCACAO");
        exit(1);
    }
    return nova;
}

No *criaNo(int chave)
{
    No *novo;
    novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("ERRO DE ALOCACAO");
        exit(1);
    }
    novo->ch = chave;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void *insereIncio(Lista *l, int valor)
{
    No *novo = criaLista(novo);
    novo->prox = l->inicio;
    l->inicio->ant = novo;
    l->inicio = novo;
    return l;
}
void *insere(Lista *l, int valor)
{
    No *novo = criaLista(novo);
    if (l == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        novo->prox = l->fim;
        l->fim->ant = novo;
        l->fim = novo;
    }
    return l;
}
void removeEspecifica(Lista *L, int valor)
{
    No *aux = L->inicio;
    if (aux == NULL)
    {
        printf("Lista vazia");
        return;
    }
    else
    {
        while (aux != NULL && aux->ch != valor)
        {
            aux->ant = aux;
            aux = aux->prox;
        }
        if (aux == NULL)
        {
            printf("valor nao encontrado");
        }
        if (aux->ant == NULL)
        {
            L->inicio = aux->prox;
            if (L->inicio != NULL)
            {
                L->inicio->ant = NULL;
            }
        }
        else
        {
            aux->ant->prox = aux->prox;
        }
        if (aux->prox == NULL)
        {
            L->fim = aux->ant;
            if (L->fim != NULL)
            {
                L->fim->prox = NULL;
            }
        }
        else
        {
            aux->prox->ant = aux->ant;
        }

        free(aux);
    }
}

No *removeCh(No *L, int valor)
{
    if (L == NULL)
    {
        printf("Lista Vazia");
        return NULL;
    }
    No *aux = L;
    No *pred = NULL;
    while (aux != L && aux->ch != valor)
    {
        pred = aux;
        aux = aux->prox;
    }
    if (aux->ch == valor)
    {
        pred->prox = L->prox;
        L = pred;
        free(aux);
        return L;
    }
    else
    {
        printf("chave nao existente");
    }
    return L;
}