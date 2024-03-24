#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "circular_queue.h"

/*typedef struct circular_queue {
	size_t capacity;
	size_t front;
	size_t rear;
	ELEMENT_TYPE* nodes;
} circular_queue_t;
*/
void cq_init_queue(circular_queue_t** queue, size_t capacity)
{
	(*queue) = malloc(sizeof(circular_queue_t));

	//Dummy nodes 
	(*queue)->nodes = malloc(sizeof(ELEMENT_TYPE) * capacity);

	(*queue)->capacity = capacity;
	(*queue)->rear = -1;
	(*queue)->front = -1;
}

void cq_enqueue(circular_queue_t** queue, ELEMENT_TYPE data)
{
	size_t rear = 0;
	size_t capacity = 0;
	//EMPTY CASE
	if (cq_is_empty(*queue)) {
		(*queue)->front = 0;
		(*queue)->rear = 0;

		rear = (*queue)->rear;
		(*queue)->nodes[rear] = data;
		return;
	}
	// FULL
	if (cq_is_full(*queue)) {
		return;
	}

	capacity = (*queue)->capacity;
	rear = ((*queue)->rear + 1) % capacity;

	(*queue)->nodes[rear] = data;
	(*queue)->rear = rear;
	return;
}

ELEMENT_TYPE cq_dequeue(circular_queue_t** queue)
{
	ELEMENT_TYPE ret = -1;
	size_t front = 0;
	size_t capacity = 0;
	//EMPTY CASE
	if (cq_is_empty(*queue)) {
		fprintf(stderr, "QUEUE IS EMPTY!");
		return ret;
	}

	//just one element
	if ((*queue)->front == (*queue)->rear) {
		front = (*queue)->front;
		ret = (*queue)->nodes[front];
		(*queue)->front = -1;
		(*queue)->rear = -1;

		return ret;
	}

	front = (*queue)->front;
	capacity = (*queue)->capacity;
	ret = (*queue)->nodes[front];

	(*queue)->front = (front + 1) % capacity;
	return ret;
}

bool cq_is_empty(const circular_queue_t* queue)
{
	if ((queue->front == -1) && (queue->rear == -1)) {
		return true;
	}
	return false;
}

bool cq_is_full(const circular_queue_t* queue)
{
	size_t rear = queue->rear;
	size_t front = queue->front;
	size_t capacity = queue->capacity;

	if ((rear + 1) % capacity == front) {
		return true;
	}
	return false;
}

void cq_print_all(const circular_queue_t* queue)
{
	size_t front = queue->front;
	size_t rear = queue->rear;
	size_t capacity = queue->capacity;
	printf("== print _ all _ node ==\n");

	while (front != rear) {
		printf("%d ", queue->nodes[front]);
		front = (front + 1) % capacity;
	}
	printf("%d \n", queue->nodes[rear]);
}

void cq_destroy_all(circular_queue_t** queue)
{
	free((*queue)->nodes);
	free((*queue));
	*queue = NULL;
}

ELEMENT_TYPE cq_peek(circular_queue_t* queue)
{
	return queue->nodes[(queue->front)];
}

