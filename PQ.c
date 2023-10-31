#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "PQ.h"

struct NO{

    int vertex; 
    double priority;

};

struct priority_queue{

    NO* queue; //vertice e prioridade 
    int size; //tamanho atual
    int N;    //quant maxima de elementos

    //TODO map (nao sei como funciona)
};


//Função para criar o nó----------------------------------------------------------------------------------
NO* inicia_no(int vertice, double prioridade){
    //prioridade aqui seria a distancia

    NO* no;
    no->vertex = vertice;
    no->priority = prioridade;

}

//Funções da fila de prioridade----------------------------------------------------------------------------

PQ* PQ_create(int N){
    PQ* pq = (PQ*)malloc(sizeof(PQ));

    pq->queue = malloc(pq->N * sizeof(NO*));
    pq->N = N + 1;
    pq->size = 0;

}


bool PQ_empty(PQ* pq){
    return pq->size == 0;
}


int PQ_size(PQ* pq){

}


void PQ_insert(PQ* pq, int v){

}


//void PQ_removemin(PQ* pq){}


void PQ_destroy(PQ* pq){
    free(pq->queue);
    //free(map)

    free(pq);
}


//TODO FIX UP E FIX DOWN

void fix_down(PQ *pq, int k){
    while (2*k <= pq->size) {
        int j = 2*k;
        if (j < pq->size && (pq->queue[j].priority > pq->queue[j+1].priority)){
          j++;
        }
        if (pq->queue[k].priority < pq->queue[j].priority)) {
            break;
        }
        
        
        //exch(a[k], a[j]);
        //TODO trocar esse exch por uma função de swap 

        k = j;
    }
}
