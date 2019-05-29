#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *cur=NULL;
void traverse(struct node *root);
struct node *construct_reverse_link(struct node *root,
		                    struct node *second_half,
				    struct node *middle);

// REVERSE LINKED LIST
struct node *rev_link(struct node *root)
{
	struct node *current=root, *prv=root,*tmp=NULL;
	current=current->next;
	if(current)
		tmp=current->next;
	while(current)
	{
		current->next=prv;
		prv=current;
		current=tmp;
		if(current)
			tmp=current->next;
	}
	root->next=NULL;
	root=prv;
	return root;
}

// CREATE NODES
struct node *create_node(struct node *root,int data)
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


// DIVIDED THE LINKED LIST INTO 2 or 3 PARTS
struct node *split_linked(struct node *root)
{
	struct node *middle=NULL,*second_half_node=NULL,*prv=NULL;
	struct node *slow=root, *fast=root;

	if(slow->next==NULL)
		return root;

	while(fast->next &&  fast->next->next)
	{
		prv=slow;
		slow=slow->next;
		fast=fast->next->next;
	}

	// for odd number of linked list
	if(fast->next==NULL)
	{
		middle=slow;
		second_half_node=slow->next;
		prv->next=NULL;
		middle->next=NULL;
	}
	
	// for even number of linked list
	else{
		second_half_node=slow->next;
	        slow->next=NULL;
	}
	
	root=rev_link(root);
	second_half_node=rev_link(second_half_node);
	root=construct_reverse_link(root,second_half_node,middle);
	return root;
}

// JOINT THE LINKED LIST 
struct node *construct_reverse_link(struct node *root,
				    struct node *second_half,
				    struct node *middle)
{
	struct node * temp=root;
	while(temp->next)
	{
		temp=temp->next;
	}

	if(middle)
	{
		temp->next=middle;
		middle->next=second_half;
	}
	else
		temp->next=second_half;
	return root;
}


int main()
{

	struct node *root=NULL;
	struct node *temp=NULL;
	char ch;
	int info;
	printf("insert node for linked list\n");
	do{
		printf("enter nodes:");
		scanf("%d",&info);
		root=create_node(root,info);
		printf("Do you want to insert again y:yes n:no :");
		scanf("\n%c",&ch);
	}while(ch=='y');

	printf("\n************************************ Before reverse ****************************\n");
	traverse(root);
	root=split_linked(root);
	printf("\n************************************ After reverse *****************************\n");
	traverse(root);
	
	//free the memory
	while(root)
	{
		temp=root->next;
		free(root);
		root=temp;
	}
	free(cur);
	return 0;
}



