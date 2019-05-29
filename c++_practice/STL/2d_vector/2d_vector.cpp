#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int r=5,c=3;
	vector<int> col(c,0);
	vector<vector<int>> vec(r,col);   //vector of vector for matrix
//	vector<int>vec;
//	vec.push_back({ 10,20,30 }); //first row 
//	vec.push_back({ 11,22,33 });  // second row
	cout<<"enter element for 5 * 5 elements :";
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin >> vec[i][j] ;
		}
	}


	for (auto x : vec)                  //printing matrix
	{ std::cout << x[0] << " " << x[1] << " "<<x[2]<< " "<<std::endl; }

	return 0;
}


