#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int items[10];
    int front;
    int rear;
};

struct queue q;
struct queue *p = &q;
void insert(int);
void Delete();
void display();

void main()
{
    p->rear = -1;
    p->front = 0;
    int ch,val;
    while(1)
    {
        printf("\n 1.Insert");
        printf("\n 2.delete");
        printf("\n 3.DISPLAY");
        printf("\n 4.EXIT");
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
                break;
            default:
                printf("\nInvalid choice");
        }
    }
}

void insert(int x)
{
    if(p->rear==9)
    {
        printf("QUEUE IS FULL");
        exit(1);
    }
    p->rear++;
    p->items[p->rear] = x;
    printf("Element inserted to queue\n");
}

void Delete()
{
    if(p->front>p->rear)
    {
        printf("QUEUE IS EMPTY");
        exit(1);
    }
    p->front++;
}

void display()
{
    int i;
    if (p->front > p->rear)
    {
        printf("\n QUEUE IS EMPTY");
        exit(1);
    }
    for ( i = p->front; i <= p->rear ; i++)
    {
        printf(" %d \t",p->items[i]);
    }  
}


