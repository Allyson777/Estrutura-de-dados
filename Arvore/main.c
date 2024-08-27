#include "arvore.h"

int main(){
    int opcao = 0, chave=0;
    No *T =NULL;
    No *pred = NULL;
    printf("Digite a opcao desejada: \n1-Inserir\n2-Buscar\n3-Remover\n4-imprimir\n5-sair\n");
    
    scanf("%d", &opcao);
    while(opcao != 5){
        switch (opcao)
        
        {
        case 1:
                printf("Digite a chave a ser inserida: ");
                scanf("%d", &chave);
                T = insere(T, chave);
                break;
            case 2:
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &chave);
                No *resultado = busca(T, chave, &pred);
                if (resultado)
                    printf("Chave %d encontrada.\n", chave);
                else
                    printf("Chave %d nao encontrada.\n", chave);
                break;
            case 3:
                printf("Digite a chave a ser removida: ");
                scanf("%d", &chave);
                T = remover(T, chave);
                break;
            case 4:
                printf("Imprimindo arvore:\n");
                imprime(T, 0);
                break;
            case 5:
                printf("Saindo...\n");
                return 0;
        default:
            printf("Opcao invalida");
            break;
        }
        printf("Digite a opcao desejada: \n1-Inserir\n2-Buscar\n3-Remover\n4-imprimir\n5-sair\n");
        
        scanf("%d", &opcao);
    }

}