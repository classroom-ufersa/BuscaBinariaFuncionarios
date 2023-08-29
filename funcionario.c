//Implementação da TAD Funcionario e das funções que manipulam a TAD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionario.h"

struct funcionario
{
    char nome[21], cargo[21], documento[21];
};

void resgitra_funcionario(Funcionario *funcionario, FILE *arquivo)
{
    funcionario = (Funcionario *) malloc(sizeof(Funcionario));

    arquivo = fopen("funcionario.txt", "a");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    
    printf("Informe o nome:");
    scanf(" %[^\n]", funcionario->nome);
    printf("Informe o cargo:");
    scanf(" %[^\n]", funcionario->cargo);
    printf("Informe o documento:");
    scanf(" %[^\n]", funcionario->documento);

    fprintf(arquivo, "%s\n%s\n%s\n", funcionario->nome, funcionario->cargo, funcionario->documento);

    fclose(arquivo);
    free(funcionario);
}

int quantifica_funcionarios(FILE *arquivo)
{
    int nlinhas = 0, c;
    arquivo = fopen("funcionario.txt", "rt");
    if(arquivo == NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }
    while((c = fgetc(arquivo)) != EOF){
        if(c == '\n'){
            nlinhas++;
        }
    }
    return nlinhas/3;
}

Funcionario *carrega_dados(Funcionario *funcionarios, FILE *arquivo, int nfuncionarios)
{
    int i;
    funcionarios = (Funcionario *) malloc(nfuncionarios * sizeof(Funcionario));
    if (funcionarios == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }
    
    arquivo = fopen("funcionario.txt", "rt");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    for (i = 0; i < nfuncionarios; i++) {
        fscanf(arquivo, "%s", funcionarios[i].nome);
        fscanf(arquivo, "%s", funcionarios[i].cargo);
        fscanf(arquivo, "%s", funcionarios[i].documento);
    }

    for (i = 0; i < nfuncionarios; i++) {
        printf("%s\n%s\n%s\n", funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].documento);
    }

    fclose(arquivo);
    return funcionarios;
}

void libera_funcionarios(Funcionario *funcionarios)
{
    free(funcionarios);
}

