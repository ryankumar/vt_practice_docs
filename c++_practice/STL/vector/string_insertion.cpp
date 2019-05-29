// cbegin() and end() is called if we traverse from start to end
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int main() 
{ 
	vector<string> vec; 

	// 5 string are inserted 
	vec.push_back("first"); 
	vec.push_back("second"); 
	vec.push_back("third"); 
	vec.push_back("fourth"); 
	vec.push_back("fifth"); 

	// displaying the contents 
	cout << "Contents of the vector:" << endl; 
	for (auto itr = vec.cbegin(); itr != vec.end(); ++itr) 
		cout << *itr << endl; 

	for(auto itr= vec.cend();itr >= vec.begin();--itr)
		cout << *itr<< endl;
	return 0; 
} 
