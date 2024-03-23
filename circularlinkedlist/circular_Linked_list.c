#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <stdio.h>

#include "circular_linked_list.h"

/*typedef struct CLL_node {
	ELEMENT_TYPE data;
	struct CLL_node* prev;
	struct CLL_node* next;
} cll_node_t;
*/
void CLL_append(cll_node_t** head, ELEMENT_TYPE data)
{
	cll_node_t* new_node = NULL;
	cll_node_t* tail_node = NULL;

	new_node = malloc(sizeof(cll_node_t));
	new_node->data = data;
	//EMPTY CASE
	if (*head == NULL) {
		*head = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
		return;
	}

	(*head)->prev->next = new_node;
	new_node->prev = (*head)->prev;
	
	(*head)->prev = new_node;
	new_node->next = *head;
	return;
}

void CLL_remove(cll_node_t** head, cll_node_t* remove_node)
{

	// ¸Ç ¾Õ
	if (*head == remove_node) {
		remove_node->next->prev = remove_node->prev;
		remove_node->prev->next = remove_node->next;

		*head = remove_node->next;
		free(remove_node);
		return;
	}

	remove_node->next->prev = remove_node->prev;
	remove_node->prev->next = remove_node->next;
	free(remove_node);
	return;
}

cll_node_t* CLL_get_node(const cll_node_t* head, ELEMENT_TYPE data)
{
	cll_node_t* ret = NULL;

	cll_node_t* p = head;
	do {
		if (p->data == data) {
			ret = p;
			return ret;
		}
		p = p->next;
	} while (p != head);

	return ret;
}

void CLL_destroy_all_node(cll_node_t** head)
{
	cll_node_t* p = *head;
	cll_node_t* free_node = NULL;

	do {
		free_node = p;
		p = p->next;
		free(free_node);
	} while (p != *head);

}

void CLL_print_all_node(const cll_node_t* head)
{
	const cll_node_t* p = head;

	do {
		printf("[%p] | data : %d | prev : %p | next : %p\n",(void*)p,
			p->data,(void*)p->prev,(void*)p->next);
		p = p->next;
	} while (p != head);

}
