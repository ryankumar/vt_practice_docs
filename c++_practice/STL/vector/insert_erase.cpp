#include <bits/stdc++.h> 
#include <vector> 
 
using namespace std; 

int main() 
{ 
	// Assign vector 
	vector<int> v; 

	// fill the array with 10 five times 
	v.assign(5, 10); // we can write : vector<int>v(5,10);

	cout << "The vector elements are: "; 
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << " ";

	
	// inserts 15 to the last position 
	v.push_back(15); 
	int n = v.size(); 
	cout << "\nThe last element is: " << v[n - 1]; 
	
	// removes last element 
	v.pop_back(); 

	// prints the vector 
	cout << "\nAfter pop_back() the vector elements are: "; 
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << " "; 


	// inserts 5 at the beginning 
	v.insert(v.begin(), 5);  // we can insert multiple element at a time like: v.insert(v.begin(),{5,6,7})
	cout << "\nThe first element is: " << v[0];

	//insert element at given position
	v.insert(v.begin()+3,7);
 	cout << "\nafter inserting  element at 3rd index are: ";
        for (int i = 0; i < v.size(); i++)
	     cout << v[i] << " ";


	// removes the first element 
	v.erase(v.begin()); // we can delete elements upto some range like: v.erase(v.begin(),v.begin()+3)
	cout << "\n after delete  first element: "<<endl ;
	for (int i = 0; i < v.size(); i++)
		             cout << v[i] << " ";
	
	// removes the specified position element 
	v.erase(v.begin()+2); 
	cout << "\n after delete  2nd index element: "<<endl ;
	for (int i = 0; i < v.size(); i++)
		             cout << v[i] << " ";


	// inserts at the beginning 
	v.emplace(v.begin(), 5); 
	cout << "\nThe first element is: " << v.front();//v[0]; 

	// Inserts 20 at the end 
	v.emplace_back(20); 
	n = v.size(); 
	cout << "\nThe last element is: " << v.back(); //v[n - 1]; 

	// erases the vector 
	v.clear(); 
	cout << "\nVector size after clear(): " << v.size();
	
}	
