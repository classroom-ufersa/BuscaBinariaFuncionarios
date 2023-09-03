//Implementação da interface das funções
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>

typedef struct funcionario Funcionario;

void registra_funcionario(Funcionario *funcionario, FILE *arquivo);

int quantifica_funcionarios(FILE *arquivo);

Funcionario *carrega_dados(Funcionario *funcionarios, FILE *arquivo, int nfuncionarios);

void libera_funcionarios(Funcionario *funcionarios);

int compararNomes(const void *a, const void *b);

int compararDocumentos(const void *a, const void *b);

int buscaBinariaNome(Funcionario *funcionarios, int nfuncionarios);

int buscaBinariaDocumento(Funcionario *funcionarios, int nfuncionarios);

#endif
