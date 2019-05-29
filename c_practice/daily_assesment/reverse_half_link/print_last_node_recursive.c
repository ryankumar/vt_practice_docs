#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *cur=NULL;
void traverse(struct node *root);


struct node *find_last_node(struct node *root)
{
	struct node *last_node=root;
	if(last_node->next==NULL)
		return last_node;
	find_last_node(last_node->next);
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

	printf("\n************************************ print nodes ****************************\n");
	traverse(root);
	temp=find_last_node(root);
	printf("\n************************************ last node *****************************\n");
	traverse(temp);
	
	//free the memory
	while(root)
	{
		temp=root->next;
		free(root);
		root=NULL;
		root=temp;
	}
	return 0;
}



