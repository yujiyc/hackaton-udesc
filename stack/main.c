#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define ASSERT(cond, name) \
    printf("%s: %s\n", (cond) ? "SUCCESS" : "FAIL", name)

int main(int argc, char *argv[]) {
    assert_fail_to_create_stack_from_non_null_pointer();
    assert_fail_to_pop_from_null_stack();
    assert_fail_to_push_from_null_stack();
    assert_fail_to_top_from_null_stack();
    assert_fail_to_clean_null_stack();
    assert_fail_to_unstack_null_stack();
    assert_fail_to_pop_from_empty_stack();
    assert_fail_to_push_to_full_stack();
    assert_success_when_pushing_sequence_of_integers();
    assert_success_when_pushing_sequence_of_doubles();
    assert_success_when_pushing_sequence_of_custom_structs();
    assert_top_returns_last_pushed_value();
    assert_popped_values_match_stack_order();

    return 0;
}

void assert_fail_to_create_stack_from_non_null_pointer() {
    pStack p_stack = (pStack)0x1;
    ASSERT(stack(&p_stack, 10, sizeof(int)) == FAIL, "assert_fail_to_create_stack_from_non_null_pointer");
}

void assert_fail_to_pop_from_null_stack() {
    int value = 0;
    ASSERT(pop(NULL, &value) == FAIL && pop((pStack)0x1, NULL) == FAIL && value == 0, "assert_fail_to_pop_from_null_stack");
}

void assert_fail_to_push_from_null_stack() {
    int value = 0;
    ASSERT(push(NULL, &value) == FAIL && push((pStack)0x1, NULL) == FAIL && value == 0, "assert_fail_to_push_from_null_stack");
}

void assert_fail_to_top_from_null_stack() {
    int value = 0;
    ASSERT(top(NULL, &value) == FAIL && top((pStack)0x1, NULL) == FAIL && value == 0, "assert_fail_to_top_from_null_stack");
}

void assert_fail_to_clean_null_stack() {
    ASSERT(cleanStack(NULL) == FAIL, "assert_fail_to_clean_null_stack");
}

void assert_fail_to_unstack_null_stack() {
    pStack p_stack = NULL;
    ASSERT(unstack(NULL) == FAIL && unstack(&p_stack) == FAIL, "assert_fail_to_unstack_null_stack");
}

void assert_fail_to_pop_from_empty_stack() {
    pStack p_stack = NULL;
    int value = 0;
    stack(&p_stack, 10, sizeof(int));
    ASSERT(pop(p_stack, &value) == FAIL && value == 0, "assert_fail_to_pop_from_empty_stack");
    unstack(&p_stack);
}

void assert_fail_to_push_to_full_stack() {
    pStack p_stack = NULL;
    int values[] = {10, 20, 30, 40, 50};
    stack(&p_stack, 4, sizeof(int));
    for (int i = 0; i < 4; i++) push(p_stack, &values[i]);
    ASSERT(push(p_stack, &values[4]) == FAIL && values[4] == 50, "assert_fail_to_push_to_full_stack");
    unstack(&p_stack);
}

void assert_success_when_pushing_sequence_of_integers() {
    pStack p_stack = NULL;
    int values[] = {10, 20, 30, 40, 50};
    stack(&p_stack, 5, sizeof(int));
    int ok = 1;
    for (int i = 0; i < 5; i++) {
        if (push(p_stack, &values[i]) == FAIL) {
            ok = 0;
            break;
        }
    }
    ASSERT(ok, "assert_success_when_pushing_sequence_of_integers");
    unstack(&p_stack);
}

void assert_success_when_pushing_sequence_of_doubles() {
    pStack p_stack = NULL;
    double values[] = {10.3, 20.2, 30.7, 40.5, 50.9};
    stack(&p_stack, 5, sizeof(double));
    int ok = 1;
    for (int i = 0; i < 5; i++) {
        if (push(p_stack, &values[i]) == FAIL) {
            ok = 0;
            break;
        }
    }
    ASSERT(ok, "assert_success_when_pushing_sequence_of_doubles");
    unstack(&p_stack);
}

void assert_success_when_pushing_sequence_of_custom_structs() {
    struct T { int a; int b; } values[] = { {1,2}, {3,4}, {5,6}, {7,8}, {9,10} };
    pStack p_stack = NULL;
    stack(&p_stack, 5, sizeof(struct T));
    int ok = 1;
    for (int i = 0; i < 5; i++) {
        if (push(p_stack, &values[i]) == FAIL) {
            ok = 0;
            break;
        }
    }
    ASSERT(ok, "assert_success_when_pushing_sequence_of_custom_structs");
    unstack(&p_stack);
}

void assert_top_returns_last_pushed_value() {
    pStack p_stack = NULL;
    int values[] = {10, 20, 30, 40, 50};
    int topValue = 0;
    stack(&p_stack, 5, sizeof(int));
    for (int i = 0; i < 5; i++) push(p_stack, &values[i]);
    ASSERT(top(p_stack, &topValue) == SUCESS && topValue == values[4], "assert_top_returns_last_pushed_value");
    unstack(&p_stack);
}

void assert_popped_values_match_stack_order() {
    pStack p_stack = NULL;
    int values[] = {10, 20, 30, 40, 50};
    int result[5] = {0};
    stack(&p_stack, 5, sizeof(int));
    for (int i = 0; i < 5; i++) push(p_stack, &values[i]);
    for (int i = 0; i < 5; i++) pop(p_stack, &result[i]);
    int ok = result[0] == values[4] &&
             result[1] == values[3] &&
             result[2] == values[2] &&
             result[3] == values[1] &&
             result[4] == values[0];
    ASSERT(ok, "assert_popped_values_match_stack_order");
    unstack(&p_stack);
}