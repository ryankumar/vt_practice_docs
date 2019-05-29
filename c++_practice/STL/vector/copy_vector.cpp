#include<iostream> 
#include<vector> 
using namespace std; 

int main() 
{ 
	// Initializing vector with values 
	vector<int> vect1{1, 2, 3, 4}; 

	// Declaring new vector 
	vector<int> vect2;
       
	//1.copy vector1 to vector3	
	vector<int> vect3(vect1); 
	vector<int> vect4;
	vector<int> vect5; 	

	// 2.A loop to copy elements of 
	// old vector into new vector 
	// by Iterative method 
	for (int i=0; i<vect1.size(); i++) 
		vect2.push_back(vect1[i]); 
	
	// 3.Copying vector by copy function 
	       copy(vect1.begin(), vect1.end(), back_inserter(vect4)); 
	
	//4. copy vect1 to vect5
	 vect5.assign(vect1.begin(), vect1.end()); 

	cout << "Old vector elements are : "; 
	for (int i=0; i<vect1.size(); i++) 
		cout << vect1[i] << " "; 
	cout << endl; 

	cout << "New vector2 elements are : "; 
	for (int i=0; i<vect2.size(); i++) 
		cout << vect2[i] << " "; 
	cout<< endl; 
	
	cout << "New vector3 elements are : "; 
	for (int i=0; i<vect3.size(); i++) 
		cout << vect3[i] << " "; 
	cout<< endl; 
	

	cout << "New vector4 elements are : "; 
	for (int i=0; i<vect4.size(); i++) 
		cout << vect4[i] << " "; 
	cout<< endl; 
	
	cout << "New vector5 elements are : "; 
	for (int i=0; i<vect5.size(); i++) 
		cout << vect5[i] << " "; 
	cout<< endl; 

	// Changing value of vector to show that a new 
	// copy is created. 
	vect1[0] = 2; 
	for (int i=0; i<vect1.size(); i++)
		                cout << vect1[i] << " ";
	cout<<endl;
	cout << "The first element of old vector is :"; 
	cout << vect1[0] << endl; 
	cout << "The first element of new vector is :"; 
	cout << vect2[0] <<endl; 

	return 0; 
} 
