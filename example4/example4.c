
//5) List implementation and circular references

//When we don't know how much data we'll need:

// DO - make lists for dynamic data structures
struct node{
	int value;
	node* next_node;
}

struct list{
	unsigned int size;
	node* head;
	node* last;
}

add_to_list(list* list, node* el_to_add){
	size++;
	list->last->next_node = el_to_add;
}

push(list* list, node* el_to_add){
	el_to_add->next_node = list->head
	list->head = el_to_add;
	list->size++;
}

pop(list){
	temp = list->last;
	t2 = list->head;
	while(t2->next != temp){
		t2 = t2->next;
	}
	t2->next = NULL;
	return temp;
}

peek(list){
	temp = list->last;
	t2 = list->head;
	while(list->)
	return temp;
}

stack(list* list, node* el_to_add){
	add_to_list(list* list, node* el_to_add);
}


// Don't - make two objects reference each other.
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

int main(void){

}