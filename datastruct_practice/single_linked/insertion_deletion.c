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

void delete(struct Node **root,int item)
{

	struct Node *cur= *root ,*prv;

	if(*root==NULL)
	{
		printf("there is no node to delete \n");
		return;
	}
	else if(cur->data==item)
	{
		*root=cur->next;
		 free(cur);
		 return;
	}
	while(cur)
	{
		prv=cur;
		cur=cur->next;
		if(cur->data==item)
		{
			prv->next=cur->next;
			free(cur);
			break;
		}
	}
	if(cur==NULL)
		printf("enterd element is not available \n");
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
		printf("1.Insert 2.Delete 3.Print 4.exit : \n");
		scanf("%d",&num);
		switch(num)
		{
			case 1 : printf("enter the data : \n");
				 scanf("%d",&value);
				 insertion(&Top,value);
				 break;
				 
			case 2: printf("enter the data to delete : \n");
				scanf("%d", &value);
				delete(&Top,value);
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

