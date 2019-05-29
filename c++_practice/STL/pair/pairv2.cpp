// format :pair (data_type1, data_type2) Pair_name (value1, value2) ;
#include<iostream>
using namespace std;
int main()
{
	pair<int,char> p1(10,'M');
	pair<int,string> p2(11,"Madhav");

	cout<<"p1: ";
	cout<<p1.first<<" "<<p1.second<<endl;
	cout<<"p2: ";
	cout<<p2.first<<" "<<p2.second<<endl;

}

