#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct VectorizeRow
{
	const size_t size;
	VectorizeRow(size_t s) :size(s) {}
	vector<int> operator()(const int* a) const
	{
		return vector<int>(a,a+size);
	}
};

int main()
{
	int arr[3][4]={{7,4,3,5},{2,5,8},{5,4,3,2}};
	vector<vector<int> > vect;
	transform(arr,arr+3,back_inserter(vect), VectorizeRow(4));
	for (int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<vect[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//sorting in ascending order
	for(int i=0;i<vect.size();i++)
		sort(vect[i].begin(),vect[i].end());
	
	cout<<"After sorting array"
	for (int i=0;i<vect.size();i++)
	{
		for(int j=0;j<vect[i].size();j++)
		{
			cout<<vect[i][j]<<" ";
		}
		cout<<endl;
	}


}
