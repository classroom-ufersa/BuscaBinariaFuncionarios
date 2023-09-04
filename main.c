#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcionario.h"

int main(void)
{
  int opcao1 = 0, opcao2 = 0, totalFuncionarios = 0, resultado = 0, resultadoString = 0;
  char nome[21], cargo[21], documento[21];
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
            do{
                printf("Informe o Nome: ");
                scanf(" %20[^\n]", nome);
                resultadoString = verificaString(nome);
            }while (resultadoString == 0);
            resultadoString = 0;

            do{
                printf("Informe o Cargo: ");
                scanf(" %20[^\n]", cargo);
                resultadoString = verificaString(cargo);
            } while (resultadoString == 0);
            resultadoString = 0;

            do{
                printf("Informe o Documento: ");
                scanf(" %20[^\n]", documento);
                resultadoString = verificaString(documento);
            }while (resultadoString == 0);
            resultadoString = 0;
            formataString(nome);
            formataString(cargo);
            registraFuncionario(funcionario, arquivo, nome, cargo, documento);
            break;
        
      case 2:
            printf("\nOpções de Busca\n");
            printf("1 - Buscar Pelo Nome\n");
            printf("2 - Buscar Pelo Documento\n");
            scanf(" %d", &opcao2);

            switch(opcao2)
            {
              case 1:
                    do{
                        printf("Informe o Nome: ");
                        scanf(" %20[^\n]", nome);
                        resultadoString = verificaString(nome);
                    }while (resultadoString == 0);
                    resultadoString = 0;
                    formataString(nome);

                    totalFuncionarios = quantificaFuncionarios(arquivo);

                    funcionario = carregaDados(funcionario, arquivo, totalFuncionarios);

                    resultado = buscaBinariaNome(funcionario, totalFuncionarios, nome);

                    if(resultado == -1){
                      printf("Funcionário Não Encontrado\n\n");
                    } else{
                      printf("Funcionário Encontrado\n\n");
                    }

                    liberaFuncionarios(funcionario);
                    break;

              case 2:
                    do{
                        printf("Informe o Documento: ");
                        scanf(" %20[^\n]", documento);
                        resultadoString = verificaString(documento);
                    }while (resultadoString == 0);
                    resultadoString = 0;

                    formataString(documento);

                    totalFuncionarios = quantificaFuncionarios(arquivo);

                    funcionario = carregaDados(funcionario, arquivo, totalFuncionarios);

                    resultado = buscaBinariaDocumento(funcionario, totalFuncionarios, documento);

                    if(resultado == -1){
                      printf("Funcionário Não Encontrado\n\n");
                    } else{
                      printf("Funcionário Encontrado\n\n");
                    }

                    liberaFuncionarios(funcionario);
                    break;

              default:
                    printf("Opção Inválida\n");
                    break;
            }
            break;
      default:
            if(opcao1 != 3){
                printf("Opção Inválida\n");
            }
    }
  }while(opcao1 != 3); 
  printf("Programa Encerrado\n");
  return 0;
}
