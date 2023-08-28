//Implementação da interface das funções
#include <stdio.h>
typedef struct funcionario Funcionario;

<<<<<<< HEAD
void resgitra_funcionario(Funcionario *funcionario, FILE *arquivo);
=======
void resgitra_funcionario(FILE *arquivo);
>>>>>>> da486ed355509616ad863e0df2187d77ccc71378

int quantifica_funcionarios(FILE *arquivo);

<<<<<<< HEAD
Funcionario *carrega_dados(Funcionario *funcionarios, FILE *arquivo);
=======
Funcionario returna_funcionario(FILE *arquivo);
>>>>>>> da486ed355509616ad863e0df2187d77ccc71378

void libera_funcionarios(Funcionario *funcionarios);
