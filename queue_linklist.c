#include<stdio.h>
#include<stdlib.h>
struct queue{
	int info;
	struct queue* next;
};
struct queue* prev,*front,*rear;

void insert(int);
void Delete();
void display();

void main(){
	while(1){
		printf("\n 1.Insert");
        printf("\n 2.delete");
        printf("\n 3.DISPLAY");
        printf("\n 4.EXIT");
        int ch,val;
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter a value :");
				scanf("%d",&val);
                insert(val);
                break;
            case 2:
                Delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("\nInvalid choice");
        }
    }
}

	void insert(int x)
	{
		
	    if(rear==NULL)
	    {
			rear = (struct queue *)malloc(sizeof(struct queue));
			if(rear==NULL){
				printf("STACK IS FULL");
	        	exit(1);
			}
	        front=rear;
	    }
	    else
		{
			rear=(struct queue *)malloc(sizeof(struct queue));
			if(rear==NULL){
				printf("STACK IS FULL");
	        	exit(1);
			}
	        prev->next=rear;
		}
		rear->info=x;
		rear->next=NULL;
		prev=rear;
		printf("\nElement Inserted...");
	}

	void Delete()
	{
		struct queue *temp;
	    if(front == NULL)
	    {
	        printf("QUEUE IS EMPTY");
	        exit(1);
	    }
	    temp=front;
	    front=temp->next;
	    free(temp);
	    
	}





	void display()
	{
	    struct queue *temp=front;
	    printf("Display : \t");
	    if(temp == NULL)
	    {
	        printf("QUEUE IS EMPTY");
	        exit(1);
	    }
	    while(temp!=NULL){
			printf("%d\t",temp->info);
			temp = temp->next;
	    } 
	}







