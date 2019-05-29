#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 6
int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;
int peek() {
	   return intArray[front];
}

bool isEmpty() {
	   return itemCount == 0;
}

bool isFull() {
	   return itemCount == MAX;
}

int size() {
	   return itemCount;
}  
void insert(int data) {

	if(!isFull()) {

		if(rear == MAX-1) {
			rear = -1;            
		}       

		intArray[++rear] = data;
		itemCount++;
	}
}

int removeData() {
	   int data = intArray[front++];
	   	
	      if(front == MAX) {
		            front = 0;
			       }
	      	
	         itemCount--;
		    return data;  
}

void print()
{
	int end=front;
	while(end!=MAX)
	{
		printf("%d  ",intArray[end]);
		end++;
	}
}

void swap(int a,int b)
{
	int end=front;
	int t1=a,t2=b;
	int count1=0,count2=0;
	while(end!=MAX)
	{
		if(intArray[end]==a){
			if(count1==0){
			intArray[end]=b;
			count1++;
			}
		}
		else if(intArray[end]==b)
			if(count2==0)
			{
				intArray[end]=a;
				count2++;
			}
		end++;
	}
}
		
int main()
{
	int end=front;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	print();
	swap(2,5);
	print();


}

