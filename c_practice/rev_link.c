#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void traverse(struct node *root);

struct node *rev_link(struct node *root)
{
	struct node *cur=root, *prv=root,*tmp=NULL;
	cur=cur->next;
	if(cur)
	tmp=cur->next;
	while(cur)
	{
		cur->next=prv;
		prv=cur;
		cur=tmp;
		if(cur)
		tmp=cur->next;
	}
	root->next=NULL;
	root=prv;
	return root;
}
int main()
{

	struct node *root=NULL,*cur=NULL;
	char ch;
	int info;
	do{
		printf("\nenter the node\n");
		scanf("%d",&info);
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->data=info;
		temp->next=NULL;
		if(root==NULL)
		{
			root=temp;
			cur=temp;
		}
		else
		{
			cur->next=temp;
			cur=temp;
		}

		printf("do you want to insert again y:yes n:no  :");
		scanf("\n%c",&ch);
	}while(ch=='y');

	traverse(root);
	root=rev_link(root);
	printf("print revese link\n");
	traverse(root);
	return 0;
}

void traverse(struct node *root)
{
	struct node *cur=root;
	if(root==NULL)
	{
		printf("no linked list\n");
		return;
	}

	while(cur)
	{
		printf("%d\n",cur->data);
		cur=cur->next;
	}
}

