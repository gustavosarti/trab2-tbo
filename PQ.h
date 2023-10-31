#ifndef PQ_H
#define PQ_H


typedef struct no NO;
typedef struct priority_queue PQ;

//Inicia uma nova fila de prioridade
PQ* PQ_create(int max_size);

//libera a memória que foi alocada para a fila
void PQ_destroy(PQ* pq);

//checa para ver se a fila está vazia
bool PQ_empty(PQ* pq);

//retorna o tamanho da fila
int PQ_size(PQ* pq);

//insere o valor v na fila
void PQ_insert(PQ* pq, int v);

//remove o evento de menor prioridade
void PQ_removemin(PQ* pq);


#endif //PQ_H
