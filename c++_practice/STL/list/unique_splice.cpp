// unique() : will remove the occurance of element from list ,hence the list have to be in sorted order
// splice() : transfer element from one list to other list

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

	list<int>::iterator it=list1.begin();
	
	// advance will advance the iterator to 3rd position
	advance(it,3);
	
	 // using splice() to splice list2 in list1 at position it 
	 // inserts list2 after 2nd position 
	list1.splice(it,list2);
	cout<<"After transfer element from list1 to list2 :";
	for(int &x:list1)
		cout<<"\t"<<x;
	cout<<endl;
	
	for(int &x:list2)
		cout<<"\t"<<x;
	cout<<endl;


}
