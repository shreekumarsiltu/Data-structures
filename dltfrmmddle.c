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
void dltnode();

void main()
{
	createlist();
	display();
	printf("delete from middle");
	dltnode();
	display();
	getch();
}

void dltnode()
{
	struct dlink* temp = start,*temp1,*temp2;
	int i=1, loc;
	printf("\nEnter Location :");
	scanf("%d",&loc);
	while(i<loc)
	{
		temp1 = temp;
		temp = temp->next;
		i++;
	}
	temp2 = temp->next;
	temp1->next = temp2;
	temp2->prev = temp1;
	free(temp);
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

