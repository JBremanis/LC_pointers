#include <stdio.h>
#include <stdlib.h>

//Example 4
// List implementation and circular references
//When we don't know how much data we'll need:

// DO - make lists for dynamic data structures
typedef struct s_node{
	int value;
	struct s_node* next_node;
}node;

typedef struct s_list{
	unsigned int size;
	node* head;
	node* last;
}list;

node* pop(list* llist);
void print_list(list* llist);

list * make_list(){
	list* new_list = (list*)malloc(sizeof(list));
	new_list->head = (node*)malloc(sizeof(node));
	new_list->last = new_list->head;
	new_list->size = 1;
	return new_list;
}

node * make_node(int val){
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = val;
	new_node->next_node = NULL;
	return new_node;
}

void free_list(list* trash){
	if(trash == NULL) return;
	while(trash->size > 0){
		node* next = pop(trash);
		if(next != NULL) free(next);
	}
	free(trash); // does not delete the pointer itself
	//trash = NULL; // does not set trash to 0, needs to be done in original function
}

void add_to_list(list* llist, node* el_to_add, int index){
	int counter = 0;
	node* el = llist->head;
	while(counter < index && el != llist->last && el != NULL){
		el = el->next_node;
		counter++;
	}
	node* temp;
	if(el != NULL) temp = el->next_node;
	else temp = NULL;
	el->next_node = el_to_add;
	el_to_add->next_node = temp;
	if(el == llist->last) llist->last = el_to_add;
	llist->size++;
}

int peek_value(list* llist, int index){
	if(index >= llist->size) return -1;
	int counter = 0;
	node* el = llist->head;
	while(counter < index && el != llist->last && el != NULL){
		el = el->next_node;
		counter++;
	}
	if(el == NULL) return -2;
	return el->value;
}

node* get_value(list* llist, int index){
	if(index >= llist->size) return NULL;
	int counter = 0;
	node* el = llist->head;
	while(counter < index && el != llist->last && el != NULL){
		el = el->next_node;
		counter++;
	}
	return el;
}

void push(list* list, node* el_to_add){
	el_to_add->next_node = list->head;
	if(list->size == 0) list->last = list->head;
	list->head = el_to_add;
	list->size++;
}

node* pop_head(list* llist){
	node * temp = llist->head;
	if(llist->head == llist->last){
		llist->last = NULL;
		llist->head = NULL;
		llist->size = 0;
		return temp;
	}
	llist->head = llist->head->next_node;
	llist->size--;
	return temp;
}

node* pop(list* llist){
	node* temp = llist->last;
	node* t2 = llist->head;
	if(temp == t2){
		printf("Last element\n");
		llist->last = NULL;
		llist->head = NULL;
		llist->size = 0;
		return temp;
	}
	while(t2->next_node != temp){
		t2 = t2->next_node;
	}
	t2->next_node = NULL;
	llist->last = t2;
	llist->size--;
	return temp;
}

node* head(list* llist){
	return llist->head;
}

node* peek(list* llist){
	return llist->last;
}

void stack(list* llist, node* el_to_add){
	llist->size++;
	llist->last->next_node = el_to_add;
	llist->last = el_to_add;
}

void print_list(list* llist){
	if(llist == NULL || llist->size == 0){
		printf("NULL\n");
		return;
	}
	node* iterator = llist->head;
	int counter = 0;
	printf("List %p, size:%d, nodes: (h-%p,l-%p)\n", llist, llist->size, llist->head, llist->last);
	while(iterator != NULL && counter < llist->size){
		printf("El %d: %p (%d,%p)\n", counter, iterator, iterator->value, iterator->next_node);
		iterator = iterator->next_node;
		counter++;
	}
	printf("End of list %p\n", llist);
}

