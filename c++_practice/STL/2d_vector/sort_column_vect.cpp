// To sort the entire 2D vector on basis of a particular column.
#include<iostream> 
#include<vector> // for 2D vector 
#include<algorithm>
using namespace std; 


// Driver function to sort the 2D vector 
// on basis of a particular column 
bool sortcol_ascending( const vector<int>& v1, 
		const vector<int>& v2 ) { 
	return v1[1] < v2[1]; 
} 

bool sortcol_descending( const vector<int>& v1, 
		const vector<int>& v2 ) { 
	return v1[0] > v2[0]; 
} 
int main() 
{ 
	// Initializing 2D vector "vect" with values 
	vector< vector<int> > vect{{6,6,2}, 
				   {2,4,3}, 
				   {8,5,7}}; 

	// Displaying the 2D vector 
	for (int i=0; i<vect.size(); i++) 
	{ 
		for (int j=0; j<vect[i].size() ;j++) 
			cout << vect[i][j] << " "; 
		cout << endl; 
	} 

	//sortig 2d vector according to 2nd column in ascending order
	sort(vect.begin(),vect.end(),sortcol_ascending);

	cout<<"after sorting 2d array in ascending order"<<endl;
	for (int i=0; i<vect.size(); i++)
	{
		for (int j=0; j<vect[i].size() ;j++)
			cout << vect[i][j] << " ";
		cout << endl;
	}

	//sortig 2d vector according to 1st column in Descending order
	sort(vect.begin(),vect.end(),sortcol_descending);

	cout<<"after sorting 2d array in descending order"<<endl;
	for (int i=0; i<vect.size(); i++)
	{
		for (int j=0; j<vect[i].size() ;j++)
			cout << vect[i][j] << " ";
		cout << endl;
	}


	return 0; 
} 
