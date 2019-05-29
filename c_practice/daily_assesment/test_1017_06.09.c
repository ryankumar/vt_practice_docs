#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
	char data;
	struct st *next;
}Node;


void push( Node** top, char item);
char pop(Node** top);



int isTrue(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else
		return 0;
}


int expression(char *ch)
{
	int i = 0;
	char res;
	Node *stack = NULL;
	while (ch[i])
	{
		if (ch[i] == '{' || ch[i] == '(')
			push(&stack, ch[i]);
		if (ch[i] == '}' || ch[i] == ')')
		{
			if (stack == NULL)
				return 0; 
			res=pop(&stack);
			if ( !isTrue(res, ch[i]) )
				return 0;
		}
		i++;
	}



	if (stack == NULL)
		return 1; 
	else
		return 0; 
} 

void push(Node** top, char item)
{

	Node* temp =(Node*) malloc(sizeof(Node));

	if (temp == NULL)
	{
		printf("Stack overflow n");
		exit(0);
	}


	temp->data  = item;
	temp->next =(*top);
	(*top)    = temp;
}


char pop(Node** top)
{
	char res;
	Node *temp;


	if (*top == NULL)
	{
		printf("Stack overflow n");
		exit(0);
	}
	else
	{
		temp = *top;
		res = temp->data;
		*top = temp->next;
		free(temp);
		return res;
	}
}


int main()
{
	char ch[20] = "{((my name is rayn)}";
	int res;
	res=expression(ch);
	if(res)
		printf("Correct \n");
	else
		printf("Incorrect \n");  
	return 0;
}    




