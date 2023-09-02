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
      nfuncionarios = quantifica_funcionarios(arquivo);

      funcionario = carrega_dados(funcionario, arquivo, nfuncionarios); // Aloque memória aqui

      buscaBinariaNome(funcionario, nfuncionarios);
      int posicao = buscaBinariaNome(funcionario, nfuncionarios);
    if (posicao == -1) {
        printf("Valor não encontrado\n");
    } else {
        printf("Valor encontrado na posição %d\n", posicao);
    }
      
      libera_funcionarios(funcionario);
      break; 
    }
  } while(opcao1 != 3);

  return 0;
}

