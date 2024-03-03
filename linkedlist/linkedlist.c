#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Signlelinkedlist.h"


node_t* create_node_malloc(int data)
{
	node_t* new_node = NULL;

	new_node = malloc(sizeof(node_t));
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

void destroy_node(node_t* node) 
{
	free(node);
}

void destroy_allnode(node_t* head)
{
	node_t* cur_node = head;

	while (cur_node != NULL) {
		node_t* remove_node = cur_node;
		cur_node = cur_node->next;
		free(remove_node);
	}
}

/*원소를 뒤에 추가함.*/
void append_back(node_t** head, int data)
{
	node_t* new_node = NULL;
	new_node = create_node_malloc(data);

	if ((*head) == NULL) {
		(*head) = new_node;
		return;
	}

	node_t* tail = (*head);

	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = new_node;
}

void append_front(node_t** head, int data) 
{
	
	node_t* new_node = create_node_malloc(data);

	new_node->next = *head;
	*head = new_node;

}

/*data가 n인 노드 찾기*/
node_t* search_node(node_t* head, int data) 
{
	node_t* cur_node = head;

	while (cur_node != NULL) {
		if (cur_node->data == data) {
			return cur_node;
		}
	}
	return NULL;
}

void remove_node(node_t** head,node_t* remove)
{
	node_t* cur_node = NULL;    
	assert(remove != NULL);

	if (*head == remove) {
		*head = remove->next;
		return;
	}

	cur_node = *head;

	while (cur_node != NULL) {
		if (cur_node->next == remove) {
			cur_node->next = remove->next;
			destroy_node(remove);
			return;
		}
		cur_node = cur_node->next;
	}
}

void print_list(const node_t* head)
{
	const node_t* p_head = head;

	while (p_head != NULL) {
		printf("%d ", p_head->data);
		p_head = p_head->next;
	}
}
