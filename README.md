# strings_com_busca_binaria
Busca de strings com busca binária

Implemente um alogritmo que manipula um tipo estruturado  Funcionários e possui a funcionalidade de buscar os funcionários em um arquivo.

Os funcionários devem ter os atributos básicos:

Nome;

Cargo;

Documento;

Requisitos:

A cada execução do progama,ele deve carregar os dados (armazenados em um arquivo texto);

O programa deve perguntar ao usuário qual funcionário ele deseja buscar por nome ou documento com o algoritmo Busca Binária;

Compute o tempo de execução do processo de busca.

Informe a complexidade do algoritmo Busca Binária.

Compilando: gcc -c funcionario.c && gcc -c main.c && gcc -o prog funcionario.o main.o && ./prog

O programa apresenta um menu com opções para registrar funcionários, buscar funcionários por nome ou documento, listar funcionários em ordem alfabética pelo nome e listar funcionários em ordem alfabética pelo documento.

Análise de Complexidade:

*registraFuncionario(Funcionario funcionario, FILE arquivo)

Complexidade de tempo:

As operações scanf para a entrada de nome e cargo são O(1), pois o tamanho máximo é limitado a 20 caracteres.
A cópia de strings usando strcpy é linear em relação ao tamanho da string, ou seja, O(1) para nome e cargo.
A escrita no arquivo é O(1) para cada atributo do funcionário.
A função chama LimpaBuffer(), que é linear em relação ao número de caracteres lidos até encontrar um caractere de nova linha '\n' ou EOF.
Portanto, a complexidade total é O(1).

Complexidade de espaço: A função aloca dinamicamente um espaço para um funcionário usando malloc, que é O(1) em relação ao número de funcionários.

*quantificaFuncionarios(FILE arquivo)

Complexidade de tempo: A função lê o arquivo linha por linha e conta o número de linhas, que é linear em relação ao tamanho do arquivo. Portanto, a complexidade é O(N), onde 'N' é o número de linhas no arquivo.

Complexidade de espaço: A função não aloca espaço adicional dependente dos dados de entrada. A complexidade de espaço é constante, O(1).

**carregaDados(Funcionario funcionarios, FILE arquivo, int nfuncionarios)

Complexidade de tempo: A função lê os atributos de todos os funcionários do arquivo, onde o número de iterações é igual a nfuncionarios. Portanto, a complexidade é O(nfuncionarios).

Complexidade de espaço: A função aloca espaço para armazenar os dados de nfuncionarios funcionários, portanto, a complexidade de espaço é O(nfuncionarios).

*liberaFuncionarios(Funcionario funcionarios)

Complexidade de tempo: A função apenas libera a memória alocada para os funcionários, o que é linear em relação ao número de funcionários, ou seja, O(nfuncionarios).

Complexidade de espaço: A função não alocou espaço adicional além dos funcionários, portanto, a complexidade de espaço é constante, O(1).

**compararNomes(const void a, const void b)

Complexidade de tempo: A função realiza uma comparação de strings usando strcmp, que é linear em relação ao tamanho das strings. Portanto, a complexidade é O(1).

Complexidade de espaço: A função não aloca espaço adicional dependente dos dados de entrada. A complexidade de espaço é constante, O(1).

**compararDocumentos(const void a, const void b)

Complexidade de tempo: A função realiza uma comparação de strings usando strcmp, que é linear em relação ao tamanho das strings. Portanto, a complexidade é O(1).

Complexidade de espaço: A função não aloca espaço adicional dependente dos dados de entrada. A complexidade de espaço é constante, O(1).

*buscaBinariaNome(Funcionario funcionarios, int nfuncionarios) e *buscaBinariaDocumento(Funcionario funcionarios, int nfuncionarios)

Complexidade de tempo: A função realiza uma pesquisa binária, que é O(log n), onde 'n' é o número de funcionários.

Complexidade de espaço: A função não aloca espaço adicional dependente dos dados de entrada. A complexidade de espaço é constante, O(1).

Tipo de busca:

Busca binária é um algoritmo eficiente para encontrar um elemento específico em uma lista ordenada. Ele funciona dividindo repetidamente a lista pela metade e comparando o valor do elemento desejado com o valor do elemento no meio da lista. Se os valores forem iguais, o elemento foi encontrado. Se o valor do elemento desejado for menor, a busca é realizada na metade inferior da lista. Se o valor for maior, a busca é realizada na metade superior da lista. Esse processo é repetido até que o elemento seja encontrado ou até que a lista seja reduzida a zero. A busca binária tem uma complexidade de tempo de O(log n), o que a torna uma opção eficiente para pesquisar elementos em grandes listas ordenadas.

![Funcionamento da Busca Binária](https://carlacastanho.github.io/Material-de-APC/assets/images/Busca/binaryVSlinear.gif)

## Análise de Complexidade: BuscaBinariaNome


int buscaBinariaNome(Funcionario *funcionarios, int nfuncionarios, char *nome)
{
    qsort(funcionarios, nfuncionarios, sizeof(Funcionario), compararNomes);

    int inicio = 0;
    int fim = nfuncionarios - 1;
    int meio;
    
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        
        int comparacao = strcmp(funcionarios[meio].nome, nome);
        
        if (comparacao == 0) {
            return meio;
        } else if (comparacao < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    return -1;
}
