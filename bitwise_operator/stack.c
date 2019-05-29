#include<stdio.h>
#include<stdlib.h>
#define SIZE 10 
int top=-1;
int arr[SIZE];
void push(int ele)
{
	if(top==SIZE-1)
	{
		printf("stack is full\n");
		return ;
	}

	else
		arr[++top]=ele;
}

void pop()
{

	if(top<0)
	{
		printf("stack is empty\n");
		return ;
	}

	else
		printf("pop element :%d\n",arr[top--]);

}

int main()
{
	int choice;
	int ele;
	while(1)
	{
		printf("enter choice 1.push 2.pop 3.exit :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :printf("enter element for push : "); 
				scanf("%d",&ele);
				push(ele); 
				break;
			case 2 : pop() ; 
				 break;
			default : exit(1);
		}
	}

}

