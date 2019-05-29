// when compiling vector use macro during compilation time . ex: g++ filename -std=c++11 
/*
#include <iostream> 
#include <vector> 
using namespace std; 

int main() 
{ 
	vector<int> myvector{ 1, 2, 3, 4, 5 }; 

	myvector.push_back(6); 

	// Vector becomes 1, 2, 3, 4, 5, 6 

	for (auto x : myvector) 
		cout << x << " "; 
} 
*/

// in another way also we can initialise vectore
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
	    int arr[] = { 10, 20, 30 }; 
	        int n = sizeof(arr) / sizeof(arr[0]); 
		  
		    vector<int> vect(arr, arr + n); 
			vect.push_back(40);		      
		        for (int x : vect) 
				        cout << x << " "; 
			  
			    return 0; 
} 
