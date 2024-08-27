
#include <stdio.h>
#include <stdlib.h>

// define uma estrutura com uma chave do tipo int, e 1 ponteiro para o proximo nó

typedef struct no
{
    int chave;
    struct no *prox;
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
    return novo;
}

// insere um novo nó no inicio

No *insereInicio(No *L, int valor)
{
    No *novo = criaNo(valor);
    novo->prox = L;
    L = novo;
    return L;
}

// função para inserir um nó no final da lista

No *insereFim(No *L, int valor)
{
    No *novo = criaNo(valor);
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

// No *buscaChave(No *L, int chave)
// {
//     No *aux = L;
//     if (aux == NULL)
//     {
//         printf("Lista vazia, não existe chave");
//     }
//     else
//     {
//         while (aux != NULL)
//         {
//             if (aux->chave == chave)
//             {
//                 printf("Chave encontrada");
//                 break;
//             }
//             aux = aux->prox;
//         }
//     }
//     return aux;
// }

// imprime uma lista de nós

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

// exclui chaves repetidas

No *excluiRepetida(No *L, int x)
{

    No *aux = L;
    No *pred = NULL;
    int cont = 0;
    if (aux == NULL)
    {
        return NULL;
    }
    else
    {
        while (aux != NULL)
        {

            if (aux->chave == x)
            {
                cont++;
                // achamos a chave na lista a adicionamos 1 na variavel contadora
                if (cont > 1)
                {
                    // caso a variavel contadora seja maior que 1, logo é um nó repetido da lista
                    // então redefine o ponteiro e exclui a chave repetida
                    pred->prox = aux->prox;
                    free(aux);
                    aux = pred->prox;
                }
                else
                {
                    pred = aux;
                    aux = aux->prox;
                }
            }
            else
            {
                pred = aux;
                aux = aux->prox;
            }
        }
    }
    return L;
}

int main()
{
    No *L = NULL;
    L = insereInicio(L, 10);
    L = insereInicio(L, 30);
    L = insereInicio(L, 30);
    L = insereInicio(L, 30);
    L = insereFim(L, 50);
    imprime(L);
    L = excluiRepetida(L, 30);
    imprime(L);
}