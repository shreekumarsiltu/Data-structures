#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int fact(int n){
	if(n==1){
		return 1;
	}
	else{
		return n*fact(n-1);
	}
}
int main(){
	int n,m;
	printf("enter a value :");
	scanf("%d",&n);
	m=fact(n);
	printf("factorial is : %d",m);
	getch();
}
