#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

int main(void)
{
  int opcao1, opcao2;
  Funcionario *funcionario;
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
      quantifica_funcionarios(arquivo);
      carrega_dados(funcionario, arquivo);
      libera_funcionarios(funcionario);

    }
  }
  while(opcao1 != 3);

  return 0;
}

