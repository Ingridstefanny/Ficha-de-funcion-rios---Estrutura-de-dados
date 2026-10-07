#include<stdio.h>
#include<string.h>
#define Max 15
#define tam 50
#define limite 6

//Estrutura para funcionario
typedef struct {
    
    char Matricula[limite];
    char Nome[tam];
    int idade;
    float salario;

} Funcionario;

//Zera todas as informações das variaveis.
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

//Função para adicionar um funcionario
void adicionaFuncionario(Funcionario tabela[], char matricula_new[], char nome_new[], int idade_new, float salario_new)
{
     int existe = buscaFuncionario(tabela, matricula_new);

    if (existe != -1)
    {
        printf("Erro: matricula ja cadastrada.\n");
        return;
    }

    int indice = buscaFuncionario(tabela, "");

    if (indice == -1)
    {
        printf("Nao eh possivel adicionar um funcionario: tabela cheia.\n");
    }
    else
    {
        strcpy(tabela[indice].Matricula, matricula_new);
        strcpy(tabela[indice].Nome, nome_new);
        tabela[indice].idade = idade_new;
        tabela[indice].salario = salario_new;

        printf("Funcionario cadastrado com sucesso.\n");
    }
}

//Removendo um funcionario
void removerFuncionario(Funcionario tabela[], char matriculabusca[])
{
    int k = buscaFuncionario(tabela, matriculabusca);

    if (k == -1)
    {
        printf("Funcionario nao encontrado.\n");
    }
    else
    {
        strcpy(tabela[k].Nome, "");
        strcpy(tabela[k].Matricula, "");
        tabela[k].salario = 0.0;
        tabela[k].idade = 0;

        printf("Funcionario removido.\n");
    }
}

//Função para imprimir funcionários
void imprimeFuncionario(Funcionario tabela[], char matriculabusca[])
{
    int i = buscaFuncionario(tabela, matriculabusca);

    if (i == -1)
    { 
        printf("Funcionario nao encontrado\n"); 
    }
    else
    {
        printf("Matricula: %s\nNome: %s\nIdade: %d\nSalario: %.2f\n",
               tabela[i].Matricula,
               tabela[i].Nome,
               tabela[i].idade,
               tabela[i].salario);
    }

    printf("\n");
}

//Função para imprimir vários funcionarios
void imprimeFuncionarios(Funcionario tabela[])
{
    int i;

    for (i = 0; i < Max; i++)
    {
        if (strcmp(tabela[i].Matricula, "") != 0)
        {
            imprimeFuncionario(tabela, tabela[i].Matricula);
        }
    }

}

int main()
{
    int idade;
    char Matricula[limite];
    char nome[tam];
    char entrada[tam];
    float salario;

    Funcionario empresa[Max];
    zeraFuncionario(empresa);
    int opcao = 0;

    while (opcao != 5) {

        printf("\nQue acao deseja realizar?\n\n"
       "1- Adicionar funcionario\n"
       "2- Remover funcionario\n"
       "3- Imprimir funcionario\n"
       "4- Imprimir todos os funcionarios\n"
       "5- Sair\n--------------------------------------------------------------\n");
    
        scanf("%d", &opcao);
            
        switch(opcao) {
            case 1: 

                //Caso o usuario digitar a quantidade dos numeros de matricula errado.
                do
                {
                    printf("\nInforme o numero da matricula com 5 digitos:\n");
                    scanf("%49s", entrada);
                    
                    if (strlen(entrada) != 5)
                    {
                        printf("Erro: a matricula deve possuir exatamente 5 digitos.\n");
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

                adicionaFuncionario(empresa, Matricula,nome, idade, salario);

                break;

            case 2: 

                printf("\nQual a matricula do funcionario que deseja remover?\n");
                scanf("%5s", Matricula);
                removerFuncionario(empresa, Matricula);
                break;

            case 3: 
            
                printf("\nInforme a matricula de um funcionario:\n");
                scanf("%5s", Matricula);
                printf("\n");
                imprimeFuncionario(empresa,Matricula);
                break;

            case 4: 
                imprimeFuncionarios(empresa);
                break;
            
            case 5:

                break;

            default: 
                printf("\nOpcao invalida\n");
                break;
        }
    }
    printf("\nFinalizando o programa...\n");
    return 0;
}

   