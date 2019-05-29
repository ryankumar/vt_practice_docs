#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<string>v1{"madhab","kamles" ,"Arun"};
	for(int i=0;i<v1.size();i++)
	cout<<i+1<<"value in vector: "<<v1[i]<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"max_size v1: "<<v1.max_size()<<endl<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	

	v1.push_back("akbar");
	for(int i=0;i<v1.size();i++)
	cout<<"after push value in vector: "<<v1[i]<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
	v1.push_back("tarani");
	for(auto i=v1.begin();i!=v1.end();i++)
	cout<<"after push value in vector: "<<*i<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
	v1.pop_back( );
	for(auto i=v1.begin();i!=v1.end();i++)
	cout<<"after pop value in vector: "<<*i<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
	v1.pop_back( );
	for(auto i=v1.begin();i!=v1.end();i++)
	cout<<"after pop value in vector: "<<*i<<endl;
	cout<<"sizeof v1: "<<v1.size()<<endl;
	cout<<"capacity v1: "<<v1.capacity()<<endl<<endl;
	
}
