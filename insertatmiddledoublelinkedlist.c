#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct dlink
{
	int info;
	struct dlink *next, *prev;
};
struct dlink *start;

void createlist();
void display();
void addnode();

void main()
{
	createlist();
	display();
	printf("add node in middle");
	addnode();
	display();
	getch();
}

void addnode()
{
	struct dlink* node=(struct dlink*)malloc(sizeof(struct dlink));
	struct dlink* temp = start,*temp1;
	int i=1, loc;
	printf("\nEnter Location :");
	scanf("%d",&loc);
	if(node==NULL)
	{
		printf("Out of memory");
		exit(1);
	}
	while(i<loc)
	{
		temp1 = temp;
		temp = temp->next;
		i++;
	}
	printf("Entre value :");
	scanf("%d",&node->info);
	node->prev = temp1;
	node->next = temp;
	temp1->next = node;
	temp->prev = node;
}

void createlist()
{
	start = (struct dlink*)malloc(sizeof(struct dlink));
	if(start==NULL)
	{
		printf("Out of memory");
		exit(1);
	}
	struct dlink* temp= start;
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
		struct dlink* cur=(struct dlink*)malloc(sizeof(struct dlink));
		temp->next = cur;
		cur->prev = temp;
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
	struct dlink* temp= start;
	printf("Display :\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}
}

