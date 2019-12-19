#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

struct stack {
	int inpt[10];
	int top;
};

struct stack s;
struct stack *p = &s;

int isEmpty(){
	if(p->top==-1){
		return 1;
	}
	return 0;
}

int isFull(){
	if(p->top==9){
		return 1;
	}
	return 0;
}

void push(int n){
	if(isFull)
	{
		printf("Stack is Full");
		exit(1);
	}
	struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
	p->top++;
	scanf("%d",&temp->inpt[p->top]);
}



int pop(){
	if(isEmpty)
	{
		printf("Stack is Empty");
		exit(1);
	}
	int x = p->inpt[p->top];
	p->top--;
	return x;
}

void display(){
	if(isEmpty)
	{
		printf("Stack is Empty");
		exit(1);
	}
	struct stack* temp = p;
	int b=p->top;
	while(b!=-1){
		printf("%d\t",temp->inpt[b]);
		b--;
	}
	
}

void main(){
	p->top = -1;
	printf("push : 1\n");
	printf("pop : 2\n");
	printf("display : 3\n");
	int i;
	printf("Enter ur option : ");
	scanf("%d",&i);
	switch(i){
		case 1:
			
				{int n;
				printf("Enter a no :");
				scanf("%d",&n);
				push(n);
				break;	}
			
		case 2:
			
				if(isEmpty){
					printf("Stack is Empty");
					exit(1);
				}
				int x = pop();
				printf("Poped element is : %d",x);
				break;
		
		case 3:
			
				if(isEmpty){
					printf("Stack is Empty");
					exit(1);
				}
				display();
				break;
				
		default :
			
				printf("Invalid option");
				break;
		
	}
	getch();
}
