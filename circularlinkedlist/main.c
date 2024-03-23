#include<assert.h>
#include "circular_linked_list.h"
#include <stdio.h>

int main(void) {

	cll_node_t* head = NULL;
	cll_node_t* remove_node = NULL;

	{
		printf("TEST START : APPEND NODE");
		CLL_append(&head, 10);
		CLL_append(&head, 20);
		CLL_append(&head, 30);
		CLL_append(&head, 40);
		CLL_append(&head, 50);
		printf("TEST DONE : APPEND NODE");

	}
	CLL_print_all_node(head);
	{
		printf("TEST START : Remove First Elment\n");
		remove_node = CLL_get_node(head, 10);
		CLL_remove(&head, remove_node);
		printf("TEST DONE : Remove First Elment\n");
	}
	CLL_print_all_node(head);
	{
		printf("TEST START : Remove Last Elment\n");
		remove_node = CLL_get_node(head, 50);
		CLL_remove(&head, remove_node);
		printf("TEST DONE : Remove Last Elment\n");
	}
	CLL_print_all_node(head);
	
	{
		printf("TEST START : free all node\n");
		CLL_destroy_all_node(&head);
		head = NULL;
		printf("TEST DONE : free all node\n");
	}
	
	return 0;
}