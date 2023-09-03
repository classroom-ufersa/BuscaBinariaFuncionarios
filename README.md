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

Busca binária é um algoritmo eficiente para encontrar um elemento específico em uma lista ordenada. Ele funciona dividindo repetidamente a lista pela metade e comparando o valor do elemento desejado com o valor do elemento no meio da lista. Se os valores forem iguais, o elemento foi encontrado. Se o valor do elemento desejado for menor, a busca é realizada na metade inferior da lista. Se o valor for maior, a busca é realizada na metade superior da lista. Esse processo é repetido até que o elemento seja encontrado ou até que a lista seja reduzida a zero. A busca binária tem uma complexidade de tempo de O(log n), o que a torna uma opção eficiente para pesquisar elementos em grandes listas ordenadas.

![Alt text](image.png)