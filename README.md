# Grupo 6 - Busca de String com Busca Binária

# Problema

Implemente um algoritmo que manipula um tipo estruturado Funcionários e possui a funcionalidade de buscar os funcionários em um arquivo

# Como Exercutar
- Windows: gcc -c funcionario.c & gcc -c main.c & gcc -o prog.exe funcionario.o main.o & prog.exe
- Linux: gcc -c funcionario.c && gcc -c main.c && gcc -o prog funcionario.o main.o && ./prog

# Sobre a Busca Binária
- Descrição:
Busca binária é um algoritmo eficiente para encontrar um elemento específico em uma lista ordenada. Ele funciona dividindo repetidamente a lista pela metade e comparando o valor do elemento desejado com o valor do elemento no meio da lista. Se os valores forem iguais, o elemento foi encontrado. Se o valor do elemento desejado for menor, a busca é realizada na metade inferior da lista. Se o valor for maior, a busca é realizada na metade superior da lista. Esse processo é repetido até que o elemento seja encontrado ou até que a lista seja reduzida a zero. A busca binária tem uma complexidade de tempo de O(log n), o que a torna uma opção eficiente para pesquisar elementos em grandes listas ordenadas.

- Funcionamento:

Passo 1: Inicialize três variáveis, inicio e fim, representando os índices do início e do fim do vetor, respectivamente, e meio para armazenar o índice médio.

Passo 2: Entre em um loop enquanto inicio for menor ou igual a fim. Isso garante que continuaremos a busca até que a área de pesquisa seja reduzida a um único elemento.

Passo 3: Calcule o índice médio, meio, como a média de inicio e fim. Isso nos permite dividir o vetor em duas partes aproximadamente iguais.

Passo 4: Verifique se o elemento no índice meio do vetor é igual ao valor que estamos procurando. Se for igual, encontramos o valor e retornamos meio, que é o índice do valor no vetor.

Passo 5: Se o elemento no índice meio for menor que o valor que estamos procurando, atualizamos inicio para meio + 1. Isso significa que o valor que estamos procurando está à direita de meio, e a próxima iteração do loop considerará apenas a metade direita do vetor.

Passo 6: Se o elemento no índice meio for maior que o valor que estamos procurando, atualizamos fim para meio - 1. Isso indica que o valor que estamos procurando está à esquerda de meio, e a próxima iteração do loop considerará apenas a metade esquerda do vetor.

Passo 7: Repita os passos 3 a 6 até encontrar o valor desejado ou até que inicio seja maior que fim, indicando que o valor não está presente no vetor.

Passo 8: Se o loop terminar e o valor não for encontrado, retorne -1 para indicar que o valor não está no vetor.

![Funcionamento da Busca Binária](https://carlacastanho.github.io/Material-de-APC/assets/images/Busca/binaryVSlinear.gif)

## Análise de Complexidade: 
- Busca Por Nome:
```
int buscaBinariaNome(Funcionario *funcionarios, int nfuncionarios, char *nome)
{
    qsort(funcionarios, nfuncionarios, sizeof(Funcionario), compararNomes); //c1, 1 vez
    int inicio = 0; //c2, 1 vez
    int fim = nfuncionarios - 1; //c3, 1 vez
    int meio; //c4, 1 vez
    while (inicio <= fim) { //c5*log₂(nfuncionarios) vezes 
        meio = (inicio + fim) / 2; //c6*log₂(nfuncionarios) vezes 
        int comparacao = strcmp(funcionarios[meio].nome, nome); //c7*log₂(nfuncionarios) vezes 
        if (comparacao == 0) { //c8*log₂(nfuncionarios) vezes 
            return meio; //c9, 1 vez
        } else if (comparacao < 0) { //c10*log₂(nfuncionarios) vezes 
            inicio = meio + 1; //c11*log₂(nfuncionarios) vezes 
        } else {
            fim = meio - 1; //c12*log₂(nfuncionarios) vezes 
        }
    }
    return -1; //c13, 1 vez
}
```

- Busca Por Documento:
```
int buscaBinariaDocumento(Funcionario *funcionarios, int nfuncionarios, char *documento)
{
    qsort(funcionarios, nfuncionarios, sizeof(Funcionario), compararDocumentos); //c1, 1 vez
    int inicio = 0; //c2, 1 vez
    int fim = nfuncionarios - 1; //c3, 1 vez
    int meio; //c4, 1 vez
    while (inicio <= fim){ //c5*log₂(tamanho) vezes 
        meio = (inicio + fim) / 2; //c6*log₂(tamanho) vezes 
        int comparacao = strcmp(funcionarios[meio].documento, documento); //c7*log₂(nfuncionarios) vezes 
        if (comparacao == 0){ //c8*log₂(nfuncionarios) vezes 
            return meio; //c9, 1 vez
        } else if (comparacao < 0){ //c10*log₂(nfuncionarios) vezes 
            inicio = meio + 1; //c11*log₂(nfuncionarios) vezes 
        } else {
            fim = meio - 1; //c12*log₂(nfuncionarios) vezes 
        }
    }
    return -1; //c13, 1 vez
}
```
```
- A Complexidade em Ambas Funções é:

T(n) = c1+c2+c3+c4+c5*log₂(n)+c6*log₂(n)+c7*log₂(n)+c8*log₂(n)+c9+c10*log₂(n)+c11*log₂(n)+c12*log₂(n)+c13

T(n) = c1+c2+c3+c4+c9+c13+c5*log₂(n)+c6*log₂(n)+c7*log₂(n)+c8*log₂(n)+c10*log₂(n)+c11*log₂(n)+c12*log₂(n)

T(n) = c1+c2+c3+c4+c9+c13+c5+log₂(n)*(c5+c6+c7+c8+c10+c11+c12)

T(n) = A+log₂(n)*(B)

O(n) = log₂(n) 
```