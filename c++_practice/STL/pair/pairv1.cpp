// format : pair (data_type1, data_type2) Pair_name;
#include<iostream>
using namespace std;
int main()
{
	pair<int,char> p1;
	pair<int,string> p2;
	p1.first=10;
	p1.second='M';
	p2.first=11;
	p2.second="madhab";

	cout<<"p1: ";
	cout<<p1.first<<" "<<p1.second<<endl;
	cout<<"p2: ";
	cout<<p2.first<<" "<<p2.second<<endl;

}

