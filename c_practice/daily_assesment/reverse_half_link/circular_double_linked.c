#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};



struct node *cur=NULL;


// PRINT LINKED LIST
void print_front(struct node *root)
{
	struct node *temp=root;
	if(root==NULL)
	{
		printf("no linked list\n");
		return;
	}
	while(temp->next && temp->next!=root)
	{
		printf("%d     %p\n",temp->data,temp);
		temp=temp->next;
	}
	printf("%d     %p\n",temp->data,temp);

}



// PRINT LINKED LIST
void print_reverse(struct node *tail)
{
	struct node *temp=tail;
	if(tail==NULL)
	{
		printf("no linked list or no double linked list \n");
		return;
	}
	while(temp->prev && temp->prev!=tail)
	{
		printf("%d     %p\n",temp->data,temp);
		temp=temp->prev;
	}
	printf("%d     %p\n",temp->data,temp);	

}


// CREATE NODES
struct node *insert(struct node *root,int data)
{

	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(root==NULL)

		root=temp;
	else
		cur->next=temp;
	cur=temp;
	return root;
}

struct node *double_ll(struct node *root)
{
	struct node *temp=root;
	if(root==NULL)
	{
		printf("there is no node \n");
		return 0;
	}
	while(temp->next)
	{
		temp->next->prev=temp;
		temp=temp->next;
	}
	temp->next=root;
	root->prev=temp;
	return root;
}

void free_memory(struct node *root)
{
	struct node *tail=NULL;
	struct node *temp=NULL;

	tail=root->prev;
	while(root!=tail)
	{
		temp=root->next;
		temp->prev=tail;
		tail->next=temp;
		free(root);
		root=temp;
	}
	free(root);
	root='\0';
}

int main()
{

	struct node *root=NULL;

	char ch;
	int info,choose;

	while(1)
	{
		printf("choose one 1.single_ll(),2.double_ll(),3.print_front(),4.print_reverse(),5.exit() :");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:printf("enter nodes:");
			       scanf("%d",&info);
			       root=insert(root,info);
			       break;
			case 2: root=double_ll(root);
				break;
			case 3: print_front(root);
				break;
			case 4: if(root==NULL)
				{
					printf("atleast one node required\n");
					break;
				}
				print_reverse(root->prev);
				break;
			default : goto end;
		}
	}

end:
	// free memory
	if(root)
		free_memory(root);
	return 0;
}



