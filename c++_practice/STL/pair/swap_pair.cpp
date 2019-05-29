// format : swap() will swap value with p1.1st with p2.1st and p1.2nd with p2.2nd. both pair should have same type.
//
#include<iostream>
using namespace std;
int main()
{
	pair<int,string> p1=make_pair(10,"ROJEE");
	pair<int,string> p2=make_pair(11,"Madhav");
	cout<<"before swap: "<<endl;
	cout<<"p1: ";
	cout<<p1.first<<" "<<p1.second<<endl;
	cout<<"p2: ";
	cout<<p2.first<<" "<<p2.second<<endl;
	
	p1.swap(p2);
	cout<<"\nthis is one way :after swap: "<<endl;
	cout<<"p1: ";
	cout<<p1.first<<" "<<p1.second<<endl;
	cout<<"p2: ";
	cout<<p2.first<<" "<<p2.second<<endl;
	
	swap(p1,p2);
	cout<<"\nthis is another way :after swap: "<<endl;
	cout<<"p1: ";
	cout<<p1.first<<" "<<p1.second<<endl;
	cout<<"p2: ";
	cout<<p2.first<<" "<<p2.second<<endl;


}

