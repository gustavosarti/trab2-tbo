#ifndef ENTRADA_H
#define ENTRADA_H

// Estrutura para representar uma aresta do grafo
typedef struct {
    int origem;
    int destino;
    double peso;
} Aresta;

// Função para ler a entrada do programa a partir de um arquivo
void lerEntrada(const char *nomeArquivo, int *numVertices, int *numArestas, int *numServidores, int *numClientes, int *numMonitores, int **servidores, int **clientes, int **monitores, Aresta **arestas);

#endif
