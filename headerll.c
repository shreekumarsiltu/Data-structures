#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct slink
{
	int info;
	struct slink *next;
};
struct slink *start;

void createlist();
void display();

void main()
{
	createlist();
	display();
	getch();
}
void createlist()
{
	start = (struct slink*)malloc(sizeof(struct slink));
	if(start==NULL)
	{
		printf("Out of memory");
		exit(1);
	}
	start->info = 0;
	start->next = (struct slink*)malloc(sizeof(struct slink));
	struct slink* temp= start->next;
	printf("Entre value :");
	scanf("%d",&temp->info);
	temp->next = NULL;
	start->info += temp->info;
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
		start->info += temp->info;
		printf("Do u wanna cont. (y/n) :");
		fflush(stdin);
		scanf("%c",&ch);
	}
	
}
void display()
{
	printf("%d",start->info);
}

