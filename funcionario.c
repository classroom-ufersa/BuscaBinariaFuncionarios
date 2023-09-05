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
    for(i = 0; nome[i] != '\0'; i++){ //Verifica se chegou no fim da string
        nome[i] = toupper(nome[i]); //Retorna cada caracter da string em maiúsculo
    }
}

int verificaString(char nome[21])
{
    int i;
    for(i = 0; i < strlen(nome); i++){ //Compara se i é menor do que o tamanho da string
        if (!isalnum(nome[i])){ //Verifica se a string contém caracteres alfanuméricos (letras e números) ou não.
            //Caso não contenha apenas caracteres alfanuméricos
            printf("Entrada Inválido\n"); 
            return 0;
        }
    }

    //Caso contenha apenas caracteres alfanuméricos
    return 1;
}

int compararNomes(const void *a, const void *b)
{
    Funcionario *funcionarioA = (Funcionario *)a; //Converte o ponteiro
    Funcionario *funcionarioB = (Funcionario *)b; //Converte o ponteiro
    return strcmp(funcionarioA->nome, funcionarioB->nome); //compara as strings 
}

int compararDocumentos(const void *a, const void *b)
{
    Funcionario *funcionarioA = (Funcionario *)a; //Converte o ponteiro
    Funcionario *funcionarioB = (Funcionario *)b; //Converte o ponteiro
    return strcmp(funcionarioA->documento, funcionarioB->documento); //compara as strings
}

void LimpaBuffer(void)
{
    int valorLido; //Armazena os valores lidos do buffer de entrada
    do
    {
        valorLido = getchar(); //Lê um caracter do buffer
    } while ((valorLido != '\n') && (valorLido != EOF)); //Continua até encontrar um caractere de nova linha e atingir o final do arquivo.
}

void registraFuncionario(Funcionario *funcionario, FILE *arquivo, char *nome, char *cargo, char *documento)
{
    //Aloca memória para um novo funcionário
    funcionario = (Funcionario *) malloc(sizeof(Funcionario)); 
    if(funcionario == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    //Abre o arquivo para escrever
    arquivo = fopen("funcionarios.txt", "a"); 
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    //Copia as string para os campos da struct
    strcpy(funcionario->nome, nome);
    strcpy(funcionario->cargo, cargo);
    strcpy(funcionario->documento, documento);

    //Escreve as string no arquivo
    fprintf(arquivo, "%s\n%s\n%s\n", funcionario->nome, funcionario->cargo, funcionario->documento);

    //Chama da função para limpar buffer
    LimpaBuffer();

    //Fecha o arquivo
    fclose(arquivo);
}

int quantificaFuncionarios(FILE *arquivo)
{
    int nlinhas = 0, c;

    //Abre o arquivo para ler
    arquivo = fopen("funcionarios.txt", "rt"); 
    if(arquivo == NULL){
        printf("Erro ao abrir!\n");
        exit(1);
    }

    //Conta a quantidade de linhas do arquivo
    while((c = fgetc(arquivo)) != EOF){
        if(c == '\n'){
            nlinhas++;
        }
    }

    //Retorna a quantidade de funcionários
    return nlinhas/3;
}

Funcionario *carregaDados(Funcionario *funcionarios, FILE *arquivo, int nfuncionarios)
{
    int i;

    //Aloca memória
    funcionarios = (Funcionario *) malloc(nfuncionarios * sizeof(Funcionario)); 
    if (funcionarios == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }
    
    //Abre o arquivo para ler
    arquivo = fopen("funcionarios.txt", "rt");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    //Lê os dados do arquivo e preenche os campos da struct
    for (i = 0; i < nfuncionarios; i++) {
        fscanf(arquivo, "%s", funcionarios[i].nome);
        fscanf(arquivo, "%s", funcionarios[i].cargo);
        fscanf(arquivo, "%s", funcionarios[i].documento);
    }   

    //Chama da função para limpar buffer
    LimpaBuffer();

    //Fecha o arquivo 
    fclose(arquivo);

    //Retorna o ponteiro para o vetor
    return funcionarios;
}

void liberaFuncionarios(Funcionario *funcionarios)
{
    //Libera a memória alocada
    free(funcionarios);
}

int buscaBinariaNome(Funcionario *funcionarios, int nfuncionarios, char *nome)
{
    //Chama da função para ordenar os vetores
    qsort(funcionarios, nfuncionarios, sizeof(Funcionario), compararNomes);
    int inicio = 0;
    int fim = nfuncionarios - 1;
    int meio;
    while (inicio <= fim){ //Verifica se chegou ao fim do vetor
        meio = (inicio + fim) / 2; //Descobre o índice na metade do vetor
        int comparacao = strcmp(funcionarios[meio].nome, nome); //Compara as strings
        if (comparacao == 0){ //Verifica se são iguais
            return meio; //Retorna o valor do índice
        } else if (comparacao < 0){ //Verifica se o nome no meio do vetor é "menor" que o nome buscado
            inicio = meio + 1; //Atualiza o índice de início para a metade superior do vetor
        } else {
            fim = meio - 1; //Caso contrário, atualiza o índice de fim para a metade inferior do vetor
        }
    }
    return -1; //Se o nome não foi encontrado
}

int buscaBinariaDocumento(Funcionario *funcionarios, int nfuncionarios, char *documento)
{
    //Chama da função para ordenar os vetores
    qsort(funcionarios, nfuncionarios, sizeof(Funcionario), compararDocumentos);
    int inicio = 0;
    int fim = nfuncionarios - 1;
    int meio;
    while (inicio <= fim){ //Verifica se chegou ao fim do vetor
        meio = (inicio + fim) / 2; //Descobre o índice na metade do vetor
        int comparacao = strcmp(funcionarios[meio].documento, documento); //Compara as strings
        if (comparacao == 0){ //Verifica se são iguais
            return meio; //Retorna o valor do índice
        } else if (comparacao < 0){ //Verifica se o nome no meio do vetor é "menor" que o nome buscado
            inicio = meio + 1; //Atualiza o índice de início para a metade superior do vetor
        } else { 
            fim = meio - 1; //Caso contrário, atualiza o índice de fim para a metade inferior do vetor
        }
    }
    return -1; //Se o nome não foi encontrado
}


