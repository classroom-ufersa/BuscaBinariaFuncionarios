//Implementação da interface das funções
#include <stdio.h>

typedef struct funcionario Funcionario;

// Função para registrar um novo funcionário e armazenar suas informações em um arquivo
void registraFuncionario(Funcionario *funcionario, FILE *arquivo);

// Função para contar o número de funcionários do arquivo
int quantificaFuncionarios(FILE *arquivo);

// Função para carregar dados de funcionários de um arquivo em um array 
Funcionario *carregaDados(Funcionario *funcionarios, FILE *arquivo, int nfuncionarios);

// Função para liberar a memória alocada para o array 
void liberaFuncionarios(Funcionario *funcionarios);


//Função para comparar nomes de funcionários para ordenação
int compararNomes(const void *a, const void *b);


//Função para comparar documentos de funcionários para ordenação
int compararDocumentos(const void *a, const void *b);


// Função para realizar uma busca binária de um funcionário pelo nome
int buscaBinariaNome(Funcionario *funcionarios, int nfuncionarios);


//Função para realizar uma busca binária de um funcionário pelo documento
int buscaBinariaDocumento(Funcionario *funcionarios, int nfuncionarios);