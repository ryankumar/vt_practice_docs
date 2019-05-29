
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define size 20
int arr[size]={0};
int front=-1 , rear=-1;
int size1,size2;
FILE *fd = NULL;
int diffe=0,diffq=0;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER; 


/* Function to create Circular queue */
void* enQueue()
{
	printf("enter the number of data want to insert\n");
	scanf("%d",&size1);
	int value[size1];


/*	diffe=front-size1;
	if(diffe<0)
	{
		diffe=size+diffe;
	}
*/
	pthread_mutex_lock(&mutex);
	
	// if QUEUE is not empty then send signal to DEQUEUE
	if (front != -1 && (size2<=(rear-front+1) || size2<=(size-(front-rear)+1)) )
	{
		pthread_cond_signal(&cond1);
	}

	// if QUEUE is full wait for space

	if ((front == 0 && (rear >= size-size1)) ||(rear >= (diffe)%(size-1)))
	{
		printf("\nQueue is Full or There is not enough space\n");
		pthread_cond_wait(&cond1, &mutex);
	}
	
	else{
	// input data for ENQUEUE operation
	for(int i=0;i<size1;i++)
		scanf("%d",&value[i]);

	for(int i=0;i<size1;i++)
	{	

		if (front == -1) /* Insert First Element */
		{
			front = rear = 0;
			arr[rear] = value[i];
		}

		else if (rear == size-1 && front != 0)
		{
			rear = 0;
			arr[rear] = value[i];
		}

		else
		{
			rear++;
			arr[rear] = value[i];
		}
	}
	printf("Enqued %d message \n",size1);
	printf("elements in stack is\n");
	for(int i=0;i<size;i++)
		printf("%d ", arr[i]);
	printf("\n");
	}
 	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
	exit(0);
}

// Function to delete element from Circular Queue
void * deQueue() 
{
	printf("enter the number of data want to DEQUEUE\n");
	scanf("%d",&size2);
	int data[size2];
	diffq=size+size2;
	if(diffq>size)
	{
		diffq=size2-size;
	}

	pthread_mutex_lock(&mutex);
	
	// if Queue have enough space
	if (((front == 0 && (rear < size-size1))) || (rear < (diffe)%(size-1)))
	{
		pthread_cond_signal(&cond1);
	}

	// if Queue is empty or not sufficient element
	if (front == -1 || size2>(rear-front+1) || size2>(size-(front-rear)+1) )
	{
		printf("\n QUEUE is empty");
		pthread_cond_wait(&cond2, &mutex);
	}
	else{

	for(int i=0;i<size2;i++)
	{

		data[i] = arr[front];
		arr[front] = -1;
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if (front == size-1)
			front = 0;
		else
			front++;
		fprintf(fd,"%5d  ",data[i]);
	}
	printf("Dequeued %d message \n",size2);
	}

	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
	exit(0);
}


/* Driver of the program */
int main()
{

	pthread_t t1,t2;
	int choice;
	void *t_res;
/*
	FILE *ret =freopen("/home/mahannee/empid-1017/empid-1017/test.txt", "r" ,stdin);
	if(ret==NULL)
	{
		printf("freopn() is failed \n");
		exit(1);
	}
*/
	fd=fopen("dequeue.txt","a");
	if(fd<0)
	{
		printf("open failed\n");
		return 0;
	}

	while(1){
		printf("enter the choice for 1.ENQUEU  2.DEQUEUE 3.EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: pthread_create(&t1,NULL,enQueue,NULL);
				pthread_join(t1,&t_res);
				break;
			case 2: pthread_create(&t2,NULL,deQueue,NULL);
				pthread_join(t1,&t_res);
				break;
			case 3:exit(0);
			       break;			  
			default: printf("enter a valid choice \n");
		}
	}
	fclose(fd);
	return 0;
}