void print_list_python_like(list* llist){
	if(llist == NULL || llist->size == 0){
		printf("[]\n");
		return;
	}
	node* iterator = llist->head;
	int counter = 0;
	printf("[");
	while(iterator != NULL && counter < llist->size){
		printf(" %d%c", iterator->value, (counter == llist->size - 1) ? ' ' : ',');
		iterator = iterator->next_node;
		counter++;
	}
	printf("]\n");
}

/*
// Don't - make two objects reference each other.
// Don't - make a circular reference
// Don't - use a regular list as a circular list
typedef struct My_Node{
	List* list;
} My_Node;

//Don't - Circular referencing
typedef struct My_Obj{
	List* list;
} My_Obj;

typedef struct List{
	int size;
    My_Node* node;
} List;

typedef struct My_node{
	My_Obj* obj;
	My_node* node;
} My_node;
*/

int main(void){
	//Initialazing
	printf("Making a list:\n");
	list* my_list = make_list();
	print_list(my_list);
	
	//Populating
	printf("\nPopulating a list:\n");
	add_to_list(my_list,make_node(5),2);
	//print_list(my_list);
	print_list_python_like(my_list);
	add_to_list(my_list,make_node(10),2);
	//print_list(my_list);
	print_list_python_like(my_list);
	add_to_list(my_list,make_node(13),2);
	//print_list(my_list);
	print_list_python_like(my_list);
	push(my_list, make_node(12));
	//print_list(my_list);
	print_list_python_like(my_list);
	stack(my_list, make_node(14));
	print_list_python_like(my_list);
	print_list(my_list);

	//Accessing
	printf("\nAccessing values of a list:\n");
	for(int i = 0; i< my_list->size; i++){
		int v = peek_value(my_list, i);
		printf("List value at %d: %d;\n", i, v);
	}

	printf("\nIterating through values of a list:\n");
	for(int i = 0; i< my_list->size; i++){
		node* n = get_value(my_list, i);
		printf("Node at %d: %p - (%d,%p);\n", i, n, n->value, n->next_node);
	}

	printf("\nAccessing values with peek:\n");
	printf("Head %p: (%d,%p)\n", head(my_list), head(my_list)->value, head(my_list)->next_node);
	printf("Peek %p: (%d,%p)\n", peek(my_list), peek(my_list)->value, peek(my_list)->next_node);


	//Queue operations
	printf("\nQueue operations:\n");
	node* first = pop_head(my_list);
	push(my_list, first);
	printf("Head %p: (%d,%p)\n", head(my_list), head(my_list)->value, head(my_list)->next_node);	// Use peek to access the first element of the list without removing it, can also be done with my_list->head
	first = pop_head(my_list); 	// in this implementation, pop_head returns a node*, and thus, requires the deletion of the pointer given
	free(first);						// This may be done in function and an integer value may be returned if the pointer to next is not needed (which is null anyway)
	printf("Head %p: (%d,%p)\n", head(my_list), head(my_list)->value, head(my_list)->next_node);
	//Stack operations
	node* last = pop(my_list);
	stack(my_list, last);
	printf("Peek %p: (%d,%p)\n", peek(my_list), peek(my_list)->value, peek(my_list)->next_node); 				// Use peek to access the last element of the list without removing it, can also be done with my_list->last
	last = pop(my_list); 				// in this implementation, pop returns a node*, and thus, requires the deletion of the pointer given
	printf("Last %p: (%d,%p)\n", last, last->value, last->next_node);
	free(last);							// This may be done in function and an integer value may be returned if the pointer to next is not needed (which is null anyway)
	printf("Peek %p: (%d,%p)\n", peek(my_list), peek(my_list)->value, peek(my_list)->next_node);

	printf("\nDeleting list:\n");
	print_list(my_list);
	free_list(my_list);
	//free(my_list); 					// List pointer is still there, can't delete it from function. Either free, or use a statically allocated list.
	my_list = NULL; 					// To prevent trash values from messing with print list
	print_list(my_list); 				// using the pointer after it is deleted is undefined behaviour, so we set it to NULL
	print_list_python_like(my_list);

	printf("\nEnd of example!\n");
}