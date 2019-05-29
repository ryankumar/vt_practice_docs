#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1, v2; 
	v1.push_back(1); 
	v1.push_back(2); 
	v1.push_back(5);
	cout<<"v1.capacity(): "<<v1.capacity()<<endl;
	v2.push_back(3); 
	v2.push_back(4); 
	cout<<"v2.capacity(): "<<v2.capacity()<<endl;

	cout << "\n\nVector 1: "; 
	for (int i = 0; i < v1.size(); i++) 
		cout << v1[i] << " "; 

	cout << "\nVector 2: "; 
	for (int i = 0; i < v2.size(); i++) 
		cout << v2[i] << " "; 

	// Swaps v1 and v2 
	v1.swap(v2); // or we can write : swap(v1,v2); 

	cout << "\nAfter Swap \nVector 1: "; 
	for (int i = 0; i < v1.size(); i++) 
		cout << v1[i] << " "; 

	cout << "\nVector 2: "; 
	for (int i = 0; i < v2.size(); i++) 
		cout << v2[i] << " ";

	// Swaps v1 and v2 
	swap(v1,v2); // or we can write : swap(v1,v2); 

	cout << "\nAfter Swap \nVector 1: "; 
	for (int i = 0; i < v1.size(); i++) 
		cout << v1[i] << " "; 

	cout << "\nVector 2: "; 
	for (int i = 0; i < v2.size(); i++) 
		cout << v2[i] << " ";
} 
