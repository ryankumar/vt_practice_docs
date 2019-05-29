#include <iostream> 
#include <vector> 

using namespace std; 

int main() 
{ 
	vector<int> g1; 

	for (int i = 0; i < 5; i++)
		g1.push_back(i); 

	cout << "Size : " << g1.size(); 
	cout << "\nCapacity : " << g1.capacity(); 
	cout << "\nMax_Size : " << g1.max_size()<<endl; 
	

	// resizes the vector size to 4 but does not remove the elements form vector
	g1.resize(4); 
	for (int i = 0; i < 10; i++)
		cout<<g1[i]<<endl;

	// prints the vector size after resize() 
	cout << "\nafter resize Size is: " << g1.size(); 
	cout << "\nafter resize capacity is : " << g1.capacity(); 
	
	// checks if the vector is empty or not 
	if (g1.empty() == false) 
		cout << "\nVector is not empty"; 
	else
		cout << "\nVector is empty"; 

	// Shrinks the vector 
	g1.shrink_to_fit(); 
	cout << "\nVector elements are: "; 
	for (auto it = g1.begin(); it != g1.end(); it++) 
		cout << *it << " "; 

	cout << "\nafter shrink_fit Size : " << g1.size(); 
	cout << "\nafter shrink fit Capacity : " << g1.capacity()<<endl; 

	return 0; 
} 
