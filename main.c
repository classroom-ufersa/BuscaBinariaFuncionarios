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

  //Laço de repetição para o menu de opções
  do
  {
    printf("\n========== MENU ==========\n");
    printf("1 - Registrar Funcionário\n");
    printf("2 - Buscar Funcionário\n");
    printf("3 - Sair\n");
    scanf(" %d", &opcao1);
    
    switch(opcao1)
    {
      //Caso opção 1: Registrar Funcionário
      case 1:
            //Laço de reptição para verificar se a string contém caracteres especiais
            do{
                printf("Informe o Nome: ");
                scanf(" %20[^\n]", nome);
                resultadoString = verificaString(nome);
                //Se resultadoString receber 0 o laço continua até receber a entrada correta
            }while (resultadoString == 0);
            resultadoString = 0;

            //Laço de reptição para verificar se a string contém caracteres especiais
            do{
                printf("Informe o Cargo: ");
                scanf(" %20[^\n]", cargo);
                resultadoString = verificaString(cargo);
                //Se resultadoString receber 0 o laço continua até receber a entrada correta
            } while (resultadoString == 0);
            resultadoString = 0;

            //Laço de reptição para verificar se a string contém caracteres especiais
            do{
                printf("Informe o Documento: ");
                scanf(" %20[^\n]", documento);
                //Se resultadoString receber 0 o laço continua até receber a entrada correta
                resultadoString = verificaString(documento);
            }while (resultadoString == 0);
            resultadoString = 0;

            //Chamada das funções para formatar as strings para maiúsculo
            formataString(nome);
            formataString(cargo);

            //Chamda da função que irá registrar um novo funcionário
            registraFuncionario(funcionario, arquivo, nome, cargo, documento);
            printf("Funcionário Cadastrado Com Sucesso!\n");
            break;
      
      //Caso opção 2: Buscar Funcionário
      case 2:
            printf("\n=== OPÇÕES DE BUSCA ===\n");
            printf("1 - Buscar Pelo Nome\n");
            printf("2 - Buscar Pelo Documento\n");
            scanf(" %d", &opcao2);

            switch(opcao2)
            {
              //Caso opção 1: Buscar Pelo Nome
              case 1:
                    //Laço de reptição para verificar se a string contém caracteres especiais
                    do{
                        printf("Informe o Nome: ");
                        scanf(" %20[^\n]", nome);
                        //Se resultadoString receber 0 o laço continua até receber a entrada correta
                        resultadoString = verificaString(nome);
                    }while (resultadoString == 0);
                    resultadoString = 0;

                    //Chamada da função para formatar a string para maiúsculo
                    formataString(nome);

                    //Chamada da função para saber a quantidade de funcionários
                    totalFuncionarios = quantificaFuncionarios(arquivo);

                    //Chamada da função para copiar os dados do arquivo para um vetor de funcionários
                    funcionario = carregaDados(funcionario, arquivo, totalFuncionarios);

                    clock_t inicioBuscaNome = clock();
                    //Chamda da função para buscar um funcionário pelo nome
                    resultado = buscaBinariaNome(funcionario, totalFuncionarios, nome);

                    ////Calcula o tempo de execução da função buscaBinariaNome
                    double tempo = (double)(clock() - inicioBuscaNome) / CLOCKS_PER_SEC;
                    printf("RESULTADO:\n");

                    //Informa se o funcionário foi encontrado
                    if(resultado == -1){
                      printf("\nFuncionário Não Encontrado\n\n");
                    } else{
                      printf("Funcionário Encontrado\n");
                    }

                    //Informa o tempo de execução da função buscaBinariaDocumento
                    printf("Tempo de execução: %f\n", tempo);

                    //Libera a memória do vetor de funcionários
                    liberaFuncionarios(funcionario);
                    break;

              //Caso opção 1: Buscar Pelo Documento
              case 2:
                    //Laço de reptição para verificar se a string contém caracteres especiais
                    do{
                        printf("Informe o Documento: ");
                        scanf(" %20[^\n]", documento);
                        resultadoString = verificaString(documento);
                        //Se resultadoString receber 0 o laço continua até receber a entrada correta
                    }while (resultadoString == 0);
                    resultadoString = 0;

                    //Chamada da função para formatar a string para maiúsculo
                    formataString(documento);

                    //Chamada da função para saber a quantidade de funcionários
                    totalFuncionarios = quantificaFuncionarios(arquivo);

                    //Chamada da função para copiar os dados do arquivo para um vetor de funcionários
                    funcionario = carregaDados(funcionario, arquivo, totalFuncionarios);
                    
                    clock_t inicioBuscaDocumento = clock();
                    //Chamda da função para buscar um funcionário pelo documento
                    resultado = buscaBinariaDocumento(funcionario, totalFuncionarios, documento);

                    //Calcula o tempo de execução da função buscaBinariaDocumento
                    tempo = (double)(clock() - inicioBuscaDocumento) / CLOCKS_PER_SEC;
                    printf("RESULTADO:\n");
                    if(resultado == -1){
                      printf("Funcionário Não Encontrado\n");
                    } else{
                      printf("Funcionário Encontrado\n");
                    }

                    //Informa o tempo de execução da função buscaBinariaDocumento
                    printf("Tempo de execução: %f\n", tempo);

                    //Libera a memória do vetor de funcionários
                    liberaFuncionarios(funcionario);
                    break;

              default:
                    //Informa o usuário sobre a entrada errada
                    printf("Opção Inválida\n");
                    break;
            }
            break;
      default:
            //Informa o usuário sobre a entrada errada
            if(opcao1 != 3){
                printf("Opção Inválida\n");
            }
    }
  }while(opcao1 != 3); //Condição para sair do primeiro laço while

  //Informa o usuário sobre o encerramento do programa
  printf("Programa Encerrado\n");
  return 0;
}
