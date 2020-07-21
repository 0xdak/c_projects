//inserting elements to linked list
//there is 3 ways for inserting elements to linkedlist
//1)at the front of the linked list 
//2)after a given node
//3)at the end of the linked list
//this is a "geeksforgeeks" example

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
void populate_linked_list(struct node*, int);
void print_linked_list(struct node*);

struct node *head;

int main(void){
	//when malloc is not used, compiler gives segmentation fault
	head = (struct node*)malloc(sizeof(struct node)); //declaring root, head, first node
	head->value = 0; //setting up root value
	populate_linked_list(head, 0); //create linkedlist and fill
	
	//deleting a node with value
	//delete_node_with_value(12);
	//print_linked_list(head);

	//deleting a node with position
	//delete_node_with_position(12);
	//print_linked_list(head);

	//at the front of the linked list
	//insert_at_beginning(13);
	//print_linked_list(new_node); // print linkedlist elements to screen
	
	//after a given node
	//insert_after(13, 5);
	//print_linked_list(head);

	//at the end of the linked list
	//insert_at_end(new_node);
	//print_linked_list(head); // print linkedlist elements to screen
	return 0;
}

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

void insert_at_beginning(int value){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->value = value;
	new_node->next = head; //new_node became head
}

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
void populate_linked_list(struct node *trg, int index){
	int arr[arr_size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	if(index == arr_size) return; // at the end of the array, function will stop
	struct node *n = (struct node*)malloc(sizeof(struct node));
	trg->next = n;
	n->value = arr[index];
	n->next = NULL;
	index++;
	populate_linked_list(n, index);
}

//print linked list elements
//it's recursive function
void print_linked_list(struct node *trg){
	printf("%d\n",trg->value);
	if(trg->next == NULL) return;
	print_linked_list(trg->next);
}
