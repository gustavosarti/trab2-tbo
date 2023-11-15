#include <stdio.h>
#include <stdlib.h>
#include "../include/entrada.h"

// Função para ler a entrada de um arquivo e criar um grafo
Grafo* ler_entrada(char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    Grafo* grafo = malloc(sizeof(Grafo));
    fscanf(arquivo, "%d %d", &(grafo->V), &(grafo->E));
    fscanf(arquivo, "%d %d %d", &(grafo->S), &(grafo->C), &(grafo->M));

    grafo->servidores = malloc(grafo->S * sizeof(int));
    grafo->clientes = malloc(grafo->C * sizeof(int));
    grafo->monitores = malloc(grafo->M * sizeof(int));

    for (int i = 0; i < grafo->S; i++) {
        fscanf(arquivo, "%d", &(grafo->servidores[i]));
    }

    for (int i = 0; i < grafo->C; i++) {
        fscanf(arquivo, "%d", &(grafo->clientes[i]));
    }

    for (int i = 0; i < grafo->M; i++) {
        fscanf(arquivo, "%d", &(grafo->monitores[i]));
    }

    grafo->arestas = malloc(grafo->V * sizeof(double*));
    for (int i = 0; i < grafo->V; i++) {
        grafo->arestas[i] = malloc(grafo->V * sizeof(double));
        for (int j = 0; j < grafo->V; j++) {
            grafo->arestas[i][j] = 0.0;
        }
    }

    for (int i = 0; i < grafo->E; i++) {
        int x, y;
        double z;
        fscanf(arquivo, "%d %d %lf", &x, &y, &z);
        grafo->arestas[x][y] = z;
    }

    fclose(arquivo);
    return grafo;
}

// Função para liberar a memória alocada para o grafo
void liberar_grafo(Grafo* grafo) {
    free(grafo->servidores);
    free(grafo->clientes);
    free(grafo->monitores);

    for (int i = 0; i < grafo->V; i++) {
        free(grafo->arestas[i]);
    }
    free(grafo->arestas);

    free(grafo);
}
