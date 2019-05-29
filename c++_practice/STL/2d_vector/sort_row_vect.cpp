// To sort a particular row of 2D vector in Ascending and descending order.
#include<iostream> 
#include<vector> // for 2D vector 
#include<algorithm>
using namespace std; 

int main() 
{ 
	// Initializing 2D vector "vect" with 
	//     // values 
	vector< vector<int> > vect{{6,4,2}, 
		{2,4,3}, 
		{8,9,7}}; 

	// Displaying the 2D vector 
	for (int i=0; i<vect.size(); i++) 
	{ 
		for (int j=0; j<vect[i].size() ;j++) 
			cout << vect[i][j] << " "; 
		cout << endl; 
	} 

	//sortig 2d vector in Ascending order
	for(int i=0;i<vect.size();i++)
		sort(vect[i].begin(),vect[i].end());
	
	cout<<"after sorting 2d vector in Ascendingh"<<endl;
	for (int i=0; i<vect.size(); i++)
	{
		for (int j=0; j<vect[i].size() ;j++)
			cout << vect[i][j] << " ";
		cout << endl;
	}

	//sortig 2d vector in descending order
	for(int i=0;i<vect.size();i++)
		sort(vect[i].rbegin(),vect[i].rend());
	
	cout<<"after sorting 2d vector in Descendingh"<<endl;
	for (int i=0; i<vect.size(); i++)
	{
		for (int j=0; j<vect[i].size() ;j++)
			cout << vect[i][j] << " ";
		cout << endl;
	}



	return 0; 
} 
