#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"

int main() {
    const char *nomeArquivo = "entrada.txt"; // Nome do arquivo de entrada

    int numVertices, numArestas, numServidores, numClientes, numMonitores;
    int *servidores, *clientes, *monitores;
    Aresta *arestas;

    lerEntrada(nomeArquivo, &numVertices, &numArestas, &numServidores, &numClientes, &numMonitores, &servidores, &clientes, &monitores, &arestas);

    // Verifique se os dados foram armazenados corretamente
    printf("Número de vértices: %d\n", numVertices);
    printf("Número de arestas: %d\n", numArestas);
    printf("Número de servidores: %d\n", numServidores);
    printf("Número de clientes: %d\n", numClientes);
    printf("Número de monitores: %d\n", numMonitores);

    printf("Nós servidores: ");
    for (int i = 0; i < numServidores; i++) {
        printf("%d ", servidores[i]);
    }
    printf("\n");

    printf("Nós clientes: ");
    for (int i = 0; i < numClientes; i++) {
        printf("%d ", clientes[i]);
    }
    printf("\n");

    printf("Nós monitores: ");
    for (int i = 0; i < numMonitores; i++) {
        printf("%d ", monitores[i]);
    }
    printf("\n");

    printf("Arestas:\n");
    for (int i = 0; i < numArestas; i++) {
        printf("%d -> %d, Peso: %lf\n", arestas[i].origem, arestas[i].destino, arestas[i].peso);
    }

    // Seu código para o restante do programa aqui

    // Não esqueça de liberar a memória alocada:
    free(servidores);
    free(clientes);
    free(monitores);
    free(arestas);

    return 0;
}
