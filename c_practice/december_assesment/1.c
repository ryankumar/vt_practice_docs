#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h> 

/* Link list node */
struct node 
{ 
	int data; 
	struct node* next; 
}; 

struct node *cur=NULL;

int ascent=0 , descent=0;

struct node* SortedMerge(struct node* root1, struct node* root2)  
{ 
	struct node * result = NULL;
	struct node ptr;
	result=&ptr;

	// Ascending order
	if(ascent)
	{
		while(root1 && root2){
			if(root1->data <= root2->data){
				result->next=root1;
				root1=root1->next;
			}
			else
			{
				result->next=root2;
				root2=root2->next;
			
			}
			result=result->next;
		}
		if(root1==NULL)
			result->next=root2;
		else if(root2==NULL)
			result->next=root1;
	}

	// Descending order
	else
	{
		while(root1 || root2){
			if(root1->data >=root2->data){
				result->next=root1;
				root1=root1->next;
			}
			else
			{
				result->next=root2;
				root2=root2->next;
			}
			result=result->next;
		}
		if(root1==NULL)
			result->next=root2;
		else if(root2==NULL)
			result->next=root1;



	}

	return(ptr.next); 
} 




/* Function to print nodes in a given linked list */
void printList(struct node *node) 
{ 
	while (node!=NULL) 
	{ 
		printf("%d %p\n", node->data ,node); 
		node = node->next; 
	} 
} 

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



int main() 
{ 

	struct node* hptr1 = NULL ,*hptr2=NULL; 
	struct node* head1 = NULL; 
	struct node* head2 = NULL;
	struct node* res=NULL;
	int data; 
	int size1,size2;

	printf("enter the size1 for 1st ll and for 2nd ll :");
	scanf("%d%d",&size1,&size2);
	printf("enter elements for ll1\n");
	for(int i=0;i<size1;i++){
		scanf("%d",&data);
		head1=create_node(head1,data);
	}

	cur=NULL;
	printf("enter the elements for ll2\n");
	for(int i=0;i<size2;i++)
	{
		scanf("%d",&data);
		head2=create_node(head2,data);
	}


	if(head1==NULL && head2==NULL)
	{
		printf("At least one linked list required\n");
		return 0;
	}
	hptr1=head1;
	hptr2=head2;
	if(hptr1==NULL){
		printf("merging sort is :");
		printList(head2);
		return 0;
	}
	if(hptr2==NULL)
	{
		printf("merging sort is :");
		printList(head1);
		return 0;
	}


	while(hptr1 && hptr2 )
	{
		if(hptr1->next && hptr2->next)
		{
			if((hptr1->data < hptr1->next->data) && (hptr2->data < hptr2->next->data))
			{
				ascent++;
				break;
			}
			else if((hptr1->data > hptr1->next->data) && (hptr2->data > hptr2->next->data))
			{
				descent++;
				break;
			}
			hptr1=hptr1->next;
			hptr2=hptr2->next;
		}
		else
			break;
	}

	if(hptr1->next== NULL && hptr2->next !=NULL)
	{
		while(hptr2){
			if(hptr2->data < hptr2->next->data){
				ascent++;
				break;
			}
			else  if(hptr2->data > hptr2->next->data){

				descent++;
				break;
			}
			hptr2=hptr2->next;
		}
	}
	else if(hptr2->next== NULL && hptr1->next !=NULL)
	{
		while(hptr1){
			if(hptr1->data < hptr1->next->data){
				ascent++;
				break;
			}
			else  if(hptr1->data > hptr1->next->data){

				descent++;
				break;
			}
			hptr1=hptr1->next;
		}
	}


	res = SortedMerge(head1,head2); 

	printf("Merged Linked List is: \n"); 
	printList(res); 

	return 0; 
} 
