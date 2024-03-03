#pragma once

typedef struct node {
	int data;
	struct node* next;
} node_t;

node_t* create_node_malloc(int data);
void destroy_node(node_t* node);
void destroy_allnode(node_t* head);
/*원소를 뒤에 추가함.*/
void append_back(node_t** head, int data);
void append_front(node_t** head, int data);
node_t* search_node(const node_t* head, int data);
void remove_node(node_t** head, node_t* remove);
void print_list(const node_t* head);
