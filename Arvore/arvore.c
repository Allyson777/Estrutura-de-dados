#include "arvore.h"

No *criaNo(int ch){
    No *novo = (No*)calloc(1,sizeof(No));

    if(novo==NULL){
        printf("ERRO_de_ALOCACAO");
    }
    novo->chave=ch;
    return novo;
}

No *busca(No *T,int ch, No **pred){
    No *aux = T;

    while(aux != NULL){
        if(ch==aux->chave){
            return aux;
        }

        if(ch < aux->chave){
            *pred =aux;
            aux = aux->esq;
        }
        if(ch > aux->chave){
            *pred =aux;
            aux = aux->dir;
        }
    }
    return NULL;
}

No *insere(No *T, int ch){
    No *novo = criaNo(ch);
    No *aux = T, *pai=NULL;
    if(T==NULL){
        return novo;
    }else{
        while(aux!=NULL){
            if(aux->chave == ch){
                free(novo);
                return T;
            }
            if(ch < aux->chave){
                pai = aux;
                aux = aux->esq;
            }else{
                pai = aux;
                aux = aux->dir;
            }
        }
        if(ch < pai->chave){
            pai->esq = novo;
        }else{
            pai->dir = novo;
        }
    }
    return T;

}

No *remover(No *T, int ch){
    No *paisuc=NULL, *suc=NULL, *pred = NULL;
    No *aux = busca(T, ch, &pred);
    

    if(aux==NULL){
        return T;
    }else{
        if(aux->esq == NULL && aux->dir == NULL){//se é folha
            printf("\nEntrou1\n");
            if(pred == NULL){//se é raiz
                free(aux);
                return NULL;
            }
            if(pred->esq->chave == aux->chave ){//filho a esquerda
                pred->esq = NULL;
            }
            if(pred->dir->chave == aux->chave ){//filho a direita
                pred->dir = NULL;
            }
            free(aux);
            return T;
        }else if(aux->esq != NULL && aux->dir !=NULL){
            printf("\nEntrou2\n");
            suc = sucessor(aux, &paisuc);
            aux->chave=suc->chave;
            if(paisuc->dir == suc){         //sucessor é filho direita
                paisuc->dir = suc->dir;
            }else{                          //sucessor é fiho a esquerda
                paisuc->esq =suc->dir;
            }
            
            free(suc);
            return T;
        }    
        else{
            if(aux == pred->dir){ // filho a direita
                if(aux->esq == NULL){
                    pred->dir = aux->dir;
                }if(aux->dir == NULL){
                    pred->dir = aux->esq;
                }
            }if(aux == pred->esq){  //filho a esquerda
            
                if(aux->esq == NULL){
                    pred->esq = aux->dir;
                }if(aux->dir == NULL){
                    pred->esq = aux->esq;
                }
            }
            free(aux);
            return T;
        }
            
        printf("\nsaiu\n");
    }
    

}

No *sucessor(No *x, No **paisuc){
    printf("\nentrou1\n");
    No *suc = x->dir;
    *paisuc = x;
    if(suc==NULL){
        return suc;
    }
    while(suc->esq!=NULL){
        *paisuc = suc;
        suc = suc->esq;
    }
    printf("\n");
    printf("%d", suc);
    printf("\n");
    return suc;

}

void imprime(No *T, int nivel){
if(T){
    int i;
    imprime(T->dir, nivel+1);
    for(i=0; i < nivel; i ++)printf("\t");
    printf("%d\n", T->chave);
    imprime(T->esq, nivel+1);
}
}
