//Implementação da interface das funções
#include <stdio.h>
typedef struct funcionario Funcionario;

void *resgitra_funcionario(FILE *arquivo);

int quant_linhas(FILE *arquivo);

Funcionario *returna_vetor(FILE *arquivo);

void libera_vetor(Funcionario *funcionarios);
