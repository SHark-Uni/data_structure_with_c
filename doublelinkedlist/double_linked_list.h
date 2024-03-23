#pragma once

typedef int ELEMENT_TYPE;

typedef struct dll_node{
	ELEMENT_TYPE data;

	struct dll_node* next;
	struct dll_node* prev;
} dll_node_t;

void DLL_append(dll_node_t** head, ELEMENT_TYPE data);
void DLL_insert_front(dll_node_t** head, ELEMENT_TYPE data);


size_t DLL_get_index_of_node(ELEMENT_TYPE data);

void DLL_remove_node(dll_node_t** head, ELEMENT_TYPE data);
void DLL_update_node(dll_node_t** head, ELEMENT_TYPE new_data);

void DLL_remove_node_front(dll_node_t** head);
void DLL_remove_node_back(dll_node_t** head);

void DLL_destroy_all_node(dll_node_t* head);
void DLL_print_all_node(const dll_node_t* head);
