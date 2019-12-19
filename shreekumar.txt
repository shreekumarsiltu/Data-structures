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
    while(1)
    {
        printf("\n 1.PUSH");
        printf("\n 2.POP");
        printf("\n 3.DISPLAY");
        printf("\n 4.PEEK");
        printf("\n 5.EXIT");
        int ch;
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        int x;
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                x = pop();
                printf("\nElement deleted from stack : %d\n",x);
                break;
            case 3:
                display();
                break;
            case 4:
                x = peek();
                printf("Top element of stack : %d \n",x);
                break;
            case 5:
                exit(1);
            default:
                printf("\nInvalid choice");
        }
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


