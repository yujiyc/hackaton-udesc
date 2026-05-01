#ifndef MAIN_H
#define MAIN_H

#include "queue_pub.h"
#include <stdio.h>
#include <stdlib.h>

void assert_fail_to_create_queue_from_non_null_pointer();
void assert_fail_to_queue_from_null();
void assert_fail_to_unqueue_from_null();
void assert_fail_to_clean_null_queue();
void assert_fail_to_destroy_null_queue();
void assert_fail_to_unqueue_from_empty_queue();
void assert_fail_to_queue_when_full();
void assert_success_when_queueing_sequence_of_integers();
void assert_unqueued_values_match_queue_order();

#endif