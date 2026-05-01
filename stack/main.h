#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include "stack_pub.h"

void assert_fail_to_create_stack_from_non_null_pointer();
void assert_fail_to_pop_from_null_stack();
void assert_fail_to_push_from_null_stack();
void assert_fail_to_top_from_null_stack();
void assert_fail_to_clean_null_stack();
void assert_fail_to_unstack_null_stack();
void assert_fail_to_pop_from_empty_stack();
void assert_fail_to_push_to_full_stack();
void assert_success_when_pushing_sequence_of_integers();
void assert_success_when_pushing_sequence_of_doubles();
void assert_success_when_pushing_sequence_of_custom_structs();
void assert_top_returns_last_pushed_value();
void assert_popped_values_match_stack_order();

#endif
