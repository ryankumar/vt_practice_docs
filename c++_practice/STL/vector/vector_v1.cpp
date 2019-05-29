#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int num;
	vector<int> v1;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"max_sizeof v1: "<<v1.max_size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
	// user input to vector
	cin>>num;
	v1.push_back(num);

	v1.push_back(10);
	cout<<"1st value in vector: "<<v1[0]<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"max_sizeof v1: "<<v1.max_size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
	v1.push_back(20);
	cout<<"2nd value in vector: "<<v1[1]<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"max_sizeof v1: "<<v1.max_size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
	v1.push_back(30);
	cout<<"3rd value in vector: "<<v1[2]<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"max_sizeof v1: "<<v1.max_size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
	v1.push_back(40);
	cout<<"4th value in vector: "<<v1[3]<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"max_sizeof v1: "<<v1.max_size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
	v1.push_back(50);
	cout<<"5th value in vector: "<<v1[4]<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"max_sizeof v1: "<<v1.max_size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
	v1.push_back(60);
	cout<<"6th value in vector: "<<v1[5]<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"max_sizeof v1: "<<v1.max_size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;

}
