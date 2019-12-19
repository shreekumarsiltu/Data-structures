#include <stdio.h>
#include <stdlib.h>

struct STACK
{
    int items[5];
    int top;
};

struct STACK s;
struct STACK *p = &s;
void push();
int pop();
int isEmpty();
int isFull();
int peek();
void display();

void main()
{
    p->top = -1;
    printf("Enter an expression : ");
    while(1){
		char ch;
		scanf("%c",&ch);
		
    }
}

void push()
{
    if(isFull())
    {
        printf("STACK IS FULL");
        exit(1);
    }
    int x;
    printf("\nEnter a value : ");
    scanf("%d",&x);
    p->top++;
    p->items[p->top] = x;
    printf("Element pushed to stack\n");
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


