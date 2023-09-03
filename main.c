#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcionario.h"

int main(void)
{
  int opcao1, opcao2, totalFuncionarios, resultado;
  Funcionario *funcionario = NULL; 
  FILE *arquivo = NULL; 

  do
  {
    printf("\nMENU\n");
    printf("1 - Registrar Funcionário\n");
    printf("2 - Buscar Funcionário\n");
    printf("3 - Sair\n");
    scanf(" %d", &opcao1);
    switch(opcao1)
    {
      case 1:
      resgitra_funcionario(funcionario, arquivo); break;

      case 2:
      printf("\nOpções de Busca\n");
      printf("1 - Buscar Pelo Nome\n");
      printf("2 - Buscar Pelo Documento\n");
      scanf(" %d", &opcao2);
      switch(opcao2)
      {
        case 1:
        totalFuncionarios = quantifica_funcionarios(arquivo);

        funcionario = carrega_dados(funcionario, arquivo, totalFuncionarios);

        resultado = buscaBinariaNome(funcionario, totalFuncionarios);

        if (resultado == -1){
          printf("Funcionário Não Encontrado\n\n");
        } else{
          printf("Funcionário Encontrado\n\n");
        }

        libera_funcionarios(funcionario); break;

        case 2:
        totalFuncionarios = quantifica_funcionarios(arquivo);

        funcionario = carrega_dados(funcionario, arquivo, totalFuncionarios);

        resultado = buscaBinariaDocumento(funcionario, totalFuncionarios);
        if (resultado == -1){
          printf("Funcionário Não Encontrado\n\n");
        } else{
          printf("Funcionário Encontrado\n\n");
        }

        libera_funcionarios(funcionario); break;

        default:
        printf("Opção Inválida.\n");
      }
      default:
        printf("Opção Inválida.\n");
    }
  }while(opcao1 != 3); 
return 0;
}
