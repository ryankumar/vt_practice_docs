#include<stdio.h>
#include<stdlib.h>
#define SIZE1 5
#define SIZE2 5
int top1=-1;
int top2=-1;
int stack1[SIZE1];
int stack2[SIZE2] ;
int temp[SIZE1];

void push_stack1(int ele)
{
	if(top1==SIZE1-1)
	{
		printf("stack is full\n");
		return ;
	}

	else
		stack1[++top1]=ele;
}

void push_stack2(int ele)
{
	if(top2==SIZE2-1)
	{
		printf("stack is full\n");
		return ;
	}

	else
		stack2[++top2]=ele;
}
void pop_stack1()
{

	if(top1<0)
	{
		printf("stack is empty\n");
		return ;
	}

	else
		printf("pop element :%d\n",stack1[top1--]);

}


void pop_stack2()
{

	if(top2<0)
	{
		printf("stack is empty\n");
		return ;
	}

	else
		printf("pop element :%d\n",stack2[top2--]);

}

void merge()
{
	int top;
	int temp_top=0;

	if(top1<0 | top2<0)
	{
		printf("Stack1 or stack2 is empty\n");
		return ;
	}

	// Merging STACK1 with STACK2
	if( top1 < (SIZE2 - top2 -1))
	{
		top=top1;
		while(top>=0)
		{
			temp[temp_top++]=stack1[top];
			top--;
		}
		while(temp_top>0)
		{
			temp_top--;
			push_stack2(temp[temp_top]);

		}
	}

	// Merging STACK2 with STACK1
	else if( top2 < (SIZE1 - top1 -1))
	{
		top=top2;
		while(top>=0)
		{
			temp[temp_top++]=stack2[top];
			top--;
		}
		while(temp_top>0)
		{
			temp_top--;
			push_stack1(temp[temp_top]);
		}
	}

	else
		printf("merging is not poissible \n");

}

void print()
{
	int t1=top1;
	int t2=top2;
	if(top1>=0)
	{
		printf("stack1 :");
		while(t1>=0){
			printf("%d",stack1[t1]);
			t1--;
		}
	}

	printf("\n");
	if(top2>=0)
	{
		printf("stack2 :");
		while(t2>=0){
			printf("%d",stack2[t2]);
			t2--;
		}
	}
	printf("\n");

}

int main()
{
	int choice;
	int ele;
	while(1)
	{
		printf("enter choice 1.push_stack1 2.push_stack2 3.pop_satck1 4.pop_stack2 5.merge(stack1,stack2) 6.print() 7.exit() :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :printf("enter element for push_stack1 : "); 
				scanf("%d",&ele);
				push_stack1(ele); 
				break;
			case 2 : printf("enter element for push_stack2 : ");
				 scanf("%d",&ele);
				 push_stack2(ele); 
				 break;
			case 3 : pop_stack1();
				 break;
			case 4: pop_stack2();
				break;
			case 5: merge();
				break;

			case 6 : print();
				 break;

			default : exit(1);
		}
	}

}

