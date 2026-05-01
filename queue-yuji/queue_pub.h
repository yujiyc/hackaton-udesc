#ifndef QUEUE_PUB_H
#define QUEUE_PUB_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

typedef struct Queue *pQueue, **ppQueue;

// "Construtor": aloca memória e inicializa as variáveis
int cQueue(ppQueue pf, int size, int sizedata);
// "Destrutor": libera memória da estrutura
int dQueue(ppQueue pf);

// **** "Operações de manipulação" ****
// Enfileira um elemento
int queue(pQueue f, void *element);
// Desenfileira um elemento
int unqueue(pQueue f, void *element);
// Limpa a fila (mantém a estrutura alocada, só remove dados)
int cleanQueue(pQueue f);

// **** "Operações de acesso" ****
// Retorna o tamanho máximo da fila
int sizeQueue(pQueue f);

#endif