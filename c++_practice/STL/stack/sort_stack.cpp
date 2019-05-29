#include<iostream>
#include<stack>
using namespace std;

stack<int> sort(stack<int> &buff)
{
	stack<int>tmp_stack;
	int top;
	while(!buff.empty())
	{
		top=buff.top();
		buff.pop();

		while(!tmp_stack.empty() && tmp_stack.top() > top)
		{
			buff.push(tmp_stack.top());
			tmp_stack.pop();
		}

		tmp_stack.push(top);
	}
	return tmp_stack;

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
	stack<int>tmp=sort(input);
	
	while(!tmp.empty())
	{
		cout<<tmp.top() << " ";
		tmp.pop();
	}
	cout<<endl;
}
