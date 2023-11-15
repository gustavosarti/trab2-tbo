#include <stdlib.h>
#include <stdio.h>
#include "../include/heap.h"

HeapBinario* criarHeap(int capacidade) {
    HeapBinario* heap = (HeapBinario*) malloc(sizeof(HeapBinario));
    heap->pos = (int *)malloc(capacidade * sizeof(int));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    heap->array = (NoHeap**) malloc(capacidade * sizeof(NoHeap*));
    return heap;
}

NoHeap* criarNoHeap(int v, double dist) {
    NoHeap* noHeap = (NoHeap*) malloc(sizeof(NoHeap));
    noHeap->v = v;
    noHeap->dist = dist;
    return noHeap;
}

void liberaHeap(HeapBinario* heap) {
    if(heap->array) {
        for (int i = 0; i < heap->tamanho; i++) {
            if(heap->array[i]) {
                free(heap->array[i]);
                heap->array[i] = NULL;
            }
        }
        free(heap->array);
        heap->array = NULL;
    }
    if(heap->pos) {
        free(heap->pos);
        heap->pos = NULL;
    }
    free(heap);
    heap = NULL;
}

void trocarNoHeap(NoHeap** a, NoHeap** b) {
    NoHeap* t = *a;
    *a = *b;
    *b = t;
}

void heapify(HeapBinario* heap, int idx) {
    int menor, esquerda, direita;
    menor = idx;
    esquerda = 2 * idx + 1;
    direita = 2 * idx + 2;

    if (esquerda < heap->tamanho && heap->array[esquerda]->dist < heap->array[menor]->dist)
        menor = esquerda;

    if (direita < heap->tamanho && heap->array[direita]->dist < heap->array[menor]->dist)
        menor = direita;

    if (menor != idx) {
        NoHeap *menorNo = heap->array[menor];
        NoHeap *idxNo = heap->array[idx];

        heap->pos[menorNo->v] = idx;
        heap->pos[idxNo->v] = menor;

        trocarNoHeap(&heap->array[menor], &heap->array[idx]);

        heapify(heap, menor);
    }
}

int vazio(HeapBinario* heap) {
    return heap->tamanho == 0;
}

NoHeap* extrairMin(HeapBinario* heap) {
    if (vazio(heap))
        return NULL;

    NoHeap* root = heap->array[0];

    NoHeap* ultimoNo = heap->array[heap->tamanho - 1];
    heap->array[0] = ultimoNo;

    heap->pos[root->v] = heap->tamanho-1;
    heap->pos[ultimoNo->v] = 0;

    --heap->tamanho;
    heapify(heap, 0);

    return root;
}

void diminuirChave(HeapBinario* heap, int v, double dist) {
    int i = heap->pos[v];

    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->v] = (i-1)/2;
        heap->pos[heap->array[(i-1)/2]->v] = i;
        trocarNoHeap(&heap->array[i],  &heap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

int isInHeap(HeapBinario* heap, int v) {
   if (heap->pos[v] < heap->tamanho)
     return 1;
   return 0;
}