#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	deque<int> dq = { 1, 2, 3, 4, 5 }; 

	deque<int>::iterator it = dq.begin(); 
	++it; 

	vector<int> v(2, 10); 

	// 1 10 10 2 3 4 5 
	dq.insert(it, v.begin(), v.end()); 

	std::cout << "Deque contains:"; 
	for (it = dq.begin(); it != dq.end(); ++it) 
		cout << ' ' << *it; 
	cout << '\n'; 

	return 0; 
} 
