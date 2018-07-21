#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct double_ll{
	struct double_ll *prev, *addr;
	int data;
}dll;

int newNode(dll **h, int newValue){
	printf("Creating a New Node\n");
	if((*h) == NULL){
		(*h) = (dll*)malloc(sizeof(dll));
		(*h)->data = newValue;
		(*h)->addr = NULL;
		(*h)->prev = NULL;
		printf("Successfully Added a New Node...\n");
	}
	else{
		dll *current = (*h), *temp;
		while(current->addr != NULL){
			current = current->addr;
		}
		temp = current;
		current = (dll*)malloc(sizeof(dll));
		current->addr = NULL;
		current->prev = temp;
		temp->addr = current;
		current->data = newValue;
		printf("Successfully Added a New Node...\n");
	}
}

int display(dll **h){
	if((*h) == NULL){
		printf("Error...\nNo Doubly Linked List Found...\n");
	}
	else{
		printf("The Current Doubly Linked List is:\n");
		dll *current;
		current = (*h);
		while(current != NULL){
			printf("[%d]->", current->data);
			current = current->addr;
		}
		printf("[NULL]\n");
	}
}

int delNode(dll **h, int target){
	printf("Searching Target\n");
	if((*h) == NULL){
		printf("No Linked List Found...\n");
		return 0;
	}
	dll *current;
	current = (*h);
	bool found = false;
	while(current->addr != NULL){
		if(current->data == target){
			found = true;
			break;
		}
		else{
			current = current->addr;
		}
	}
	if(found){
		printf("Target Node Found...\n");
		if(current->prev == NULL){
			(*h) = current->addr;
			current->addr->prev = NULL;
			free(current);
			printf("Target Node Deleted Successfully...\n");
		}
		else{
			current->addr->prev = current->prev;
			current->prev->addr = current->addr;
			free(current);
			printf("Target Node Successfully Deleted...\n");
		}
	}
	else{
		if(current->data == target && current->prev != NULL){
			printf("Target Node Found0...\n");
			current->prev->addr = NULL;
			free(current);
			printf("Target Node Successfully Deleted...\n");
		}
		else if(current->data == target && current->prev == NULL){
			(*h) = NULL;
			printf("Target Node Successfully Deleted...\n");
		}
		else{
			printf("Error...\nTarget Node Not Found...\n");
		}
	}
}

int main(){
	dll *head = NULL;
	int choice = -1, value;
	do{
		printf("\n***********************************************\n");
		printf("For New Node \t\t\t\tPress 1\n");
		printf("To Display Current Linked List \t\tPress 2\n");
		printf("To Delete a Node \t\t\tPress 3\n");
		printf("To Exit \t\t\t\tPress 0\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Enter a value: \t");
				scanf("%d", &value);
				newNode(&head, value);
				break;
			case 2:
				display(&head);
				break;
			case 3:
				printf("Enter Node to be Deleted: \t");
				scanf("%d", &value);
				delNode(&head, value);
				break;
			case 0:
				printf("Exiting........\n");
				break;
			default :
				printf("Try Again.....\n");
				break;
		}
	}while(choice != 0);
	return 0;
}
