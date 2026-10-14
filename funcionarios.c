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
    int posicao = 0;
    int i;

    if (existe != -1)
    {
        printf("Erro: matricula ja cadastrada.\n");
        return;
    }

    int indiceVazio = buscaFuncionario(tabela, "");

    if (indiceVazio == -1)
    {
        printf("Nao eh possivel adicionar um funcionario: tabela cheia.\n");
        return;
    }

    for(posicao = 0; posicao < indiceVazio; posicao++)
    {
        //Comparar os nomes por ordem alfabética
       if(strcmp( nome_new, tabela[posicao].Nome) < 0 )
       {
            break;
       }
    }
    //Da direita para a esquerda atribui-se o valor no qual estava o antigo para copiar ele novamente
    for(i = indiceVazio; i > posicao; i--){

        tabela[i] = tabela[i-1];
        
    }
    //Para assim ser substituído pelos valores que foram adicionados pelo usuário.
    strcpy(tabela[posicao].Matricula, matricula_new);
    strcpy(tabela[posicao].Nome, nome_new);
    tabela[posicao].idade = idade_new;
    tabela[posicao].salario = salario_new;

    printf("Funcionario cadastrado com sucesso\n");
}

//Removendo um funcionario
void removerFuncionario(Funcionario tabela[], char matriculabusca[])
{
    int k = buscaFuncionario(tabela, matriculabusca);
    int i;

    if (k == -1)
    {
        printf("Funcionario nao encontrado.\n");
        return;
    }
    else
    {
        strcpy(tabela[k].Nome, "");
        strcpy(tabela[k].Matricula, "");
        tabela[k].salario = 0.0;
        tabela[k].idade = 0;

        printf("Funcionario removido.\n");
    }

    for(i = k; i < Max - 1; i++){
        tabela[i]= tabela[i+1];
    }

    strcpy(tabela[Max - 1].Matricula, "");
    strcpy(tabela[Max - 1].Nome, "");
    tabela[Max - 1].idade = 0;
    tabela[Max - 1].salario = 0.0;
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
//Função para o CSV:
void salvarCSV(Funcionario tabela[])
{
    int i;
    FILE *arquivo;

    arquivo = fopen("funcionarios.csv", "w");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    //Salvando apenas os dados dos funcionários que foram preenchidos, caso não, a repetição não guarda os valores vazios.
    for(i = 0; i < Max; i++)
    {
        if(strcmp(tabela[i].Matricula, "") != 0){
            fprintf(arquivo, "%s;%s;%d;%.2f\n",
            tabela[i].Matricula,
            tabela[i].Nome,
            tabela[i].idade,
            tabela[i].salario);
        }
        else{
            break;
        }    
    }
    
    fclose(arquivo);
}

void carregarCSV(Funcionario tabela[])
{
    int i = 0;
    FILE *arquivo;

    arquivo = fopen("funcionarios.csv", "r");

    if (arquivo == NULL)
    {
        return;
    }
    while(i < Max &&  fscanf(arquivo, " %5[^;];%49[^;];%d;%f",
           tabela[i].Matricula,
           tabela[i].Nome,
           &tabela[i].idade,
           &tabela[i].salario) == 4){
       
        i++;
    }

    fclose(arquivo);
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
    carregarCSV(empresa);
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

                salvarCSV(empresa);

                break;

            case 2: 

                printf("\nQual a matricula do funcionario que deseja remover?\n");
                scanf("%5s", Matricula);
                removerFuncionario(empresa, Matricula);

                salvarCSV(empresa);
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

   