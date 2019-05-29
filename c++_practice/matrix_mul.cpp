#include<iostream>
#include<vector>
using namespace std;

class matrix{
	int row,col;
	vector< vector<int> >v2d;

	public:
	matrix(int r=0,int c=0) 
	{
		row=r; col=c;
		v2d.resize(r,vector<int>(c,0));
	}
	void set();
	void print();
	int **mul(matrix &obj2);
};

void matrix:: set(){
	int n;
	cout<<"\nenter elements for matrix elements :";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin >> n ;

			v2d[i][j]=n;
		}

	}

}

void  matrix:: print()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<< v2d[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}


int** matrix:: mul(matrix &obj)
{
	if(col!=obj.row)
	{
		cout<<"cul of 1st mat and row of 2nd mat should be equal";
		return 0;
	}
	int c=obj.col;
	int r=row;
	int **arr=0;
	arr=new int*[r];
	for(int i=0;i<r;i++)
		arr[i]=new int[c];

	for(int i = 0; i < row; ++i)
		for(int j = 0; j < obj.col; ++j)
			for(int k = 0; k <col; ++k)
			{
				arr[i][j] += v2d[i][k] * obj.v2d[k][j];
			}
	return arr;

}

int main()
{
	int r1,c1;
	int r2,c2;
	cout<<"enter the size for matrix1 row,col ";
	cin>> r1>>c1;
	matrix mat1(r1,c1);
	mat1.set();

	cout<<"enter the size for matrix2 row,col ";
	cin>> r2>>c2;
	matrix mat2(r2,c2);
	mat2.set();	

//	int arr[r1][c2];
	cout<<"\nprint matrix1 : "<<endl;
	mat1.print();

	cout<<"print materix2 : "<<endl;
	mat2.print();

	cout<<"matrix multiplication : "<<endl;
	int **arr=mat1.mul(mat2);

	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			cout<<arr[i][j] <<" " ;
		}
		cout<<endl;
	}
	cout<<endl;


	return 0;
}


