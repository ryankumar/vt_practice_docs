#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void insertion(struct Node **root, int item)
{
	struct Node *ptr=(struct Node *)malloc (sizeof(struct Node));
	ptr->data=item;
	if(*root==NULL)
	{
		*root=ptr;
		ptr->next=NULL;
	}
	else
	{
		ptr->next=*root;
		*root=ptr;
	}
}

void reverse(struct Node **root)
{
	struct Node *cur=*root,*prv=NULL, *nnext=NULL;

	if(cur==NULL)
	{
		printf("for reverse min 2 nodes required\n");
		return;
	}
	
	prv=cur;
	cur=cur->next;
	while(cur)
	{
		nnext=cur->next;
		cur->next=prv;
		prv=cur;
		cur=nnext;
	}

	(*root)->next=NULL;
	*root=prv;
}
void print(struct Node *root)
{
	struct Node *cur=root;
	if(cur==NULL)
	{
		printf("there is no node to print \n");
		return;
	}
	while(cur)
	{
		printf("%d->",cur->data);
		cur=cur->next;
	}
	printf("NULL\n");
}

int main()
{
	int value,num;
	struct Node *Top=NULL;

	while(1)
	{
		printf("choose one muber for : 1.Insert 2.reverse 3.Print 4.exit : \n");
		scanf("%d",&num);
		switch(num)
		{
			case 1 : printf("enter the data : \n");
				 scanf("%d",&value);
				 insertion(&Top,value);
				 break;

			case 2: reverse(&Top);
				break;

			case 3: printf("data in linked list : \n");
				print(Top);
				break;

			default : printf("you are exited succesfully \n");
				  return 0;

		}
	}

	return 0;	
}

