#include<stdio.h>
#include<stdlib.h>
struct STACK
{
	int info;
	struct STACK *next;
};
struct STACK *top=NULL;
void push();
void pop();
void display();
void main()
{
	while(1)
	{
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.DISPLAY\n");
		printf("4.EXIT\n");
		int ch;
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;

			case 3:
				display();
				break;

			case 4:
				exit(1);
               	}
	}
}
void push()
{
 	struct STACK *curr=(struct STACK *)malloc(sizeof(struct STACK ));
	if(curr==NULL)
	{	
		printf("\n out of memory");
		exit(1);
	}
	printf("\n enter a value:");
	scanf("%d",&curr->info);
	curr->next=top;
	top=curr;
}
void pop()
{
	struct STACK *curr=top;
	if(curr==NULL)
	{
		printf("\n out of memory");
		exit(1);
	}
	top=curr->next;
	free(curr);
}
void display()
{
	struct STACK *temp=top;
	if(temp==NULL)
	{
		printf("\nstack empty");
		exit(1);
	}
	printf("\nDISPLAY\n");
	while(temp!=NULL)
	{
		printf("\n%d",temp->info);
		temp=temp->next;
	}
}



	
	
		