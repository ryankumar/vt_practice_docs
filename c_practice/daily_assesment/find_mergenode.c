// complixity of finding node: m=number of 1st ll , n=number of 2nd ll ,t=number of linking nodes



#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};


struct node *find_node(struct node *head1,struct node *head2)
{
	struct node *cur1=head1;
	struct node *cur2=NULL;
	int flag=0;
	if(head2==NULL || head1==NULL)
	{
		printf("there is no linkage node\n");
		return 0;
	}

	while(cur1)
	{
		cur2=head2;
		while(cur2)
		{
			if(cur1==cur2)
			{
				flag=1;
				break;
			}
			cur2=cur2->next;
		}
		if(flag==1)
			break;
		cur1=cur1->next;
	}
	return cur1;
}

struct node * create_node(struct node *root,int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(root)
		temp->next=root;
	root=temp;
	return root;
}


void display(struct node *root1,struct node *root2)
{
	struct node *cur1=root1, *cur2=root2;
	if(root1==NULL)
		printf("there is no node in 1st linked list\n");
	if(root2==NULL)
		printf("there is no node in 2nd linked list\n");

	if(root1)
	{
		printf("1st linked list:\n");
		while(cur1)
		{
			printf("%d  %p\n",cur1->data,cur1);
			cur1=cur1->next;
		}
		printf("HEAD1 :%p\n",root1);
	}

	if(root2)
	{
		printf("2nd linked list:\n");
		while(cur2)
		{
			printf("%d  %p\n",cur2->data,cur2);
			cur2=cur2->next;
		}
		printf("HEAD2 :%p\n",root2);
	}
}


int main()
{
	int PASS=0,FAIL=0 ,count=0;
	struct node *head1=NULL ,*head2=NULL;
	struct node *ret=NULL;
	struct node *temp=NULL;
	struct node *cur1=NULL,*cur2=NULL;
	struct node *hptr2=NULL;
	int num1=1,num2=5;
	int size1,size2;
	printf("enter the size1 for 1st ll and for 2nd ll :");
	scanf("%d%d",&size1,&size2);
	for(int i=0;i<size1;i++)
		head1=create_node(head1,num1++);
	for(int i=0;i<size2;i++)
		head2=create_node(head2,num2++);
	cur1=head1;
	cur2=head2;
	hptr2=head2;
	display(head1,head2);
	if(cur1 && cur2)
	{
		while(cur1->next)
		{
			cur1=cur1->next;
		}

		while(cur2->next)
		{
			cur2=cur2->next;
		}
	}

	while(count<7)
	{
		// TEST CASES1: merge end of node of 2nd linked list in the middle of 1st linked list
		// complexity=[(m-t) *(n+t)]+(n+1);  m=number of 1st ll , n=number of 2nd ll ,t=number of linking nodes
		if(count==0)
		{	
			if(head1 && head2)
			cur2->next=head1->next->next->next;
			ret=find_node(head1,head2);
			if(ret){
				printf("node found at %p :\n",ret);
				PASS++;
			}
			else
				FAIL++;
			count+=1;
			cur2->next=NULL;
		}


		// TEST CASES2: merge end of node of 2nd linked list in the last of 1st linked list
		// complexity=[(m-t) *(n+t)]+(n+1);  m=number of 1st ll , n=number of 2nd ll ,t=number of linking nodes
		else if(count==1)
		{	
			if(head1 && head2)
			cur2->next=cur1;
			ret=find_node(head1,head2);
			if(ret)
			{
				printf("node found at %p :\n",ret);
				PASS++;
			}
			else
				FAIL++;
			count+=1;
			cur2->next=NULL;
		}

		// TEST CASES3: merge end of node of 2nd linked list in the 1st node of 1st linked list
		// complexity= n+1;  m=number of 1st ll , n=number of 2nd ll ,t=number of linking nodes
		else if(count==2)
		{
			if(head1 && head2)
			cur2->next=head1; 
			ret=find_node(head1,head2);

			if(ret)
			{
				printf("node found at %p :\n",ret);
				PASS++;
			}
			else
				FAIL++;
			count+=1;
			cur2->next=NULL;
		}

		// TEST CASES4: head2  at any point of 1st linked list except next to end of node
		// complexity= (m *(m-t))+(m-t+1);  m=number of 1st ll , n=number of 2nd ll ,t=number of linking nodes
		else if(count==3)
		{
			if(head1 && head2)
			head2=head1->next->next;
			ret=find_node(head1,head2);

			if(ret)
			{
				printf("node found at %p :\n",ret);
				PASS++;
			}
			else
				FAIL++;
			count+=1;
			head2=hptr2;
		}

		// TEST CASES5: head2 is at next to end of node of 1st liked list
		// complexity=[((m+n) * m)+(m+1)];  m=number of 1st ll , n=number of 2nd ll ,t=number of linking nodes
		else if(count==4)
		{
			if(head1 && head2)
			cur1->next=head2;
			ret=find_node(head1,head2);

			if(ret)
			{
				printf("node found at %p :\n",ret);
				PASS++;
			}
			else
				FAIL++;
			count+=1;
			cur1->next=NULL;
		}

		// TEST CASES6: if head2 is NULL or no linkage
		// complecity= zero; 
		else if(count==5)
		{	
			ret=find_node(head1,head2);

			if(ret)
			{
				printf("node found at %p :\n",ret);
				PASS++;
			}
			else
				FAIL++;
			count+=1;
		}

		// TEST CASES7: if head1 is NULL or no linkage
		// complexity= zero;
		else if(count==6)
		{
			ret=find_node(head1,head2);
			if(ret)
			{
				printf("node found at %p :\n",ret);
				PASS++;
			}
			else
				FAIL++;
			count+=1;
		}
	}


	while(head1)
	{
		temp=head1->next;
		free(head1);
		head1=temp;
	}
	while(head2)
	{
		temp=head2->next;
		free(head2);
		head2=temp;
	}

	printf("total count %d\n",count);
	printf("PASS :%d\n",PASS);
	printf("FAIL :%d\n",FAIL);

	return 0;
}


