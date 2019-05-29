#include<iostream>
#include<list>
using namespace std;
int main()
{
        list<int> list1{1,1,2,2,3,3,4,5};
        list<int> list2{6,7,8};

        //remove the multiple occurance from list
        list1.unique();
        cout<<"After remove occurance from list :";
        for(int &i:list1)
        cout<<"\t"<<i;
        cout<<endl;

	//swap element from list1 to list2
	list1.swap(list2);

	cout<<"after swaping list1 :";
	for(int &x:list1)
		cout<<x<<" ";
	cout<<endl;

	cout<<"after swaping list2 :";
	for(int &x:list2)
		cout<<x<<" ";
        cout<<endl;	

}
