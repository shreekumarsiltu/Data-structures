#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct STACK
{
	int info;
	struct STACK *next;
};
struct STACK *top=NULL;
void push(int);
int pop();
void main()
{
	int n,m=1;
	printf("enter a value :");
	scanf("%d",&n);
	while(n-1 != 0){
		push(n);
		n--;
	}
	while(top != NULL){
		m=m*pop();
	}
	
	
	printf("factorial is : %d",m);
	getch();
}
void push(int n)
{
 	struct STACK *curr=(struct STACK *)malloc(sizeof(struct STACK ));
	if(curr==NULL)
	{	
		printf("\n out of memory");
		exit(1);
	}
	curr->info=n;
	curr->next=top;
	top=curr;
}
int pop()
{
	struct STACK *curr=top;
	if(curr==NULL)
	{
		printf("\n out of memory");
		exit(1);
	}
	int x = curr->info;
	top=curr->next;
	free(curr);
	return x;
}
