#include<stdio.h>
#include<conio.h>
#include<ctype.h>

struct STACK
{
    char items[20];
    int top;
};
struct STACK s;
struct STACK *p=&s;

void push(char);
char pop();
int priority(char);

void main()
{
    p->top=-1;
    char exp1[20],postfix[20];
    char x;
    printf("Enter the expression : ");
    gets(exp1);
    int len=strlen(exp1);
    int i=0;
    char exp[len];
    while(i<len){
		if(exp1[len-i-1]=='(')
		exp1[len-i-1]=')';
		else if(exp1[len-i-1]==')')
		exp1[len-i-1]='(';
		exp[i]=exp1[len-i-1];
		i++;
    }
    i=0;
	int j=0;
    while(exp[i]!='\0')
    {
        if(isalnum(exp[i]))
        {
            postfix[j]=exp[i];
            j++;
        }
        else if (exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            while((x=pop())!='(')
            {
                postfix[j]=x;
                j++;
            }
        }
        else
        {
            while(priority(p->items[p->top])>=priority(exp[i]))
            {
                postfix[j]=pop();
                j++;
            }
            push(exp[i]);
        }
        i++;
    }
    
    while(p->top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    
    int r=pop();
    printf("%d\n",r);
    
    printf("Postfix expression : \n");
    i=0;
    while (postfix[i]!='\0')
    {
        printf("%c",postfix[i]);
        i++;
    }
    int o=i;
    printf("\n\n");
    char exp2[o];
    i=0;
    while(i<o){
		exp2[i]=postfix[o-i-1];
		i++;
    }
    i=0;
    while (i<o)
    {
        printf("%c",exp2[i]);
        i++;
    }
    printf("\n\n");
  
    i=o-1;
    int z,y;
    char a,b;
    while(i>=0){
		if(isalnum(exp2[i])){
			push(exp2[i]);
			i--;
		}
		else{
			a=pop();
			b=pop();
			z=(int)a-48;
			y=(int)b-48;
			printf("\nz= :%d",z);
			printf("\ny= :%d",y);
			if(exp2[i]=='+')
			push(z+y+48);
			else if(exp2[i]=='-')
			push(z-y+48);
			else if(exp2[i]=='*')
			push(z*y+48);
			else if(exp2[i]=='/')
			push(z/y+48);
			i--;
		}
    }
    char m=pop();
    printf("\n%d",(int)m-48);
    
    
    
    getch();
}

void push(char x)
{
    p->top++;
    p->items[p->top]=x;
}

char pop()
{
    if (p->top==-1)
    {
        return -1;
    }
    else
    {
        int x=p->items[p->top];
        p->top--;
        return x;
    }
}

int priority(char x)
{
    if(x=='(')
    {
        return 0;
    }
    if(x=='+'||x=='-')
    {
        return 1;
    }
    if (x=='*'||x=='/')
    {
        return 2;
    }
    //else return 1; it is inevitable
}
