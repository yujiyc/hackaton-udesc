#ifndef QUEUE_PRIV_H
#define QUEUE_PRIV_H

#include "queue_pub.h"

struct Queue
{
    void *data;    // ponteiro para o array de dados genéricos
    int front;     // índice do início da fila (posição do próximo a sair)
    int rear;      // índice da próxima posição de inserção
    int count;     // número atual de elementos na fila
    int length;    // tamanho máximo da fila (número de elementos)
    int data_size; // tamanho de cada elemento (em bytes)
};

#endif