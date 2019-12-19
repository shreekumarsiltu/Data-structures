#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct clink
{
	int info;
	struct clink *next,*prev;
};
struct clink *start;

void createlist();
void display();
void dltfrmend();

void main()
{
	createlist();
	display();
	dltfrmend();
	display();
	getch();
}

void dltfrmend(){
	struct clink* temp = start;
	do
	{
		temp = temp->next;
	}while(temp->next->next!=start);
	temp->next = start;
	start->prev = temp;
	
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
	temp->prev = NULL;
	char ch;
	printf("Do u wanna cont. (y/n) :");
	fflush(stdin);
	scanf("%c",&ch);
	
	while(ch=='y')
	{
		struct clink* temp1 = (struct clink*)malloc(sizeof(struct clink));
		printf("Entre value :");
		scanf("%d",&temp1->info);
		temp->next = temp1;
		temp1->prev = temp;
		temp1->next = NULL;
		temp = temp1;
		printf("Do u wanna cont. (y/n) :");
		fflush(stdin);
		scanf("%c",&ch);
	}
	temp->next = start;
	start->prev = temp;
	
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

