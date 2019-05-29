#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node *latest=NULL;
void insertion(struct Node **root, int item)
{
	struct Node *ptr=(struct Node *)malloc (sizeof(struct Node));
	ptr->data=item;
	if(*root==NULL)
	{
		*root=ptr;
		latest=*root;
	}
	else
	{
		latest->next=ptr;
		latest=ptr;
	}
	ptr->next=NULL;
}

struct Node * merge(struct Node *l1,struct Node *l2)
{
	struct Node *cur=NULL;

	if(l1==NULL)
		return l2;
	else if(l2==NULL)
		return l1;
	if(l1->data <= l2->data)
	{
		cur=l1;
		cur->next=merge(l1->next,l2);
	}

	else
	{
		cur=l2;
		cur->next=merge(l1,l2->next);
	}
	return cur;
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
	int value,num,i=0,num1,j=0;
	struct Node *Top=NULL,*Top1=NULL,*res=NULL;
	FILE *ret =freopen("/home/mahannee/empid-1017/datastruct_practice/single_linked/merge.txt", "r" ,stdin);
	if(ret==NULL)
	{
		printf("freopn() is failed \n");
		exit(1);
	}

	printf("how many nodes want to enter for 1st linked list and 2nd linked list\n");
	scanf("%d%d",&num,&num1);
	printf("enter nodes in sorted order :\n");
	while(i<num)
	{
		scanf("%d",&value);
		insertion(&Top,value);
		i++;
	}
	printf("1st linked list\n");
	print(Top);
	while(j<num1)
	{
		scanf("%d",&value);
		insertion(&Top1,value);
		j++;
	}
	printf("2nd linked list\n");
	print(Top1);

	res=merge(Top,Top1);
	printf("after merging linked list :\n");
	print(res);
	return 0;	
}

