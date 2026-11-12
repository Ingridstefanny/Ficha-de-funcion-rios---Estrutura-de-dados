#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "funcionarios.h"

#define tam 50
#define limite 6

struct Funcionario{
    
    char Matricula[limite];
    char Nome[tam];
    int idade;
    float salario;

    struct Funcionario *prox;
};

Funcionario *buscaFuncionario(Funcionario *inicio, char matriculabusca[])
{
    Funcionario *atual = inicio;
    while (atual != NULL)
    {
        if(strcmp(atual->Matricula, matriculabusca) == 0){
            return atual;
        }

        atual = atual->prox;
    }
    
    //Caso não existir:
    return NULL;
}

//Função para adicionar um funcionario
Funcionario *adicionaFuncionario(Funcionario *inicio, char matricula_new[], char nome_new[], int idade_new, float salario_new)
{
    
    if (buscaFuncionario(inicio, matricula_new) != NULL)
    {
        printf("\nErro: matricula ja cadastrada!\n");
        return inicio;
    }

    Funcionario *novo = malloc(sizeof(Funcionario));

    if(novo == NULL){
        printf("Erro ao alocar memoria!\n");
        return inicio;
    }
    
    strcpy(novo->Matricula, matricula_new);
    strcpy(novo->Nome, nome_new);
    novo->idade = idade_new;
    novo->salario = salario_new;

    novo->prox = NULL;
    Funcionario *atual = inicio;
    Funcionario *anterior = NULL;

        while (atual != NULL && strcmp(atual->Nome, novo->Nome) < 0){
            anterior = atual;
            atual = atual->prox;
        }
    

    if (anterior == NULL) {
        novo->prox = inicio;
        inicio = novo;
    } else {
        novo->prox = atual;
        anterior->prox = novo;
    }

    printf("Funcionario cadastrado com sucesso!\n");

    return inicio;
}

//Removendo um funcionario
Funcionario *removerFuncionario(Funcionario *inicio, char matriculabusca[])
{
    Funcionario *atual = inicio;
    Funcionario *anterior = NULL;

    while (atual != NULL && strcmp(atual->Matricula, matriculabusca) != 0){
        anterior = atual;
    atual = atual->prox;
    }
    
    if(atual == NULL){
       printf("\nFuncionario nao encontrado.\n");
       return inicio;
    }

    if(anterior == NULL){
        inicio = atual->prox;
    }
    else{
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("\nFuncionario removido com sucesso!\n");

    return inicio;
}
    
//Função para imprimir funcionários
void imprimeFuncionario(Funcionario *inicio, char matriculabusca[])
{
    Funcionario *funcionario = buscaFuncionario(inicio, matriculabusca);
    if (funcionario == NULL)
    { 
        printf("\nFuncionario nao encontrado!\n"); 
    }
    else
    {
       printf("\n----------------------------------------\n");
        printf("Matricula : %s\n", funcionario->Matricula);
        printf("Nome      : %s\n", funcionario->Nome);
        printf("Idade     : %d anos\n", funcionario->idade);
        printf("Salario   : R$ %.2f\n", funcionario->salario);
        printf("----------------------------------------\n");
    }
}

//Função para imprimir vários funcionarios
void imprimeFuncionarios(Funcionario *inicio)
{
    Funcionario *atual = inicio;

    while (atual != NULL){
        printf("\n----------------------------------------\n");
        printf("Matricula : %s\n", atual->Matricula);
        printf("Nome      : %s\n", atual->Nome);
        printf("Idade     : %d anos\n", atual->idade);
        printf("Salario   : R$ %.2f\n", atual->salario);
        printf("----------------------------------------\n");
        atual = atual->prox;
    }

}
//Função para o CSV:
void salvarCSV(Funcionario *inicio)
{
    Funcionario *atual = inicio;
    FILE *arquivo;

    arquivo = fopen("funcionarios-listaencadeada.csv", "w");

    if(arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    //Salvando apenas os dados dos funcionários que foram preenchidos, caso não, a repetição não guarda os valores vazios.
    while(atual != NULL)
    {
        fprintf(arquivo, "%s;%s;%d;%.2f\n",
        atual->Matricula,
        atual->Nome,
        atual->idade,
        atual->salario);

        atual = atual->prox;
    }
    
    fclose(arquivo);
}

Funcionario *carregarCSV(Funcionario *inicio) {

    FILE *arquivo = fopen("funcionarios-listaencadeada.csv", "r");

    if (arquivo == NULL) {
        return inicio;
    }

    char matricula[limite];
    char nome[tam];
    int idade;
    float salario;

    while (fscanf(arquivo, " %5[^;];%49[^;];%d;%f",
        matricula, nome, &idade, &salario) == 4) {

        inicio = adicionaFuncionario(
            inicio, matricula, nome, idade, salario
        );
    }

    fclose(arquivo);
    return inicio;
}