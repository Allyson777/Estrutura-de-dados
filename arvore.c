#include "arvore.h"

No *criaNo(int ch)
{
    No *novo = (No *)calloc(1, sizeof(No));

    if (novo == NULL)
    {
        printf("ERRO_de_ALOCACAO");
    }
    novo->chave = ch;
    return novo;
}

No *insere(No *T, int ch)
{
    No *novo = criaNo(ch);
    No *aux = T, *pai = NULL;
    if (T == NULL)
    {
        return novo;
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->chave == ch)
            {
                free(novo);
                return T;
            }
            if (ch < aux->chave)
            {
                pai = aux;
                aux = aux->esq;
            }
            else
            {
                pai = aux;
                aux = aux->dir;
            }
        }
        if (ch < pai->chave)
        {
            pai->esq = novo;
        }
        else
        {
            pai->dir = novo;
        }
    }
    return T;
}

No *busca(No *T, int ch, No **pred)
{
    No *aux = T;
    *pred = NULL;
    while (aux != NULL)
    {
        if (ch == aux->chave)
        {
            return aux;
        }
        *pred = aux;
        if (ch < aux->chave)
        {

            aux = aux->esq;
        }
        if (ch > aux->chave)
        {

            aux = aux->dir;
        }
    }
    return NULL;
}

No *remover(No *T, int ch)
{
    No *paisuc = NULL, *suc = NULL, *pred = NULL;
    No *aux = busca(T, ch, &pred); // Busca o nó a ser removido e atualiza o predecessor (pred)

    if (aux == NULL)
    {
        return T;
    }
    else
    {
        // Caso 1: Nó a ser removido é uma folha (sem filhos)
        if (aux->esq == NULL && aux->dir == NULL)
        { // se é folha
            if (pred == NULL)
            {
                // Se o nó a ser removido é a raiz da árvore
                free(aux);
                return NULL;
            }
            // Verifica se o nó a ser removido é o filho esquerdo ou direito do predecessor
            if (pred->esq == aux)
            { // filho a esquerda
                pred->esq = NULL;
            }
            if (pred->dir == aux)
            { // filho a direita
                pred->dir = NULL;
            }
            free(aux);
            return T;
        }
        else if (aux->esq != NULL && aux->dir != NULL)
        {
            // Encontra o sucessor do nó (menor valor da subárvore direita)
            suc = sucessor(aux, &paisuc);

            // Substitui o valor da chave do nó a ser removido pelo valor do sucessor
            aux->chave = suc->chave;

            // Remove o sucessor da árvore

            if (paisuc->dir == suc)
            { // sucessor é filho direita
                paisuc->dir = suc->dir;
            }
            else
            { // sucessor é fiho a esquerda
                paisuc->esq = suc->dir;
            }

            free(suc);
            return T;
        }
        // Caso 3: Nó a ser removido tem apenas um filho (esquerda ou direita)
        else
        {

            // Se o nó a ser removido é o filho direito do predecessor
            if (aux == pred->dir)
            {
                // Substitui o nó removido pelo seu filho (se for filho à direita ou esquerda)
                if (aux->esq == NULL)
                {
                    pred->dir = aux->dir;
                }
                if (aux->dir == NULL)
                {
                    pred->dir = aux->esq;
                }
            }
            // Se o nó a ser removido é o filho esquerdo do predecessor
            if (aux == pred->esq)
            { // filho a esquerda
              // Substitui o nó removido pelo seu filho (se for filho à direita ou esquerda)
                if (aux->esq == NULL)
                {
                    pred->esq = aux->dir;
                }
                if (aux->dir == NULL)
                {
                    pred->esq = aux->esq;
                }
            }
            free(aux);
            return T;
        }

        printf("\nsaiu\n");
    }
}
// Função para encontrar o sucessor do um nó
No *sucessor(No *x, No **paisuc)
{
    No *suc = x->dir; // O sucessor começa sendo o filho à direita
    *paisuc = x;      // Atualiza o nó pai do sucessor como sendo o nó atual

    // Se não há filho à direita, não existe sucessor
    if (suc == NULL)
    {
        return suc;
    }
    // Procura o menor nó da subárvore direita (à esquerda do filho direito)
    while (suc->esq != NULL)
    {
        *paisuc = suc;
        suc = suc->esq;
    }

    return suc;
}

void imprime(No *T, int nivel)
{
    if (T)
    {
        int i;
        imprime(T->dir, nivel + 1); // Primeiro, imprime a subárvore direita
        for (i = 0; i < nivel; i++) // Depois, imprime espaços em branco
            printf("\t");
        printf("%d\n", T->chave);   // Imprime a chave do nó atual
        imprime(T->esq, nivel + 1); // imprime a subárvore esquerda
    }
}