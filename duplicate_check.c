#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

struct slink{
	int info;
	struct slink* next;
};

struct slink* start;





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

void cheak()
{
	int dup;
	struct slink* temp= start;
	printf("no of duplicate elements :");
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	struct slink *i;
	struct slink* j; 
	for(i=start;i!=temp;i=i->next){
		for(j=i;j!=temp->next;j=j->next){
			if(i->info>j->info){
				dup=i->info;
				i->info=j->info;
				j->info=dup;
			}
		}	
	}
	int d=0;
	struct slink *l;
	for(l=start;l!=temp;l=l->next){
		struct slink *temp1=l->next;
		if(l->info==temp1->info && temp1->next==NULL){
			l->next=NULL;
			temp=l;
			free(temp1);
			d++;
			break;
		}
		else if(l->info==temp1->info && temp1->next!=NULL){
			l->next=temp1->next;
			free(temp1);
			d++;
		}
	}
	printf("\n%d\n",d);
	temp= start;
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
	}
	
}

void main(){
	createlist();
	cheak();
	getch();
	
}
