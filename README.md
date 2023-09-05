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
    while (inicio <= fim) { //c5, log2(nfuncionarios) vezes
        meio = (inicio + fim) / 2; //c6, log2(nfuncionarios) vezes
        
        int comparacao = strcmp(funcionarios[meio].nome, nome); //c7, log2(nfuncionarios) vezes
        
        if (comparacao == 0) { //c8, log2(nfuncionarios) vezes
            return meio; //c9, log2(nfuncionarios) vezes
        } else if (comparacao < 0) { //c10, log2(nfuncionarios) vezes
            inicio = meio + 1; //c11, log2(nfuncionarios) vezes
        } else {
            fim = meio - 1; //c12, log2(nfuncionarios) vezes
        }
    }
    return -1; //c12, 1 vez
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
    while (inicio <= fim){ //c5, log2(nfuncionarios) vezes
        meio = (inicio + fim) / 2; //c6, log2(nfuncionarios) vezes
        
        int comparacao = strcmp(funcionarios[meio].documento, documento); //c7, log2(nfuncionarios) vezes
        
        if (comparacao == 0){ //c8, log2(nfuncionarios) vezes
            return meio; //c9, log2(nfuncionarios) vezes
        } else if (comparacao < 0){ //c10, log2(nfuncionarios) vezes
            inicio = meio + 1; //c11, log2(nfuncionarios) vezes
        } else {
            fim = meio - 1; //c12, log2(nfuncionarios) vezes
        }
    }
    return -1; //c13, 1 vez
}
```