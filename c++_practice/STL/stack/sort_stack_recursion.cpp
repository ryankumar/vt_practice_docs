#include<iostream>
#include<stack>
using namespace std;

void insert_sort(stack<int>& ,int ele);
void sort(stack<int> &buff)
{
	int temp;
	if(!buff.empty())
	{
		temp=buff.top();
		buff.pop();
		sort(buff);
		insert_sort(buff,temp);
	}

}

void insert_sort(stack<int> &s,int ele)
{
	int var;
	if(s.empty() || ele > s.top())
		s.push(ele);
	else
	{
		var=s.top();
		s.pop();
		insert_sort(s,ele);
		s.push(var);
	}
}

void show_stack(stack<int>temp)
{
	while(!temp.empty())
	{
	 	cout<<temp.top() <<" ";
		temp.pop();
	}
	cout<<endl;
}

int main()
{
	stack<int> input;
	input.push(30);
	input.push(5);
	input.push(20);
	input.push(40);
	input.push(35);
	input.push(98);
	input.push(2);
	show_stack(input);
	sort(input);
	
	while(!input.empty())
	{
		cout<<input.top() << " ";
		input.pop();
	}
	cout<<endl;
}
