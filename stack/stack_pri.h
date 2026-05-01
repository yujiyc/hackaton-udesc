#ifndef STACK_PRI_H
#define STACK_PRI_H

#include "stack_pub.h"

typedef struct PE {
    void * data;
    size_t data_size;
    size_t length;
    size_t capacity;
} PE;

int _is_stack_pointer_null(ppStack p_stack);
int _is_stack_empty(pStack p_stack);
int _is_stack_full(pStack p_stack);
void * _next_stack_position(pStack p_stack);
void * _current_stack_position(pStack p_stack);
void _free_stack_pointer(ppStack pp_stack);
void _free_stack_data(pStack p_stack);

#endif