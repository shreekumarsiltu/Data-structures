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
void dltfrmbegin();

void main()
{
	createlist();
	display();
	dltfrmbegin();
	display();
	getch();
}

void dltfrmbegin(){
	printf(" delete from begin :");
	struct clink* temp = start;
	do
	{
		temp = temp->next;
	}while(temp->next!=start);
	struct clink* temp1;
	temp1 = temp->next;
	temp->next = start->next;
	start = start->next;
	free(temp1);
	
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

