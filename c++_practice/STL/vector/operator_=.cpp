#include <iostream> 
#include <vector> 
using namespace std; 

int main() 
{ 
	vector<int> myvector1{ 1, 2, 3 }; 
	vector<int> myvector2{ 3, 2, 1, 4 }; 
	myvector1 = myvector2; 
	cout << "myvector1 = "; 
	for (auto it = myvector1.begin(); it != myvector1.end(); ++it) 
		cout << ' ' << *it; 
	return 0; 
} 
