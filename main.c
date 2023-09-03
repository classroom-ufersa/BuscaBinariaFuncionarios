#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

int main(void)
{
  int opcao1, opcao2, nfuncionarios, resultado;
  Funcionario *funcionario = NULL; 
  FILE *arquivo = NULL; 

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
      printf("\n1 - Buscar Pelo Nome\n");
      printf("2 - Buscar Pelo Documento\n");
      scanf(" %d", &opcao2);
      switch(opcao2)
      {
        case 1:
        nfuncionarios = quantifica_funcionarios(arquivo);

        funcionario = carrega_dados(funcionario, arquivo, nfuncionarios);

        resultado = buscaBinariaNome(funcionario, nfuncionarios);
        if (resultado == -1){
          printf("Funcionário Não Encontrado\n\n");
        } else{
          printf("Funcionário Encontrado\n\n");
        }
        break;

        case 2:
        nfuncionarios = quantifica_funcionarios(arquivo);

        funcionario = carrega_dados(funcionario, arquivo, nfuncionarios);

        resultado = buscaBinariaDocumento(funcionario, nfuncionarios);
        if (resultado == -1){
          printf("Funcionário Não Encontrado\n\n");
        } else{
          printf("Funcionário Encontrado\n\n");
        }
        break;
      }
    }
  }while(opcao1 != 3); 
return 0;
}
