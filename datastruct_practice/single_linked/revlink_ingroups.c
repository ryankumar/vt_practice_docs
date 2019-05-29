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

struct Node * revlink(struct Node *root,int k)
{
	struct Node *cur=root, *prv=NULL, *nnext=NULL;
	int count=0;
	while(cur && count<k)
	{
		nnext=cur->next;
		cur->next=prv;
		prv=cur;
		cur=nnext;
		count++;
	}

	if(cur)
		root->next=revlink(nnext,k);
	return prv;


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
	int value,num,i=0,k,j=0;
	struct Node *Top=NULL,*Top1=NULL,*res=NULL;
	FILE *ret =freopen("/home/mahannee/empid-1017/datastruct_practice/single_linked/merge.txt", "r" ,stdin);
	if(ret==NULL)
	{
		printf("freopn() is failed \n");
		exit(1);
	}

	printf("how many nodes want to enter\n");
	scanf("%d",&num);
	printf("what is the max.group \n");
	scanf("%d",&k);
	printf("enter nodes in sorted order :\n");
	while(i<num)
	{
		scanf("%d",&value);
		insertion(&Top,value);
		i++;
	}
	printf("linked list\n");
	print(Top);

	Top=revlink(Top,k);
	printf("after merging linked list :\n");
	print(Top);
	return 0;	
}

