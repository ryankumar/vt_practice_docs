#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int size;
	vector<int> v1;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"max_sizeof v1: "<<v1.max_size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
	cout<<"enter size of vector do you want to insert :";
	cin>>size;
	cout<<endl;
	for(int i=0;i<size;i++){
	v1.push_back(10*(i+1));
	cout<<i+1<<"value in vector: "<<v1[i]<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"max_sizeof v1: "<<v1.max_size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	}

}
