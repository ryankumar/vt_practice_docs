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

void swap(struct Node **root,int a,int b )
{
	struct Node *cura=*root, *prva=NULL, *curb=*root ,*prvb=NULL;
	struct Node *temp=NULL;
	if(*root==NULL )
	{
		printf("there is no node to swap \n");
		return;
	}

	if(a==b)
	{
		printf("both node are same\n");
		return;
	}

	while(cura!=NULL && cura->data!=a )
	{
		prva=cura;
		cura=cura->next;
	}

	while(curb!=NULL && curb->data!=b)
	{
		prvb=curb;
		curb=curb->next;
	}

	if(cura==NULL || curb==NULL)
	{
		printf("one of the node data is not availabe \n");
		return;
	}


	else 
	{
		if(prva!=NULL)
			prva->next=curb;
		else
			*root=curb;
		if(prvb!=NULL)
			prvb->next=cura;
		else
			*root=cura;

		temp=cura->next;
		cura->next=curb->next;
		curb->next=temp;
	}

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
	int value,num,a,b;
	struct Node *Top=NULL;

	while(1)
	{
		printf("choose one muber for : 1.Insert 2.swap 3.Print 4.exit : \n");
		scanf("%d",&num);
		switch(num)
		{
			case 1 : printf("enter the data : \n");
				 scanf("%d",&value);
				 insertion(&Top,value);
				 break;

			case 2: printf("enter the two number to swap : \n");
				scanf("%d%d", &a,&b);
				swap(&Top,a,b);
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

