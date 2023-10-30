#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"

void lerEntrada(const char *nomeArquivo, int *numVertices, int *numArestas, int *numServidores, int *numClientes, int *numMonitores, int **servidores, int **clientes, int **monitores, Aresta **arestas) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }

    // Lê o número de vértices e arestas
    fscanf(arquivo, "%d %d", numVertices, numArestas);

    // Lê o número de servidores, clientes e monitores
    fscanf(arquivo, "%d %d %d", numServidores, numClientes, numMonitores);

    // Aloca memória para os conjuntos de servidores, clientes e monitores
    *servidores = (int *)malloc(sizeof(int) * (*numServidores));
    *clientes = (int *)malloc(sizeof(int) * (*numClientes));
    *monitores = (int *)malloc(sizeof(int) * (*numMonitores));

    // Lê os nós servidores
    for (int i = 0; i < *numServidores; i++) {
        fscanf(arquivo, "%d", &(*servidores)[i]);
    }

    // Lê os nós clientes
    for (int i = 0; i < *numClientes; i++) {
        fscanf(arquivo, "%d", &(*clientes)[i]);
    }

    // Lê os nós monitores
    for (int i = 0; i < *numMonitores; i++) {
        fscanf(arquivo, "%d", &(*monitores)[i]);
    }

    // Aloca memória para as arestas
    *arestas = (Aresta *)malloc(sizeof(Aresta) * (*numArestas));

    // Lê as arestas e seus pesos
    for (int i = 0; i < *numArestas; i++) {
        fscanf(arquivo, "%d %d %lf", &(*arestas)[i].origem, &(*arestas)[i].destino, &(*arestas)[i].peso);
    }

    fclose(arquivo);
}
