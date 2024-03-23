#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "double_linked_list.h"
/*
typedef struct dll_node {
	ELEMENT_TYPE data;

	struct dll_node* next;
	struct dll_node* prev;
} dll_node_t;*/

void DLL_append(dll_node_t** head, ELEMENT_TYPE data)
{
	dll_node_t* cur_node = (*head);
	dll_node_t* new_node = NULL;

	new_node = (dll_node_t*)malloc(sizeof(dll_node_t));
	new_node->data = data;
	new_node->next = NULL;

	if (*head == NULL) {
		new_node->prev = NULL;
		*head = new_node;
		return;
	}

	while (cur_node->next != NULL) {
		cur_node = cur_node->next;
	}
	cur_node->next = new_node;
	new_node->prev = cur_node;

	return;
}

void DLL_insert_front(dll_node_t** head, ELEMENT_TYPE data)
{
	dll_node_t* cur_node = (*head);
	dll_node_t* new_node = NULL;

	new_node = (dll_node_t*)malloc(sizeof(dll_node_t));
	new_node->data = data;

	//EMPTY CASE
	if (*head == NULL) {
		new_node->prev = NULL;
		new_node->next = NULL;
		*head = new_node;
	}

	cur_node->prev = new_node;
	new_node->next = cur_node;
	new_node->prev = NULL;

	*head = new_node;
	return;
 }


size_t DLL_get_index_of_node(ELEMENT_TYPE data)
{
	return 0;
}

void DLL_remove_node(dll_node_t** head, ELEMENT_TYPE data)
{
	dll_node_t* p = (*head);
	dll_node_t* delete_node;

	/* remove first element */
	if ((*head)->data == data) {
		DLL_remove_node_front(head);
		return;
	}

	while (p != NULL) {
		if (p->data == data) {
			delete_node = p;

			assert(delete_node->prev != NULL);
			delete_node->prev->next = delete_node->next;
			//맨 끝을 삭제하는 경우, next_node = NULL이 될 수 있다.
			if (delete_node->next != NULL) {
				delete_node->next->prev = delete_node->prev;
			}
			free(delete_node);
			return;
		}
		p = p->next;
	}
	/*NOT FOUND*/
	return;
}

void DLL_update_node(dll_node_t** head, ELEMENT_TYPE new_data)
{

}

void DLL_remove_node_front(dll_node_t** head)
{
	dll_node_t* delete_node = (*head);
	dll_node_t* new_head = NULL;

	/*EMPTY CASE*/
	if (*head == NULL) {
		return;
	}

	//one element . linked list의 대전제를 유지해줘야한다.
	*head = delete_node->next;
	if (*head == NULL) {
		goto memory_free_rnf;
	}
	(*head)->prev = NULL;

memory_free_rnf:
	free(delete_node);
}

void DLL_remove_node_back(dll_node_t** head)
{
	dll_node_t* delete_node = *head;

	//EMPTY CASE
	if (*head == NULL) {
		return;
	}
	//find last
	while (delete_node->next != NULL) {
		delete_node = delete_node->next;
	}

	//one element .
	if (delete_node->prev == NULL) {
		goto memory_free_rnb;
	}
	delete_node->prev->next = NULL;

memory_free_rnb:
	free(delete_node);
}

void DLL_destroy_all_node(dll_node_t* head)
{
	dll_node_t* p = head;
	while (p != NULL) {
		dll_node_t* delete_node = p;
		p = p->next;
		free(delete_node);
	}

}

void DLL_print_all_node(const dll_node_t* head)
{
	const dll_node_t* p = head;

	while (p != NULL) {
		printf("[%p] | data : %d | prev_node : [%p] | next_node : [%p]\n", (void*)p, 
			p->data, (void*)p->prev, (void*)p->next);
		p = p->next;
	}
}
