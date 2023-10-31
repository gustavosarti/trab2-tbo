#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "PQ.h"

struct NO{

    int vertex; 
    double priority;

};

struct priority_queue{

    NO* queue;
    int size; //tamanho atual
    int N;    //quant maxima de elementos

    //TODO map (nao sei como funciona)
};


//Funções ----------------------------------------------------------------------------

PQ* PQ_create(int N){

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