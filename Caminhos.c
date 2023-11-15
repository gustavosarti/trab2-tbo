#include "../include/Caminhos.h"
#include "../include/Dijkstra.h"
#include <stdlib.h>
#include <stdio.h>

Caminho* calcularCaminhos(Grafo* grafo, double** distancias) {
    int num_servidores = grafo->S;
    int num_clientes = grafo->C;

    Caminho* caminhos = (Caminho*) malloc(num_servidores * num_clientes * sizeof(Caminho));
    if (caminhos == NULL) {
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < num_servidores; i++) {
        for (int j = 0; j < num_clientes; j++) {
            caminhos[index].x = grafo->servidores[i];
            caminhos[index].y = grafo->clientes[j];
            caminhos[index].valor_rtt = (double) (distancias[i][grafo->clientes[j]] + distancias[num_servidores + j][grafo->servidores[i]]);
            //printf("Caminho[%d]: Servidor %d -> Cliente %d, RTT = %f\n", index, caminhos[index].x, caminhos[index].y, caminhos[index].valor_rtt);
            index++;
        }
    }

    return caminhos;
}

Caminho* calcularCaminhosInflados(Grafo* grafo, double** distancias){
    int num_servidores = grafo->S;
    int num_clientes = grafo->C;
    int num_monitor = grafo->M;

    double Servidor_Monitor, Monitor_Clientes, monitor=-1;


    Caminho* caminhos_inflados = (Caminho*) malloc(num_servidores * num_clientes * sizeof(Caminho));
    if (caminhos_inflados == NULL) {
        return NULL;
    }

    int index = 0;
    for(int i=0; i<num_servidores; i++){
        for(int j=0; j<num_clientes; j++){
            monitor=-1;
            for(int k=0; k<num_monitor; k++){
                Servidor_Monitor = distancias[i][grafo->monitores[k]] + distancias[num_servidores + num_clientes + k][grafo->servidores[i]];
                Monitor_Clientes = distancias[num_servidores + j][grafo->monitores[k]] + distancias[num_servidores + num_clientes + k][grafo->clientes[j]];
            
                if(monitor > Servidor_Monitor + Monitor_Clientes){ monitor = Servidor_Monitor + Monitor_Clientes; }
                else if(monitor == -1)
                    monitor = Servidor_Monitor + Monitor_Clientes;        
            }

            caminhos_inflados[index].x = grafo->servidores[i];
            caminhos_inflados[index].y = grafo->clientes[j];
            caminhos_inflados[index].valor_rtt = monitor;
            index++;
        }
    }
    return caminhos_inflados;
}

int compararCaminhos(const void* a, const void* b) {
    double razaoA = ((Caminho*)a)->valor_rtt;
    double razaoB = ((Caminho*)b)->valor_rtt;
    if (razaoA < razaoB) return -1;
    if (razaoA > razaoB) return 1;
    return 0;
}

Caminho* calcularRazoes(Grafo* grafo){
    double** distancias = calcularTodasDistancias(grafo);

    Caminho* caminhos = calcularCaminhos(grafo, distancias);
    Caminho* caminhos_inflados = calcularCaminhosInflados(grafo, distancias);

    for (int i = 0; i < grafo->S + grafo->C + grafo->M; i++) {
        free(distancias[i]);
    }
    free(distancias);

    Caminho* razoes = (Caminho*) malloc(grafo->S * grafo->C * sizeof(Caminho));
    if (razoes == NULL) {
        free(caminhos);
        free(caminhos_inflados);
        return NULL;
    }

    for(int i=0; i< (grafo->S * grafo->C); i++){
        razoes[i].x = caminhos[i].x;
        razoes[i].y = caminhos[i].y;
        razoes[i].valor_rtt = caminhos_inflados[i].valor_rtt/caminhos[i].valor_rtt;
    }

    free(caminhos);
    free(caminhos_inflados);

    return razoes;
}