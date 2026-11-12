#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct Funcionario Funcionario;

Funcionario *buscaFuncionario(Funcionario *inicio, char matricula[]);
Funcionario *adicionaFuncionario(Funcionario *inicio, char matricula[], char nome[], int idade, float salario);
Funcionario *removerFuncionario(Funcionario *inicio, char matricula[]);

void imprimeFuncionario(Funcionario *inicio, char matricula[]);
void imprimeFuncionarios(Funcionario *inicio);

void salvarCSV(Funcionario *inicio);
Funcionario *carregarCSV(Funcionario *inicio);

#endif