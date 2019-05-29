#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

struct file
{
	char data;
	struct file *next;
};

// insert open brackets to structure
struct file *insert_char(char ch,struct file *top)
{
	struct file *temp=(struct file *) malloc(sizeof(struct file));
	temp->data=ch;
	temp->next=NULL;
	if(top!=NULL)
		temp->next=top;
	top=temp;
	return top;
}

// checking open and close brackets
int ismatching(char ch,struct file *top)
{
	if(top==NULL)
		return 0;
	if(ch=='}' && top->data=='{')
		return 1;
	else if(ch==']' && top->data=='[')
		return 1;
	else if(ch==')' && top->data=='(')
		return 1;
	else 
		return 0;

}

//free pointer
void free_pointer(struct file *top)
{
	struct file *temp=NULL;
	while(top)
	{
		temp=top;
		top=top->next;
		free(temp);
	}
}

// Reading i/p file
void read_file(int fd)
{
	char ch;
	struct file *top=NULL,*temp=NULL;

	while(read(fd,&ch,1))
	{
		if(ch=='{' || ch=='(' || ch=='[')
		{
			top=insert_char(ch,top);
		}

		else if(ch=='}' || ch==')' || ch==']')
		{
			if(ismatching(ch,top)){
				temp=top;
				top=top->next;
				free(temp);
			}
			else
			{
				printf("compilation failed \n");
				return ;
			}

		}

	}
	if(top!=NULL)
		printf("compilation failed\n");
	else
		printf("compilation Pass\n");
	free_pointer(top);

}


int main(int argc,char *argv[])
{
	int fd;
	if(argc<2){
		printf("requires two arguments; ex; ./a.out test.txt\n");
		exit(0);
	}

	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("error:");
		exit(0);
	}

	read_file(fd);

	return 0;
}



	 
