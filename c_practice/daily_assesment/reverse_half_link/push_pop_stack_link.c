#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};



// Insert node into stack
struct node *push_into_stack(struct node *root,int data)
{

	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(root)
		temp->next=root;
	root=temp;
	
	return root;
}

// pop data from stack
struct node *pop_from_stack(struct node *root)
{
	struct node *top=NULL;
	if(root==NULL)
	{
		printf("stack is empty\n");
		return 0;
	}
	else
	{
		top=root;
		root=root->next;
	}
	printf("popped data from stack is %d\n",top->data);
	free(top);
	return root;
}
		
// PRINT LINKED LIST
void traverse(struct node *root)
{
	struct node *temp=root;
	if(root==NULL)
	{
		printf("no linked list\n");
		return;
	}
	while(temp)
	{
		printf("%d     %p\n",temp->data,temp);
		temp=temp->next;
	}

}


int main()
{

	struct node *root=NULL;
	struct node *temp=NULL;
	char ch;
	int info,choose;
	
	while(1)
	{
		printf("choose one of the operation  1. push_into_stack(), 2. pop_from_stack(), 3. display(), 4. enter any key for exit :");
		scanf("%d",&choose);
		switch(choose)
		{
		   case 1:printf("enter nodes:");
			  scanf("%d",&info);
			  root=push_into_stack(root,info);
			   	break;
		   case 2: root=pop_from_stack(root);
			   	break;
		   case 3: traverse(root);
				break;
		   default : goto end;
		}
	}

	//free the memory
end:
	while(root)
	{
		temp=root->next;
		free(root);
		root=temp;
	}

	return 0;
}



