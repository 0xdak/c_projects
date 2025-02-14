//singly linked list operations in a file

#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *next;
};

void delete_node_with_value(int);
void delete_node_with_position(int);
void insert_at_beginning(int);
void insert_after(int, int);
void insert_at_end(int);
void populate(struct node*, int);
void print_linkedlist(struct node*);
int  length_of_linkedlist(struct node*);
int  get_index_of_linkedlist(struct node*, int value);

struct node *head;

int main(void){
	//when malloc is not used, compiler gives segmentation fault
	head = (struct node*)malloc(sizeof(struct node)); //declaring root, head, first node
	head->value = 0; //setting up root value
	populate(head, 0); //create linkedlist and fill
	
	//get length of linked list
	//printf("%d\n",length_of_linkedlist(head));

	//get index (position) of linked list
	//printf("%d\n",get_index_of_linkedlist(head, 12));


	//deleting a node with value
	//delete_node_with_value(12);
	//print_linkedlist(head);

	//deleting a node with position
	//delete_node_with_position(12);
	//print_linkedlist(head);

	//at the front of the linked list
	//insert_at_beginning(13);
	//print_linkedlist(new_node); // print linkedlist elements to screen
	
	//after a given node
	//insert_after(13, 5);
	//print_linkedlist(head);

	//at the end of the linked list
	//insert_at_end(new_node);
	//print_linkedlist(head); // print linkedlist elements to screen
	return 0;
}

//deletes the node with given value
void delete_node_with_value(int value){
	struct node *n = head;
	if(head->value == value){ // if the node to be deleted is head, then head changes too
		head = n->next;
		free(n);
		return;
	}
	while(n->next->value != value){	// n->next will be deleted	
	        n = n->next;
		if(n->next == NULL) return; // if the node with given value is not in linked list, do nothing
}
	struct node *temp = n->next;
	n->next = n->next->next;
	free(temp);
}	

//deletes the node with given position
void delete_node_with_position(int position){
	struct node *n = head;
	for(int i = 0; i < position - 1; i++)
		n = n->next;
	if(n == head){ // if the node to be deleted is head, then head changes too
		head = n->next;
		free(n);
		return;
	}
	struct node *temp = n->next;
	n->next = n->next->next;
	free(temp);
}

//inserts node to beginning
//so changes the head
void insert_at_beginning(int value){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->value = value;
	new_node->next = head; //new_node became head
}

//inserts node after the node with given value
void insert_after(int value, int trg){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->value = value;
	struct node *n = head;
	while(n->value != trg)
		n = n->next;
	//sequence is important
	new_node->next = n->next;
	n->next = new_node;
}

//inserts node to end
void insert_at_end(int value){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->value = value;
	new_node->next = NULL;
	struct node *n = head;
	while(n->next!=NULL){
		n = n->next;
	}
	//when the n is NULL, it's the end
	n->next = new_node;
}

//populate from an array
//it's recursive function
#define arr_size 12
void populate(struct node *trg, int index){
	int arr[arr_size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	if(index == arr_size) return; // at the end of the array, function will stop
	struct node *n = (struct node*)malloc(sizeof(struct node));
	trg->next = n;
	n->value = arr[index];
	n->next = NULL;
	index++;
	populate(n, index);
}

//print linked list elements
//it's recursive function
void print_linkedlist(struct node *trg){
	printf("%d\n",trg->value);
	if(trg->next == NULL) return;
	print_linkedlist(trg->next);
}

//returns length of linked list
int length_of_linkedlist(struct node *trg){
	int i = 0;
	struct node *n = trg;
	while(n != NULL){
		i++;
		n = n->next;
	}
	return i;	
}

//returns position of the node with given value
int get_index_of_linkedlist(struct node *trg,int value){
	int i = 0;
	struct node *n = trg;
	while(n->value != value){
		i++;
		n = n->next;
	}
	return i;
}
