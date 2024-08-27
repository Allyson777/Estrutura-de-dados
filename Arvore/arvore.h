#ifndef __ARVORE_H__
#define __ARVORE_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int chave;
    struct no *esq, *dir;
}No;

/* Nome da função: criaNo
    Objettivo: Alocar e incializar um novo Nó da ABB
    Parametros:
        ch: chave a ser inserida (tipo inteiro)
    retorno:ponteiro para um novo nò da arvore alocado e inicializado com o valor de ch
*/

No *criaNo(int ch);

/*
    Nome da função: busca
    Objetivo: Buscar uma chave ch na árvore T
    Parametros: T: ponteiro para o nó raiz da árvore
        ch: chave a ser buscada (inteiro)
    Retorno: ponteiro para o nó que contém a chave, caso ela 
    exista em T, ou NULL caso contrário
*/

No *busca(No *t,int ch, No **pred);

/*
    Nome da funcao: insere
    objetivo: inserir uma nova chave dentro da arvore t(ch será inserida somente se ela não existir na arvore t)
    parametros: 
        T: ponteiro para o nó raiz da árvore
        ch: chave a ser inserida (inteiro)
    Retorno: ponteiro para o nó que contém a chave, caso ela 
    exista em T, ou NULL caso contrário
*/


No *insere(No *t, int ch);

/*
    Nome da funcao: imprime
    objetivo: imprimir a estrutura da árvore de forma que os níveis dos nós sejam identificados
    parametros: 
        T: ponteiro para o nó raiz da árvore
    Retorno: void
*/


void imprime(No *T, int a);

/*
    Nome da funcao: remove
    objetivo: excluir fisicamente o nó de t que contém a chave ch (caso esta exista em T)
    parametros: 
        T: ponteiro para o nó raiz da árvore
        ch: chave a ser excluida (inteiro)
    Retorno: ponteiro para raiz da árvore resultante
*/



No *remover(No *T, int ch);


/*
    Nome da funcao: sucessor
    objetivo: encontrar o nó sucessir de um nó x da árvore e seu respectivo pai
    parametros: 
        x: ponteiro para um nó da árvore
        paisuc: referencia para o ponteiro pai do sucessor 
    Retorno: ponteiro para raiz da árvore resultante
*/



No *sucessor(No *x, No **paisuc);

#endif