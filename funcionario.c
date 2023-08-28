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

<<<<<<< HEAD
void resgitra_funcionario(Funcionario *funcionario, FILE *arquivo)
{
    funcionario = (Funcionario *) malloc(sizeof(Funcionario));

=======
void resgitra_funcionario(FILE *arquivo)
{
    Funcionario funcionario;
>>>>>>> da486ed355509616ad863e0df2187d77ccc71378
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

<<<<<<< HEAD
Funcionario *carrega_dados(Funcionario *funcionarios, FILE *arquivo)
=======
Funcionario *retorna_funcionarios(Funcionario *funcionarios, FILE *arquivo)
>>>>>>> da486ed355509616ad863e0df2187d77ccc71378
{
    int nfuncionarios = quantifica_funcionarios(arquivo), i;

<<<<<<< HEAD
    funcionarios = (Funcionario *) malloc(nfuncionarios * sizeof(Funcionario));
=======
    funcionarios = (Funcionario *) malloc(quant_funcionarios * sizeof(Funcionario));
>>>>>>> da486ed355509616ad863e0df2187d77ccc71378
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
<<<<<<< HEAD
    return funcionarios;
}

=======

    return funcionarios;
}

/*int buscaBinaria(Funcionario *vetor, int tamanho) 
{
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor) {
            return meio;
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}
*/

>>>>>>> da486ed355509616ad863e0df2187d77ccc71378
void libera_funcionarios(Funcionario *funcionarios)
{
    free(funcionarios);
}
