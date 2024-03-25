#include <stdio.h>
#include <assert.h>

#include "circular_queue_SLL.h"

int main() {
	sll_queue_t queue;
	//init
	queue.front = NULL;
	queue.rear = NULL;
	queue.head = NULL;

	{
		printf("TEST START : Enqueue\n");
		sll_enqueue(&queue, 10);
		sll_enqueue(&queue, 20);
		sll_enqueue(&queue, 30);
		sll_enqueue(&queue, 40);
		sll_enqueue(&queue, 50);
		printf("TEST DONE : Enqueue\n");
	}

	sll_print_all_node(&queue);

	{
		printf("TEST START : deqeue\n");
		assert(sll_dequeue(&queue) == 10);
		assert(sll_dequeue(&queue) == 20);
		assert(sll_dequeue(&queue) == 30);
		assert(sll_dequeue(&queue) == 40);
		assert(sll_dequeue(&queue) == 50);
		printf("TEST DONE : deqeue\n");
	}
	assert(sll_is_empty(&queue) == true);
	{
		printf("TEST START : ONE ELEMENT DEQEUE\n");
		sll_enqueue(&queue, 10);
		assert(sll_dequeue(&queue) == 10);
		assert(sll_is_empty(&queue) == true);
		printf("TEST DONE : ONE ELEMENT DEQEUE\n");
	}
	sll_destroy_all_node(&queue);

	{
		printf("TEST START : Enqueue And Dequeue\n");
		sll_enqueue(&queue, 0);
		sll_enqueue(&queue, 1);
		sll_enqueue(&queue, 2);
		sll_enqueue(&queue, 3);
		sll_enqueue(&queue, 4);
		sll_print_all_node(&queue);
		assert(sll_dequeue(&queue) == 0);
		assert(sll_dequeue(&queue) == 1);
		sll_print_all_node(&queue);
		sll_enqueue(&queue, 5);
		sll_enqueue(&queue, 6);
		assert(sll_dequeue(&queue) == 2);
		assert(sll_dequeue(&queue) == 3);
		sll_print_all_node(&queue);
		printf("TEST DONE : Enqueue And Dequeue\n");
	}
	sll_destroy_all_node(&queue);
	assert(sll_is_empty(&queue) == true);

	return 0;
}