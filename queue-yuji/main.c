#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define ASSERT(cond, name) \
    printf("%s: %s\n", (cond) ? "SUCCESS" : "FAIL", name)

int main(void) {
    assert_fail_to_create_queue_from_non_null_pointer();
    assert_fail_to_queue_from_null();
    assert_fail_to_unqueue_from_null();
    assert_fail_to_clean_null_queue();
    assert_fail_to_destroy_null_queue();
    assert_fail_to_unqueue_from_empty_queue();
    assert_fail_to_queue_when_full();
    assert_success_when_queueing_sequence_of_integers();
    assert_unqueued_values_match_queue_order();

    return 0;
}

void assert_fail_to_create_queue_from_non_null_pointer() {
    pQueue q = (pQueue)0x1;
    ASSERT(cQueue(&q, 5, sizeof(int)) == FAIL, "assert_fail_to_create_queue_from_non_null_pointer");
}

void assert_fail_to_queue_from_null() {
    int value = 42;
    ASSERT(queue(NULL, &value) == FAIL && queue((pQueue)0x1, NULL) == FAIL, "assert_fail_to_queue_from_null");
}

void assert_fail_to_unqueue_from_null() {
    int value = 0;
    ASSERT(unqueue(NULL, &value) == FAIL && unqueue((pQueue)0x1, NULL) == FAIL && value == 0, "assert_fail_to_unqueue_from_null");
}

void assert_fail_to_clean_null_queue() {
    ASSERT(cleanQueue(NULL) == FAIL, "assert_fail_to_clean_null_queue");
}

void assert_fail_to_destroy_null_queue() {
    pQueue q = NULL;
    ASSERT(dQueue(NULL) == FAIL && dQueue(&q) == FAIL, "assert_fail_to_destroy_null_queue");
}

void assert_fail_to_unqueue_from_empty_queue() {
    pQueue q = NULL;
    int value = 0;
    cQueue(&q, 3, sizeof(int));
    ASSERT(unqueue(q, &value) == FAIL && value == 0, "assert_fail_to_unqueue_from_empty_queue");
    dQueue(&q);
}

void assert_fail_to_queue_when_full() {
    pQueue q = NULL;
    int values[] = {1, 2, 3};
    cQueue(&q, 2, sizeof(int));
    queue(q, &values[0]);
    queue(q, &values[1]);
    ASSERT(queue(q, &values[2]) == FAIL, "assert_fail_to_queue_when_full");
    dQueue(&q);
}

void assert_success_when_queueing_sequence_of_integers() {
    pQueue q = NULL;
    int values[] = {5, 10, 15, 20, 25};
    cQueue(&q, 5, sizeof(int));
    int ok = 1;
    for (int i = 0; i < 5; i++) {
        if (queue(q, &values[i]) == FAIL) {
            ok = 0;
            break;
        }
    }
    ASSERT(ok, "assert_success_when_queueing_sequence_of_integers");
    dQueue(&q);
}

void assert_unqueued_values_match_queue_order() {
    pQueue q = NULL;
    int values[] = {11, 22, 33, 44, 55};
    int result[5] = {0};
    cQueue(&q, 5, sizeof(int));
    for (int i = 0; i < 5; i++) queue(q, &values[i]);
    for (int i = 0; i < 5; i++) unqueue(q, &result[i]);
    int ok = 1;
    for (int i = 0; i < 5; i++) {
        if (result[i] != values[i]) {
            ok = 0;
            break;
        }
    }
    ASSERT(ok, "assert_unqueued_values_match_queue_order");
    dQueue(&q);
}