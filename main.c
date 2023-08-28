#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

int main(void)
{
  int opcao1, opcao2, quant_funcionarios;
  Funcionario *funcionarios;
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
      resgitra_funcionario(arquivo); break;
      
      case 2:
      quant_funcionarios = quant_linhas(arquivo);
      funcionarios = returna_funcionarios(funcionarios, arquivo);
      buscaBinaria(funcionarios, quant_funcionarios);
      libera_funcionarios(funcionarios);

    }
  }
  while(opcao1 != 3);

  return 0;
}

