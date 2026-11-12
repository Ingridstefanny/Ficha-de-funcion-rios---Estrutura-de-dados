#include <stdio.h>
#include <string.h>
#include "funcionarios.h"

#define limite 6
#define tam 50

int main()
{
    Funcionario *inicio = NULL;
    int idade;
    char Matricula[limite];
    char nome[tam];
    char entrada[tam];
    float salario;

    inicio = carregarCSV(inicio);
    int opcao = 0;

    while (opcao != 5) {

        printf("\n========================================\n");
        printf("       SISTEMA DE FUNCIONARIOS\n");
        printf("========================================\n");
        printf("1 - Adicionar funcionario\n");
        printf("2 - Remover funcionario\n");
        printf("3 - Consultar funcionario\n");
        printf("4 - Consultar todos os funcionarios\n");
        printf("5 - Sair\n");
        printf("----------------------------------------\n");
        printf("Escolha uma opcao: ");
    
        scanf("%d", &opcao);
            
        switch(opcao) {
            case 1: 
                
                printf("\n---------- NOVO FUNCIONARIO ----------\n");
                //Caso o usuario digitar a quantidade dos numeros de matricula errado.
                do
                {
                    printf("\nInforme o numero da matricula com 5 digitos:\n");
                    scanf("%49s", entrada);
                    
                    if (strlen(entrada) != 5)
                    {
                        printf("\nErro: a matricula deve possuir exatamente 5 digitos!\n");
                    }

                }
                while (strlen(entrada) != 5);
                
                strcpy(Matricula, entrada);
                
                printf("\nInforme o nome:\n");
                scanf(" %49[^\n]", nome);

                

                printf("\nInforme a idade:\n");
                scanf("%d", &idade);

                printf("\nInforme o salario:\n");
                scanf("%f",&salario);

                inicio = adicionaFuncionario(inicio, Matricula, nome, idade, salario);

                salvarCSV(inicio);

                break;

            case 2: 
                printf("\n---------- REMOVER FUNCIONARIO ----------\n");
                printf("\nQual a matricula do funcionario que deseja remover?\n");
                scanf("%5s", Matricula);
                inicio = removerFuncionario(inicio, Matricula);

                salvarCSV(inicio);
                break;

            case 3: 
                printf("\n---------- CONSULTAR FUNCIONARIO ----------\n");
                printf("\nInforme a matricula de um funcionario:\n");
                scanf("%5s", Matricula);
                printf("\n");
                imprimeFuncionario(inicio, Matricula);
                break;

            case 4: 
                printf("\n========== FUNCIONARIOS CADASTRADOS ==========\n");
                imprimeFuncionarios(inicio);
                break;
            
            case 5:
                
                break;

            default: 
                printf("\nOpcao invalida!\n");
                break;
        }
    }
    printf("\nFinalizando o programa...\n");
    return 0;
}