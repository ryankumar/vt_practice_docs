// it compares with p1.st to p2.1st and p1.2nd to p2.2nd
//
#include<iostream>
#include<utility>
using namespace std;

int main()
{
	pair<int,int>p1=make_pair(8,9);
	pair<int,int>p2=make_pair(7,10);
	cout<<"is equal: "<< (p1==p2) <<endl;
	cout<<"is not equal: "<< (p1!=p2) <<endl;
	cout<<"is greater or equal: "<< (p1>=p2) <<endl;
	cout<<"is lessser or equal: "<< (p1<=p2) <<endl;
	cout<<"is greater: "<< (p1 > p2) <<endl;
	cout<<"is smalles: "<< (p1 < p2) <<endl;
}
