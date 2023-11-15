#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/entrada.h"
#include "../include/heap.h"

double* dijkstra(Grafo* grafo, int src) {
    double* dist = (double*) malloc(grafo->V * sizeof(double));
    HeapBinario* heap = criarHeap(grafo->V);

    for (int v = 0; v < grafo->V; ++v) {
        dist[v] = __DBL_MAX__;
        if(v==src){
            heap->pos[src] = src;
            dist[src] = 0;
        }
        heap->array[v] = criarNoHeap(v, dist[v]);
        heap->pos[v] = v;
    }
    diminuirChave(heap, src, dist[src]);

    heap->tamanho = grafo->V;

    while (!vazio(heap)) {
        NoHeap* noHeap = extrairMin(heap);
        int u = noHeap->v;

        //printf("Extraiu o mínimo do heap: %d\n", u);

        for (int v = 0; v < grafo->V; ++v) {
            if (isInHeap(heap, v) && grafo->arestas[u][v] && dist[u] != __DBL_MAX__ && dist[u]+grafo->arestas[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo->arestas[u][v];
                diminuirChave(heap, v, dist[v]);

                //printf("Atualizou a distância do vértice %d para %f\n", v, dist[v]);
            }
        }
        free(noHeap);
    }
    liberaHeap(heap);
    return dist;
}

double** calcularTodasDistancias(Grafo* grafo) {
    int total = grafo->S + grafo->C + grafo->M;
    double** distancias = (double**) malloc(total * sizeof(double*));
    int index = 0;
    for (int i = 0; i < grafo->S; i++) {
        distancias[index++] = dijkstra(grafo, grafo->servidores[i]);
    }
    for (int i = 0; i < grafo->C; i++) {
        distancias[index++] = dijkstra(grafo, grafo->clientes[i]);
    }
    for (int i = 0; i < grafo->M; i++) {
        distancias[index++] = dijkstra(grafo, grafo->monitores[i]);
    }
    return distancias;
}

void imprimirDistancias(double** distancias, Grafo* grafo) {
    int total = grafo->S + grafo->C + grafo->M;
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < grafo->V; j++) {
            printf("Distância entre %d e %d: %lf\n", i, j, distancias[i][j]);
        }
    }
}

void liberarDistancias(double** distancias, Grafo* grafo) {
    int total = grafo->S + grafo->C + grafo->M;
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < grafo->V; j++) {
            free(distancias[i]);
        }
        free(distancias);
    }
    
}