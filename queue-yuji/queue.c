#include "queue_priv.h"

#include <memory.h>
#include <string.h>

// Cria e inicializa a fila
int cQueue(ppQueue pf, int length, int sizedata)
{
    if (pf == NULL || *pf != NULL || length <= 0 || sizedata <= 0)
        return FAIL;

    *pf = (pQueue)malloc(sizeof(struct Queue));
    if (*pf == NULL)
        return FAIL;

    (*pf)->data = malloc(length * sizedata);
    if ((*pf)->data == NULL)
    {
        free(*pf);
        *pf = NULL;
        return FAIL;
    }

    (*pf)->front = 0;
    (*pf)->rear = 0;
    (*pf)->count = 0;
    (*pf)->length = length;
    (*pf)->data_size = sizedata;

    return SUCCESS;
}

// Libera a memória da fila
int dQueue(ppQueue pf)
{
    if (pf == NULL || *pf == NULL)
        return FAIL;

    free((*pf)->data);
    free(*pf);
    *pf = NULL;

    return SUCCESS;
}

// Enfileira um novo elemento
int queue(pQueue f, void *element)
{
    if (f == NULL || element == NULL || f->count == f->length)
        return FAIL;

    void *target = (char *)f->data + (f->rear * f->data_size);
    memcpy(target, element, f->data_size);

    f->rear = (f->rear + 1) % f->length;
    f->count++;

    return SUCCESS;
}

// Desenfileira o elemento mais antigo
int unqueue(pQueue f, void *element)
{
    if (f == NULL || element == NULL || f->count == 0)
        return FAIL;

    void *source = (char *)f->data + (f->front * f->data_size);
    memcpy(element, source, f->data_size);

    f->front = (f->front + 1) % f->length;
    f->count--;

    return SUCCESS;
}
// Esvazia a fila sem desalocar
int cleanQueue(pQueue f)
{
    if (f == NULL)
        return FAIL;

    f->front = 0;
    f->rear = 0;
    f->count = 0;

    return SUCCESS;
}

// Retorna o tamanho máximo da fila
int sizeQueue(pQueue f)
{
    if (f == NULL)
        return FAIL;

    return f->length;
}