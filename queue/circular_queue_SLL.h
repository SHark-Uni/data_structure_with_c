#pragma once
#include <stdbool.h>
typedef int ELEMENT_TYPE;

typedef struct sll_queue_node {
	ELEMENT_TYPE data;
	struct sll_queue_node* next;
} sll_queue_node_t;

typedef struct sll_queue {
	sll_queue_node_t* front;
	sll_queue_node_t* rear;

	sll_queue_node_t* head;
}sll_queue_t;

void sll_enqueue(sll_queue_t* queue, ELEMENT_TYPE data);
ELEMENT_TYPE sll_dequeue(sll_queue_t* queue);

ELEMENT_TYPE sll_peek(const sll_queue_t* queue);
bool sll_is_empty(const sll_queue_t* queue);
void sll_print_all_node(const sll_queue_t* queue);

void sll_destroy_all_node(sll_queue_t* queue);