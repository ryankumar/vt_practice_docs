// i/p: 1->2->3->4->5->6->7->8->9->NULL  k=3;
//o/p:3->2->1->4->5->6->9->8->7->NULL

#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	int item;
	struct st *next;
}stud;

void travers(stud *);
// reverse altrenate k node
stud * rev_alt(stud * head,int k)
{
	stud *cur=head,*pre=NULL,*temp=NULL;
	int i=0;
	stud *head_ref=cur;
	while(cur!=NULL && (i<k*2))
	{
		if(i<k)
		{
			temp=cur->next;
			cur->next=pre;
			pre=cur;
			cur=temp;
		}

		else
		{
			head_ref->next=cur;
                	head_ref=cur;
                	cur=cur->next;
		}
		i++;
	}

/*	while(cur!=NULL && (i<k*2))
	{
		head_ref->next=cur;
		head_ref=cur;
		cur=cur->next;
		i++;
	}
*/
	head_ref->next=NULL;
	if(cur)
		head_ref->next=rev_alt(cur,k);
	return pre;
			

}

int main()
{
	stud *head=NULL,*cur=NULL,*pre=NULL;
	int i=0;

	printf("enter nodes\n");
	while(i<9){
		stud *node=(stud *) malloc(sizeof(stud));
		scanf("%d",&node->item);
		node->next=NULL;
		if(head==NULL){
			head=node;
			cur=head;
		}
		else{
			cur->next=node;
			cur=node;
		}
		i++;
	}

	travers(head);

	head=rev_alt(head,3);
	travers(head);
}
// traversal of linked list
void travers(stud *head){
	stud *node=head;
	while(node!=NULL){
		printf("%d->",node->item);
		node=node->next;
	}
	printf("NULL\n");
}




