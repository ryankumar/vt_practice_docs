
#include<iostream>
using namespace std;
int main()
{
	pair<int,char> p1(10,'M');
	pair<int,char> p2(p1);
	pair<int,char> p3=p1;
	cout<<"p1: ";
	cout<<p1.first<<" "<<p1.second<<endl;
	cout<<"p2: ";
	cout<<p2.first<<" "<<p2.second<<endl;
	cout<<"p3: ";
	cout<<p3.first<<" "<<p3.second<<endl;

}

