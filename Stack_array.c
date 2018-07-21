// Stack Using Array
#include<stdio.h>
#include<stdlib.h>

int push(int *s, int top, int value){
	printf("Pushing Value into Stack...\n");
	s[top-1] = value;
}

int pop(){
	printf("Popping from Stack...\n");
}

int display(int *s, int top){
	printf("The Stack is :\n");
	int i = top-1;
	while(i >=0){
		printf("| %d |\n", s[i]);
		i--;
	}
}

int main(){
	int size, choice = -1, value, count = 0;
	printf("Enter the size of Stack :\t");
	scanf("%d", &size);
	int stack[size];
	do{
		printf("****************************************\n");
		printf("PUSH \t\t1\n");
		printf("POP \t\t2\n");
		printf("DISPLAY \t3\n");
		printf("EXIT \t\t0\n");
		printf("Enter your Choice:\t");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				printf("Exiting...\n");
				break;
			case 1:
				count++;
				if(count <= size){
					printf("Enter a value to PUSH:\t");
					scanf("%d", &value);
					push(stack, count, value);
				}
				else{
					printf("Stack Overflow...\nTry Popping some elements...\n");
					count--;
				}
				break;
			case 2:
				if(count > 0){
					count--;
					pop();
				}
				else{
					printf("Stack Empty...\n");
				}
				break;
			case 3:
				if(count > 0){
					display(stack, count);
				}
				else{
					printf("Stack is Empty...\n");
				}
				break;
		}
	}while(choice != 0);
	
	
	return 0;
}
