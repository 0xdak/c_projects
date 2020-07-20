//printing linked list elements
//before printing linked list, i had to do create a linked list
//so i did this with populate_linked_list function
//this is a "geeksforgeeks" example

#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *next;
};

void populate_linked_list(struct node*, int);
void print_linked_list(struct node*);

int main(void){
	//when malloc is not used, compiler gives segmentation fault
	struct node *head = (struct node*)malloc(sizeof(struct node)); //declaring root, head, first node
	head->value = 0; //setting up root value
	populate_linked_list(head, 0); //create linkedlist and fill
	print_linked_list(head); // print linkedlist elements to screen
	return 0;
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
