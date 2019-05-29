#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Node * add_ll(struct Node *root1 ,struct Node *root2)
{
	struct Node *new=NULL,*temp=NULL,*prv=NULL;
	int carry=0,rem=0,sum=0;
	int data1=0,data2=0;
	if(root1==NULL)
		return root2;
	if(root2==NULL)
		return root1;
	while(root1 || root2)
	{
		temp=(struct Node*) malloc(sizeof(struct Node));
		if(root1)
		 data1=root1->data;
		else
		 data1=0;
		if(root2)
		 data2=root2->data;
		else
		 data2=0;
		sum=data1 + data2 +carry;
		rem=sum % 10;
		carry=sum / 10;
		temp->data=rem;
		temp->next=NULL;
		if(new==NULL)
			new=temp;
		else
			prv->next=temp;
		prv=temp;
		if(root1)
		root1=root1->next;
		if(root2)
		root2=root2->next;
	}
	if(carry>0){
		temp=(struct Node*) malloc(sizeof(struct Node));
		temp->data=carry;
		temp->next=NULL;
		prv->next=temp;
		prv=temp;
	}
	return new;
}


void insertion(struct Node **root,int item)
{
			
	struct Node *cur=(struct Node*) malloc(sizeof(struct Node));
	cur->data=item;
	if(*root==NULL)
	{
		*root=cur;
	}
	else
		cur->next=*root;
		*root=cur;
}

void print(struct Node *root)
{
	struct Node *cur=root;
	if(cur==NULL)
	{
		printf("there is no node\n");
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
	struct Node *head=NULL,*head2=NULL,*sum=NULL;
	int n1,n2,value;
	printf("enter no. of nodes for 1st string and 2nd string\n ");
	scanf("%d%d",&n1,&n2);
	printf("enter data for two linked list\n");
	for(int i=0;i<n1;i++)
	{
		scanf("%d",&value);
		insertion(&head,value);
	}
	for(int i=0;i<n2;i++)
	{
		scanf("%d",&value);
		insertion(&head2,value);
	}
	printf("1st linked list :\n");
	print(head);
	printf("2nd linked list :\n");
	print(head2);
	
	sum=add_ll(head,head2);
	printf("sum of two node is\n");
	print(sum);
	return 0;
}

