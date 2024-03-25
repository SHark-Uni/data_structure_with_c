#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "circular_queue_SLL.h"

/*typedef struct sll_queue_node {
	ELEMENT_TYPE data;
	sll_queue_node_t* next;
} sll_queue_node_t;

typedef struct sll_queue {
	sll_queue_node_t* front;
	sll_queue_node_t* rear;

	sll_queue_node_t* head;
}sll_queue_t;
*/
void sll_enqueue(sll_queue_t* queue, ELEMENT_TYPE data)
{
	sll_queue_node_t* new_node = NULL;

	// EMTPY CASE
	if (sll_is_empty(queue)) {
		new_node = malloc(sizeof(sll_queue_node_t));
		new_node->data = data;

		queue->head = new_node;
		queue->front = new_node;
		queue->rear = new_node;

		new_node->next = queue->front;
		return;
	}

	new_node = malloc(sizeof(sll_queue_node_t));
	new_node->data = data;

	queue->rear->next = new_node;
	queue->rear = new_node;

	queue->rear->next = queue->front;
	return;
}

ELEMENT_TYPE sll_dequeue(sll_queue_t* queue)
{
	ELEMENT_TYPE ret = 0;
	sll_queue_node_t* front = queue->front;
	sll_queue_node_t* rear = queue->rear;
	sll_queue_node_t* delete_node;

	if (sll_is_empty(queue)) {
		return -1;
	}

	//one element
	if (front == rear) {
		ret = queue->front->data;
		free(queue->front);

		queue->front = NULL;
		queue->rear = NULL;
		queue->head = NULL;

		return ret;
	}

	delete_node = front;
	ret = delete_node->data;

	queue->head = delete_node->next;
	queue->front = delete_node->next;
	rear->next = delete_node->next;
	free(delete_node);
	return ret;
}

ELEMENT_TYPE sll_peek(const sll_queue_t* queue)
{
	if (sll_is_empty(queue)) {
		return -1;
	}
	return queue->front->data;
}

bool sll_is_empty(const sll_queue_t* queue)
{
	if (queue->head == NULL) {
		return true;
	}
	return false;
}

void sll_print_all_node(const sll_queue_t* queue)
{
	sll_queue_node_t* cur_node = queue->front;
	sll_queue_node_t* rear = queue->rear;

	if (sll_is_empty(queue)) {
		return;
	}
	assert(queue->head != NULL);

	while (cur_node != rear) {
		printf("%d ", cur_node->data);
		cur_node = cur_node->next;
	}
	printf("%d\n", rear->data);
}

void sll_destroy_all_node(sll_queue_t* queue)
{
	sll_queue_node_t* front = queue->front;
	sll_queue_node_t* rear = queue->rear;
	sll_queue_node_t* delete_node;


	while (front != rear) {
		delete_node = front;
		front = front->next;
		free(delete_node);
	}
	free(rear);
	queue->rear = NULL;
	queue->front = NULL;
	queue->head = NULL;
}
