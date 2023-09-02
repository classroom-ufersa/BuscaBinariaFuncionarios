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
      resgitra_funcionario(funcionario, arquivo); 
      break;
      
  
      case 2:
            nfuncionarios = quantifica_funcionarios(arquivo);
            funcionario = carrega_dados(funcionario, arquivo, nfuncionarios);

            printf("1 - Buscar por Nome\n");
            printf("2 - Buscar por Documento\n");
            scanf(" %d", &opcao2);
            switch (opcao2)
            {
            case 1:
                buscaBinariaNome(funcionario, nfuncionarios);
                int posicaoNome = buscaBinariaNome(funcionario, nfuncionarios);
                if (posicaoNome == -1)
                {
                    printf("Nome não encontrado\n");
                }
                else
                {
                    printf("Nome encontrado na posição %d\n", posicaoNome);
                }
                break;

            case 2:
                buscaBinariaDocumento(funcionario, nfuncionarios);
                int posicaoDocumento = buscaBinariaDocumento(funcionario, nfuncionarios);
                if (posicaoDocumento == -1)
                {
                    printf("Documento não encontrado\n");
                }
                else
                {
                    printf("Documento encontrado na posição %d\n", posicaoDocumento);
                }
                break;

    if (posicaoNome == -1) {
        printf("Valor não encontrado\n");
    } else {
        printf("Valor encontrado na posição %d\n", posicaoNome);
    }
      
      libera_funcionarios(funcionario);
      break; 
    }

  } while(opcao1 != 3);

  return 0;
}

}
