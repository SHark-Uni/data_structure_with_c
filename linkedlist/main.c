#include <stdio.h>
#include "Signlelinkedlist.h"

int main(void)
{
	node_t** head = NULL;
	node_t* remove = NULL;

	append_back(&head, 10);
	append_back(&head, 5);
	append_back(&head, 15);

	append_front(&head, 500);

	print_list(head);
	/*500 10 5 15 */

	remove = search_node(head, 500);
	remove_node(&head, remove);
	puts("");
	print_list(head);
	/*10 5 15 */

	destroy_allnode(head);
	head = NULL;
	return 0;
}