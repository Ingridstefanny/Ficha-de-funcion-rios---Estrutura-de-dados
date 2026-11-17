
#include <stdio.h>
#include "pilhadinamica.h"

int main(){

    Pilha p;
    int valor;
    int opcao;

    criarPilha(&p);

    do {
        printf("\n--- PILHA DINAMICA ---\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Consultar topo\n");
        printf("4 - Verificar se esta vazia\n");
        printf("0 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);

                if(empilhar(&p, valor) == 1){
                    printf("Valor empilhado!\n");
                }
                else{
                    printf("Erro ao alocar memoria!\n");
                }
                break;

            case 2:
                if(desempilhar(&p, &valor) == 1){
                    printf("Valor removido: %d\n", valor);
                }
                else{
                    printf("Pilha vazia!\n");
                }
                break;

            case 3:
                if(consultarTopo(&p, &valor) == 1){
                    printf("Topo: %d\n", valor);
                }
                else{
                    printf("Pilha vazia!\n");
                }
                break;

            case 4:
                if(vazia(&p) == 1){
                    printf("A pilha esta vazia!\n");
                }
                else{
                    printf("A pilha nao esta vazia!\n");
                }
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
