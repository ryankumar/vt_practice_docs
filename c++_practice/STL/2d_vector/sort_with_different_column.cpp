//Sorting the 2D Vector on basis of no. of columns in row in ascending order as well as descending order.
#include<iostream> 
#include<vector> // for 2D vector 
#include<algorithm> // for sort() 
using namespace std; 
  
// Driver function to sort the 2D vector 
// on basis of a no. of columns in  
// ascending order 
bool sizecom(const vector<int>& v1, const vector<int>& v2) 
{ 
    return v1.size() < v2.size();  //for ascending order
    // return v1.size() > v2.size(); //descending order
} 
  
int main() 
{ 
    // Initializing 2D vector "vect" with 
    // values 
    vector< vector<int> > vect{{2,1}, 
                               {5,3,4}, 
                               {6}}; 
  
    // Displaying the 2D vector before sorting 
    cout << "The Matrix before sorting is:\n"; 
    for (int i=0; i<vect.size(); i++) 
    { 
        for (int j=0; j<vect[i].size() ;j++) 
            cout << vect[i][j] << " "; 
        cout << endl; 
    } 
  
    //Use of "sort()" for sorting on 
    //basis of no. of columns in 
    //ascending order. 
    sort(vect.begin(), vect.end(), sizecom); 
  
    // Displaying the 2D vector after sorting 
    cout << "The Matrix after sorting is:\n"; 
    for (int i=0; i<vect.size(); i++) 
    { 
        for (int j=0; j<vect[i].size() ;j++) 
            cout << vect[i][j] << " "; 
        cout << endl; 
    } 
  
    return 0; 
  
} 
