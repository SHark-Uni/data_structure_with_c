#pragma once

typedef int ELEMENT_TYPE;

typedef struct CLL_node {
	ELEMENT_TYPE data;
	struct CLL_node* prev;
	struct CLL_node* next;
} cll_node_t;

void CLL_append(cll_node_t** head, ELEMENT_TYPE data);
void CLL_remove(cll_node_t** head, cll_node_t* remove_node);
cll_node_t* CLL_get_node(const cll_node_t*, ELEMENT_TYPE data);

void CLL_destroy_all_node(cll_node_t** head);

void CLL_print_all_node(const cll_node_t* head);
