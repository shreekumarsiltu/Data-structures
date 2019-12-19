#include<stdio.h>
#include<stdlib.h>
struct stack{
	int info;
	struct stack* next;
};
struct stack* top=NULL;
void push();
void pop();
void display();
void main(){
	while(1){
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
                pop();
                printf("\nElement deleted from stack : %d\n",x);
                break;
            case 3:
                display();
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
		struct stack *curr=(struct stack *)malloc(sizeof(struct stack));
	    if(curr==NULL)
	    {
	        printf("STACK IS FULL");
	        exit(1);
	    }
	    printf("\nEnter a value : ");
	    scanf("%d",&curr->info);
	    curr->next=top;
		top=curr;
	    printf("Element pushed to stack\n");
	}

	void pop()
	{
		struct stack *temp=top;
	    if(temp == NULL)
	    {
	        printf("STACK IS EMPTY");
	        exit(1);
	    }
	    top=temp->next;
	    free(temp);
	    
	}





	void display()
	{
	    struct stack *temp=top;
	    printf("Display");
	    if(temp == NULL)
	    {
	        printf("STACK IS EMPTY");
	        exit(1);
	    }
	    while(temp!=NULL){
			printf("%d\n",temp->info);
			temp = temp->next;
	    } 
	}







