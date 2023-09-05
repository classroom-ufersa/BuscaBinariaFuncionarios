#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "funcionario.h"

struct funcionario
{
    char nome[21], cargo[21], documento[21];
};

void formataString(char nome[21])
{
    int i = 0;
    for(i = 0; nome[i] != '\0'; i++){
        nome[i] = toupper(nome[i]); 
    }
}

int verificaString(char nome[21])
{
    int i;
    for(i = 0; i < strlen(nome); i++) {
        if (!isalnum(nome[i])) {
            printf("Entrada Inválido\n");
            return 0;
        }
    }
    return 1;
}

int compararNomes(const void *a, const void *b)
{
    Funcionario *funcionarioA = (Funcionario *)a;
    Funcionario *funcionarioB = (Funcionario *)b;
    return strcmp(funcionarioA->nome, funcionarioB->nome);
}

int compararDocumentos(const void *a, const void *b)
{
    Funcionario *funcionarioA = (Funcionario *)a;
    Funcionario *funcionarioB = (Funcionario *)b;
    return strcmp(funcionarioA->documento, funcionarioB->documento);
}

void LimpaBuffer(void)
{
    int valorLido;
    do
    {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

void registraFuncionario(Funcionario *funcionario, FILE *arquivo, char *nome, char *cargo, char *documento)
{
    funcionario = (Funcionario *) malloc(sizeof(Funcionario));
    if(funcionario == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    arquivo = fopen("funcionarios.txt", "a");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    strcpy(funcionario->nome, nome);
    strcpy(funcionario->cargo, cargo);
    strcpy(funcionario->documento, documento);
    fprintf(arquivo, "%s\n%s\n%s\n", funcionario->nome, funcionario->cargo, funcionario->documento);
    LimpaBuffer();
    fclose(arquivo);
}

int quantificaFuncionarios(FILE *arquivo)
{
    int nlinhas = 0, c;
    arquivo = fopen("funcionarios.txt", "rt");
    if(arquivo == NULL){
        printf("Erro ao abrir!\n");
        exit(1);
    }
    while((c = fgetc(arquivo)) != EOF){
        if(c == '\n'){
            nlinhas++;
        }
    }
    return nlinhas/3;
}

Funcionario *carregaDados(Funcionario *funcionarios, FILE *arquivo, int nfuncionarios)
{
    int i;
    funcionarios = (Funcionario *) malloc(nfuncionarios * sizeof(Funcionario));
    if (funcionarios == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }
    
    arquivo = fopen("funcionarios.txt", "rt");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    for (i = 0; i < nfuncionarios; i++) {
        fscanf(arquivo, "%s", funcionarios[i].nome);
        fscanf(arquivo, "%s", funcionarios[i].cargo);
        fscanf(arquivo, "%s", funcionarios[i].documento);
    }

    LimpaBuffer();
    fclose(arquivo);
    return funcionarios;
}

void liberaFuncionarios(Funcionario *funcionarios)
{
    free(funcionarios);
}

int buscaBinariaNome(Funcionario *funcionarios, int nfuncionarios, char *nome)
{
    qsort(funcionarios, nfuncionarios, sizeof(Funcionario), compararNomes);
    int inicio = 0;
    int fim = nfuncionarios - 1;
    int meio;
    while (inicio <= fim){
        meio = (inicio + fim) / 2;
        
        int comparacao = strcmp(funcionarios[meio].nome, nome);
        
        if (comparacao == 0){
            return meio;
        } else if (comparacao < 0){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}


int buscaBinariaDocumento(Funcionario *funcionarios, int nfuncionarios, char *documento)
{
    qsort(funcionarios, nfuncionarios, sizeof(Funcionario), compararDocumentos);
    int inicio = 0;
    int fim = nfuncionarios - 1;
    int meio;
    while (inicio <= fim){
        meio = (inicio + fim) / 2;
        
        int comparacao = strcmp(funcionarios[meio].documento, documento);
        
        if (comparacao == 0){
            return meio;
        } else if (comparacao < 0){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}


