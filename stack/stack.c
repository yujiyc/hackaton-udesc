#include <memory.h>

#include "stack_pri.h"

int _is_stack_pointer_null(ppStack p_stack) {
    return *p_stack == NULL;
}

int _is_stack_empty(pStack p_stack) {
    return p_stack->length == 0;
}

int _is_stack_full(pStack p_stack) {
    return p_stack->length == p_stack->capacity;
}

void * _next_stack_position(pStack p_stack) {
    return (char *)p_stack->data + (p_stack->data_size * p_stack->length);
}

void * _current_stack_position(pStack p_stack) {
    return (char *)p_stack->data + (p_stack->data_size * (p_stack->length - 1));
}

void _free_stack_pointer(ppStack pp_stack) {
    if (*pp_stack == NULL) return;
    _free_stack_data(*pp_stack);
    free(*pp_stack);
    *pp_stack = NULL;
}

void _free_stack_data(pStack p_stack) {
    if (p_stack == NULL || p_stack->data == NULL) return;
    free(p_stack->data);
    p_stack->data = NULL;
}

int stack(ppStack pp, int size, int sizedata) {
    if (pp == NULL || *pp != NULL || size <= 0 || sizedata <= 0)
        return FAIL;

    *pp = malloc(sizeof(PE));
    if (*pp == NULL)
        return FAIL;

    (*pp)->capacity = size;
    (*pp)->data_size = sizedata;
    (*pp)->length = 0;
    (*pp)->data = malloc(size * sizedata);

    if ((*pp)->data == NULL) {
        free(*pp);
        *pp = NULL;
        return FAIL;
    }

    return SUCCESS;
}

int unstack(ppStack pp) {
    if (pp == NULL || *pp == NULL)
        return FAIL;

    _free_stack_pointer(pp);
    return SUCCESS;
}

int push(pStack p, void *element) {
    if (p == NULL || element == NULL || _is_stack_full(p))
        return FAIL;

    memcpy(_next_stack_position(p), element, p->data_size);
    p->length++;
    return SUCCESS;
}

int pop(pStack p, void *element) {
    if (p == NULL || element == NULL || _is_stack_empty(p))
        return FAIL;

    memcpy(element, _current_stack_position(p), p->data_size);
    p->length--;
    return SUCCESS;
}

int cleanStack(pStack p) {
    if (p == NULL)
        return FAIL;

    p->length = 0;
    return SUCCESS;
}

int top(pStack p, void *top) {
    if (p == NULL || top == NULL)
        return FAIL;

    memcpy(top, _current_stack_position(p), p->data_size);
    return SUCCESS;
}
