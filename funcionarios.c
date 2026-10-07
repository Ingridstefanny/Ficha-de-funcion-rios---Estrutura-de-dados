#include<stdio.h>
#include<string.h>
const int Max= 15;
const int tam= 50;
const int limite= 6;


typedef struct {
    
    char Matricula[6];
    char Nome[50];
    int idade;
    float salario;

} Funcionario;

void zeraFuncionario(Funcionario tabela[])
{
    int i;
    for(i = 0; i < Max; i++)
    {
        strcpy(tabela[i].Matricula, "");
        strcpy(tabela[i].Nome, "");
        tabela[i].idade= 0;
        tabela[i].salario= 0.00;
    }
}

//Por meio do numero da matricula identificamos a posição do funcionario no vetor
int buscaFuncionario(Funcionario tabela[], char matriculabusca[])
{
    int k;
    for(k = 0; k < Max; k++){
        if(strcmp(tabela[k].Matricula, matriculabusca) == 0){
            return k;   /* retorna o índice do funcionário buscado */
        }
    }
    //Caso não existir:
    return -1;
}

//
void adicionaFuncionario(Funcionario tabela[], int indice, char matricula_new[], char nome_new[], int idade_new, float salario_new)
{
    strcpy(tabela[indice].Matricula, matricula_new);
    strcpy(tabela[indice].Nome, nome_new);
    tabela[indice].idade = idade_new;
    tabela[indice].salario = salario_new;
}

void removerFuncionario(Funcionario tabela[], char matriculabusca[])
{
    int k = buscaFuncionario(tabela, matriculabusca);
    strcpy(tabela[k].Matricula, "");
    strcpy(tabela[k].Nome, "");
    tabela[k].idade = 0;
    tabela[k].salario = 0.0;
}

void imprimeFuncionario(Funcionario tabela[], char matriculabusca[])
{
    int i = buscaFuncionario(tabela, matriculabusca);

    if (i == -1)
    { 
        printf("Funcionario nao encontrado\n"); 
    }

    else {
        printf("Matricula: %s\nNome: %s\nIdade: %d\nSalario: %.2f\n", 
                tabela[i].Matricula, tabela[i].Nome, tabela[i].idade, tabela[i].salario);
    }
    printf("\n");
}


int main()
{
    int idade;
    char Matricula[6];
    char nome[tam];
    float salario;

    Funcionario empresa[Max];
    zeraFuncionario(empresa);
    int opcao = 0;
    int indice;
    int i;

    while (opcao != 5) {

        printf("Que acao deseja realizar?\n"
       "1- Adicionar funcionario\n"
       "2- Remover funcionario\n"
       "3- Imprimir funcionario\n"
       "4- Imprimir todos os funcionarios\n"
       "5- Sair\n");
    
        scanf("%d", &opcao);
            
        switch(opcao) {
            case 1: 
                printf("Informe o numero da matricula:\n");
                scanf("%s", Matricula);
                fflush(stdin);

                printf("\nInforme o nome:\n");
                scanf("%s", nome);
                fflush(stdin);

                printf("Informe a idade:\n");
                scanf("%d", &idade);

                printf("Informe o salario:\n");
                scanf("%f",&salario);

                indice= buscaFuncionario(empresa, "");
                adicionaFuncionario(empresa, indice, Matricula,nome, idade, salario);

                break;

            case 2: 
                removerFuncionario(empresa, Matricula);
                break;

            case 3: 
                imprimeFuncionario(empresa,Matricula);
                break;

            case 4: 
            
                for (i = 0; i < Max; i++) {
                    if (strcmp(empresa[i].Matricula, "") != 0) {
                        imprimeFuncionario(empresa, empresa[i].Matricula);
                    }
                }
                break;
            default: 
                printf("Opcao invalida\n");
                break;
        }
    }
    printf("Finalizando o programa...\n");
    return 0;
}

   