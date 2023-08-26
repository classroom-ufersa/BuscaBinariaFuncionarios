//Implementação da TAD Funcionario e das funções que manipulam a TAD
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "funcionario.h"

//Funcionario *ler_funcionarios(char *nome_arquivo, int *tamanho) {
//    FILE *arquivo = fopen(nome_arquivo, "w");
//   if (!arquivo) {
//        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
//        exit(1);
//    }

//   int num_funcionarios;
//    fscanf(arquivo, "%d", &num_funcionarios);

//    Funcionario *funcionarios = (Funcionario *)malloc(num_funcionarios * sizeof(Funcionario));
//    for (int i = 0; i < num_funcionarios; i++) {
//        fscanf(arquivo, "%s %s %s", funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].documento);
//    }
