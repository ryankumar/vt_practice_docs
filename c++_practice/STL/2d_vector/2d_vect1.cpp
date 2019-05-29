#include<iostream> 
#include<vector> // for 2D vector 
using namespace std; 

int main() 
{ 
	// Initializing 2D vector "vect" with 
	//     // values 
	vector< vector<int> > vect{{1, 2, 3,5}, 
					{4, 5, 6,8}, 
						{7, 8, 9,2}};

	//size of 2d vect
	cout<<"no. of rows : "<<vect.size();
	cout<<endl;	
	cout<<"no.of columns: "<<vect[0].size();

	// Displaying the 2D vector 
	for (int i=0; i<vect.size(); i++) 
	{ 
		for (int j=0; j<vect[i].size() ;j++) 
			cout << vect[i][j] << " "; 
		cout << endl; 
	} 

	return 0; 
} 
