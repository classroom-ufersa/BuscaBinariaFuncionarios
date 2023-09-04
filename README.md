# Grupo 6 - Busca de String com Busca Binária

# Problema

Implemente um algoritmo que manipula um tipo estruturado Funcionários e possui a funcionalidade de buscar os funcionários em um arquivo

# Como Exercutar
- Windows: gcc -c funcionario.c && gcc -c main.c && gcc -o prog.exe funcionario.o main.o && ./prog
- Linux: gcc -c funcionario.c && gcc -c main.c && gcc -o prog funcionario.o main.o && ./prog

Busca binária é um algoritmo eficiente para encontrar um elemento específico em uma lista ordenada. Ele funciona dividindo repetidamente a lista pela metade e comparando o valor do elemento desejado com o valor do elemento no meio da lista. Se os valores forem iguais, o elemento foi encontrado. Se o valor do elemento desejado for menor, a busca é realizada na metade inferior da lista. Se o valor for maior, a busca é realizada na metade superior da lista. Esse processo é repetido até que o elemento seja encontrado ou até que a lista seja reduzida a zero. A busca binária tem uma complexidade de tempo de O(log n), o que a torna uma opção eficiente para pesquisar elementos em grandes listas ordenadas.

![Funcionamento da Busca Binária](https://carlacastanho.github.io/Material-de-APC/assets/images/Busca/binaryVSlinear.gif)

## Análise de Complexidade: 
- Busca Por Nome:
```
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
```

- Busca Por Documento:
```
int buscaBinariaDocumento(Funcionario *funcionarios, int nfuncionarios, char *documento)
{
    qsort(funcionarios, nfuncionarios, sizeof(Funcionario), compararDocumentos);

    int inicio = 0;
    int fim = nfuncionarios - 1;
    int meio;
    
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        
        int comparacao = strcmp(funcionarios[meio].documento, documento);
        
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
```