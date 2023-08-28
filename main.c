#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

int main(void)
{
<<<<<<< HEAD
  int opcao1, opcao2;
  Funcionario *funcionario;
=======
  int opcao1, opcao2, quant_funcionarios;
  Funcionario *funcionarios;
>>>>>>> da486ed355509616ad863e0df2187d77ccc71378
  FILE *arquivo;

  do
  {
    printf("MENU\n");
    printf("1 - Registrar Funcionário\n");
    printf("2 - Buscar Funcionário\n");
    printf("3 - Sair\n");
    scanf(" %d", &opcao1);
    switch(opcao1)
    {
      case 1:
      resgitra_funcionario(funcionario, arquivo); break;
      
      case 2:
<<<<<<< HEAD
      quantifica_funcionarios(arquivo);
      carrega_dados(funcionario, arquivo);
      libera_funcionarios(funcionario);
=======
      quant_funcionarios = quant_linhas(arquivo);
      funcionarios = returna_funcionarios(funcionarios, arquivo);
      buscaBinaria(funcionarios, quant_funcionarios);
      libera_funcionarios(funcionarios);
>>>>>>> da486ed355509616ad863e0df2187d77ccc71378

    }
  }
  while(opcao1 != 3);

  return 0;
}

