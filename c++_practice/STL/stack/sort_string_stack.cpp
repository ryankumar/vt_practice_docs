#include<iostream>
#include<stack>
#include<string.h>

using namespace std;
void insert_stack(stack<char>&buff,stack<char> &temp);

stack<char> sort(char *str,int len)
{
	stack<char> buff;
	stack<char> temp;
	int i=0;
	while(str[i])
	{

		while(!buff.empty() && buff.top() < str[i])
		{
			temp.push(buff.top());
			buff.pop();
		}

		buff.push(str[i]);
		insert_stack(buff,temp);
		i++;
	}
	return buff;

}

void insert_stack(stack<char>&buff,stack<char> &temp)
{
	while(!temp.empty())
	{
		buff.push(temp.top());
		temp.pop();
	}
}


int main()
{
	char str[]="geeksforgeeks";
	int l=strlen(str);
	stack<char> store=sort(str,l);
	while(!store.empty())
	{
		cout<<store.top();
		store.pop();
	}
	cout<<endl;
}
