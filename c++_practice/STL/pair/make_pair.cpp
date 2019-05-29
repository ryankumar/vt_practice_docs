//format : by using make_pair();
#include<iostream>
#include<utility>
#include<string>
using namespace std;

class student
{
	string name;
	int i;
	public:
	void set()
	{
		name="madhav";
		i=16;
	}

	void show()
	{
		cout<<"\nname of student: "<<name;
		cout<<"\nage of student : "<<i;
	}

};

int main()
{
	student s1,s2;
	s1.set();
	pair <string,int> p1;
	pair <string,string> p2;
	pair <string,float> p3;
	pair <int,student> p4;
	
	p1=make_pair("rojee",11);
	p2=make_pair("madhab","mahanty");
	p3=make_pair("over",15.6);
	p4=make_pair(1,s1);
	
	cout<<"\np1: ";
	cout<<p1.first <<" "<<p1.second ;
	cout<<"\np2: ";
	cout<<p2.first <<" "<<p2.second ;
	cout<<"\np3: ";
	cout<<p3.first <<" "<<p3.second ;

	cout<<"\np4: ";
	cout<<p4.first <<" ";
	s2=p4.second;
	s2.show();
	return 0;

}



