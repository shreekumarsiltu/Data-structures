#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct STACK
{
    int items[10];
    int top;
};

struct STACK s;
struct STACK *p = &s;
void push(int);
int pop();
int isEmpty();
int isFull();
int peek();
void display();

void main()
{
    p->top = -1;
    int n,m=1;
	printf("enter a value :");
	scanf("%d",&n);
	
	while(n-1!=0)
	{
		push(n);
		n--;
	}
	while(p->top!=-1)
	{
		m=m*pop();
	}
	
	
	
	printf("factorial is : %d",m);
	getch();
}

void push(int n)
{
    if(isFull())
    {
        printf("STACK IS FULL");
        exit(1);
    }
    p->top++;
    p->items[p->top] = n;
}

int pop()
{
    if(isEmpty())
    {
        printf("STACK IS EMPTY");
        exit(1);
    }
    int x = p->items[p->top];
    p->top--;
    return x;
}

int peek()
{
    if(isEmpty())
    {
        printf("STACK IS EMPTY");
        exit(1);
    }
    int x = p->items[p->top];
    return x;
}

int isEmpty()
{
    if(p->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(p->top == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\n STACK IS EMPTY");
        exit(1);
    }
    for ( i = p->top; i >= 0 ; i--)
    {
        printf("\n %d \n",p->items[i]);
    }  
}


