#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"

int main() {
    const char *nomeArquivo = "entrada.txt"; // Nome do arquivo de entrada

    int numVertices, numArestas, numServidores, numClientes, numMonitores;
    int *servidores, *clientes, *monitores;
    Aresta *arestas;

    lerEntrada(nomeArquivo, &numVertices, &numArestas, &numServidores, &numClientes, &numMonitores, &servidores, &clientes, &monitores, &arestas);

    // Seu código para o restante do programa aqui

    // Não esqueça de liberar a memória alocada:
    free(servidores);
    free(clientes);
    free(monitores);
    free(arestas);

    return 0;
}
