#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct lnkd_lst{
	int data;
	struct lnkd_lst *addr;
}ll;

int newNode(ll **h, int newValue){
	printf("\nCreating a New Node\n");
	if(*h == NULL){
		(*h) = (ll*)malloc(sizeof(ll));
		(*h)->data = newValue;
		(*h)->addr = NULL;
	}
	else{
		ll *current = (*h);
		while(current->addr != NULL){
			current = current->addr;
		}
		current->addr = (ll*)malloc(sizeof(ll));
		current->addr->data = newValue;
		current->addr->addr = NULL;
	}
}

int display(ll **h){
	printf("\nThe Linked List right now is:\n");

	if((*h) == NULL){
		printf("No Nodes in Linked List\n");
	}
	else{
		ll *current = (*h);
		do{
			printf("[%d]->",current->data);
			current = current->addr;
		}while(current != NULL);
		printf("[NULL]\n");
	}
}

int delNode(ll **h, int target){
	ll *current = (*h), *previous;
	if(current == NULL){
		printf("Error....\nNO Linked List Found\n");
	}
	else{
		if(current->data == target){
			(*h) = current->addr;
			printf("Target Node Found and Deleted Successfully...\n");
		}
		else{
			bool found = false;
			while(current->addr != NULL){
				if(current->data == target){
					printf("Target Node Found...\n");
					previous->addr = current->addr;
					free(current);
					found = true;
					printf("Target Node Deleted Successfully..\n");
					break;
				}
				else{
					previous = current;
					current = current->addr;
				}
			}
			if(!found){
				if(current->data == target){
					previous->addr = NULL;
					free(current);
					printf("Target Node Found and Deleted Successfully...\n");
				}
				else{
					printf("Error...\nTarget Node Not Found...\n");	
				}
			}
		}
	}
}

int main(){
	ll *head = NULL;
	int val, choice = 1;
	do{
		switch(choice){
			case 0:
				printf("Exiting .....\n");
				break;
			case 1:
				printf("Enter a number: ");
				scanf("%d",&val);
				newNode(&head, val);
				break;
			case 2:
				printf("The current Linked List is: \n");
				display(&head);
				break;
			case 3:
				printf("Enter the target node: ");
				scanf("%d",&val);
				delNode(&head, val);
				break;
			default:
				printf("Please Try Again...!!\n");
				break;
			}
		printf("\n**********************************************\n");
		printf("For New Node \t\t\t\tPress 1\n");
		printf("To Display Current Linked List \t\tPress 2\n");
		printf("To Delete a Node \t\t\tPress 3\n");
		printf("To Exit \t\t\t\tPress 0\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
	}while(choice != 0);
	
	return 0;
}
