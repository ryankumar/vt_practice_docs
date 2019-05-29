// Iterative Queue based C program to do level order traversal 
// // of Binary Tree 
#include <stdio.h> 
#include <stdlib.h> 
#define MAX_Q_SIZE 500 

struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

/* frunction prototypes */
void enQueue(struct node **, int *, struct node *); 
struct node *deQueue(struct node **, int *); 

void printLevelOrder(struct node* root) 
{ 
	int rear=0, front=0; 
	struct node **queue = (struct node **) malloc(sizeof(struct node*) * MAX_Q_SIZE);
	struct node *temp_node = root; 

	while (temp_node) 
	{ 
		printf("%d ", temp_node->data); 

		/*Enqueue left child */
		if (temp_node->left) 
			enQueue(queue, &rear, temp_node->left); 

		/*Enqueue right child */
		if (temp_node->right) 
			enQueue(queue, &rear, temp_node->right); 

		/*Dequeue node and make it temp_node*/
		temp_node = deQueue(queue, &front); 
	} 
} 


void enQueue(struct node **queue, int *rear, struct node *new_node) 
{ 
	queue[*rear] = new_node; 
	(*rear)++;
	
} 

struct node *deQueue(struct node **queue, int *front) 
{ 
	(*front)++; 
	return queue[*front - 1]; 
} 


struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) 
		malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
} 


int main() 
{ 
	struct node *root = newNode(1); 
	root->left        = newNode(2); 
	root->right       = newNode(3); 
	root->left->left  = newNode(4); 
	root->left->right = newNode(5); 

	printf("Level Order traversal of binary tree is \n"); 
	printLevelOrder(root); 

	return 0; 
} 


