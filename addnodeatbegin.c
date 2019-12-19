#include<stdio.h>
#include<stdlib.h>

struct slink
{
	int info;
	struct slink *next;
};
struct slink *start;

void addnode();
void createlist();
void display();

void main()
{
	createlist();
	display();
	printf("\nEnter a node at begin\n");
	addnode();
	display();
}

void addnode()
{
	struct slink* node = (struct slink*)malloc(sizeof(struct slink));
	if(start==NULL)
	{
		printf("Out of memory");
		exit(1);
	}
	printf("Enter a value : ");
	scanf("%d",&node->info);
	node->next = start;
	start = node;
}

void createlist()
{
	start = (struct slink*)malloc(sizeof(struct slink));
	if(start==NULL)
	{
		printf("Out of memory");
		exit(1);
	}
	struct slink* temp= start;
	printf("Entre value :");
	scanf("%d",&temp->info);
	temp->next = NULL;
	char ch;
	printf("Do u wanna cont. (y/n) :");
	fflush(stdin);
	scanf("%c",&ch);
	while(ch=='y')
	{
		temp->next=(struct slink*)malloc(sizeof(struct slink));
		temp=temp->next;
		printf("Entre value :");
		scanf("%d",&temp->info);
		temp->next = NULL;
		printf("Do u wanna cont. (y/n) :");
		fflush(stdin);
		scanf("%c",&ch);
	}
	
}
void display()
{
	struct slink* temp= start;
	printf("Display :");
	while(temp!=NULL)
	{
		printf("\n%d",temp->info);
		temp=temp->next;
	}
}
