#pragma once
#include <stdbool.h>

typedef int ELEMENT_TYPE;

typedef struct circular_queue {
	size_t capacity;
	size_t front;
	size_t rear;
	ELEMENT_TYPE* nodes;
} circular_queue_t;

void cq_init_queue(circular_queue_t** queue, size_t capacity);

void cq_enqueue(circular_queue_t** queue, ELEMENT_TYPE data);
ELEMENT_TYPE cq_dequeue(circular_queue_t** queue);
ELEMENT_TYPE cq_peek(circular_queue_t* queue);

bool cq_is_empty(const circular_queue_t* queue);
bool cq_is_full(const circular_queue_t* queue);

void cq_print_all(const circular_queue_t* queue);
void cq_destroy_all(circular_queue_t** queue);
