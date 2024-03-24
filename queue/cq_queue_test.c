#include <stdio.h>
#include <assert.h>
#include "circular_queue.h"

int main() {
	circular_queue_t* c_queue = NULL;
	size_t size = 5;

	{
		printf("TEST START: initial Queue TEST\n");
		cq_init_queue(&c_queue, size);
		assert(c_queue->front == -1);
		assert(c_queue->rear == -1);
		assert(c_queue->capacity == size);
		printf("TEST DONE: initial Queue TEST\n");
	}

	{
		printf("TEST START: enqueue TEST\n");
		cq_enqueue(&c_queue, 0);
		cq_enqueue(&c_queue, 1);
		cq_enqueue(&c_queue, 2);
		cq_enqueue(&c_queue, 3);
		cq_enqueue(&c_queue, 4);
		printf("TEST DONE: enqueue TEST\n");
	}

	{
		printf("TEST START: enqueue when queue is FULL\n");
		assert(cq_is_full(c_queue) == true);
		cq_enqueue(&c_queue, 5);
		cq_enqueue(&c_queue, 6);
		printf("TEST DONE: enqueue when queue is FULL\n");
	}

	{
		printf("TEST START: dequeue one node\n");
		assert(cq_dequeue(&c_queue) == 0);
		printf("TEST DONE: dequeue one node\n");
	}
	cq_print_all(c_queue);

	{
		printf("TEST START: dequeue all node\n");
		assert(cq_dequeue(&c_queue) == 1);
		assert(cq_dequeue(&c_queue) == 2);
		assert(cq_dequeue(&c_queue) == 3);
		assert(cq_dequeue(&c_queue) == 4);
		//다 꺼내면, EMPTY 상태 유지
		assert(c_queue->front == -1);
		assert(c_queue->rear == -1);
		printf("TEST DONE: dequeue all node\n");
	}

	cq_destroy_all(&c_queue);
	return 0;
}