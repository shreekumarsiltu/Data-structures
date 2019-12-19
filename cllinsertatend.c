#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct clink
{
	int info;
	struct clink *next;
};
struct clink *start;

void createlist();
void display();
void insertatend();

void main()
{
	createlist();
	display();
	insertatend();
	display();
	getch();
}

void insertatend(){
	struct clink* node = (struct clink*)malloc(sizeof(struct clink));
	if(node==NULL)
	{
		printf("Out of memory");
		exit(1);
	}
	printf("insert at end");
	scanf("%d",&node->info);
	struct clink* temp = start;
	do
	{
		temp = temp->next;
	}while(temp->next!=start);
	temp->next = node;
	node->next = start;
	
}

void createlist()
{
	start = (struct clink*)malloc(sizeof(struct clink));
	if(start==NULL)
	{
		printf("Out of memory");
		exit(1);
	}
	struct clink* temp= start;
	printf("Entre value :");
	scanf("%d",&temp->info);
	temp->next = NULL;
	char ch;
	printf("Do u wanna cont. (y/n) :");
	fflush(stdin);
	scanf("%c",&ch);
	while(ch=='y')
	{
		temp->next = (struct clink*)malloc(sizeof(struct clink));
		temp=temp->next;
		printf("Entre value :");
		scanf("%d",&temp->info);
		temp->next = NULL;
		printf("Do u wanna cont. (y/n) :");
		fflush(stdin);
		scanf("%c",&ch);
	}
	temp->next = start;
	
}
void display()
{
	struct clink* temp= start;
	printf("Display :\n");
	do
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}while(temp!=start);
}

