#include <stdio.h>
#include <assert.h>

#include "double_linked_list.h"

int main(void) {
	dll_node_t* head = NULL;

	DLL_append(&head, 10);
	DLL_append(&head, 20);
	DLL_append(&head, 30);
	DLL_append(&head, 40);

	DLL_insert_front(&head, 0);
	DLL_remove_node(&head, 0);

	DLL_remove_node_front(&head);
	DLL_remove_node_back(&head);
	DLL_remove_node_front(&head);
	DLL_remove_node_front(&head);

	DLL_print_all_node(head);
	DLL_destroy_all_node(head);
	return 0;
}
