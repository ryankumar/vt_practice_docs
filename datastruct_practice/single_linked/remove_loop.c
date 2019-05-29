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

void makeloop(struct Node **root)
{
	struct Node *cur=*root;
	while(cur->next)
	{
		cur=cur->next;
	}

	cur->next=(*root)->next->next;
}
struct Node* remove_loop(struct Node *s,struct Node *root)
{
	struct Node *ptr1;
	struct Node *ptr2;
	ptr1=root;
	ptr2=s;
	while(1)
	{
		while(ptr2->next!=s && ptr2->next!=ptr1)
			ptr2=ptr2->next;
		if(ptr2->next==ptr1)
		{
			ptr2->next=NULL;
			break;
		}

		ptr1=ptr1->next;
	}
	return root;
}



struct Node * check_loop(struct Node *root)
{
	struct Node *f=root, *s=root;
	while(f->next || f)
	{
		s=s->next;
		f=f->next->next;
		if(f==s)
		{
		root=remove_loop(s,root);
		return root;
		}
	}
	return 0;	
}

void print(struct Node *root)
{
	struct Node *cur=root;
	int k=0;
	if(cur==NULL)
	{
		printf("there is no node to print \n");
		return;
	}
	while(cur)
	{
		printf("%d->",cur->data);
		cur=cur->next;
		if(k>20)
			break;
		k++;
	}
	printf("NULL\n");
}

int main()
{
	int value,num,i=0,k,j=0,result=0;
	struct Node *Top=NULL,*Top1=NULL,*res=NULL;
	FILE *ret =freopen("/home/mahannee/empid-1017/datastruct_practice/single_linked/merge.txt", "r" ,stdin);
	if(ret==NULL)
	{
		printf("freopn() is failed \n");
		exit(1);
	}

	printf("how many nodes want to enter\n");
	scanf("%d",&num);

	printf("enter nodes :\n");
	while(i<num)
	{
		scanf("%d",&value);
		insertion(&Top,value);
		i++;
	}
	printf("linked list\n");
	print(Top);

	makeloop(&Top);
	print(Top);
	Top=check_loop(Top);
	if(Top==0)
		printf("there is no loop");
	else
	print(Top);
	return 0;	
}

