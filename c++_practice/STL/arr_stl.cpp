#include<iostream>
#include<array>
using namespace std;
int main()
{
	int size1=8;
	int size2=8;

	array<int,8> arr_name1={10,20,30,40,50};
	array<int,8> arr_name2={1,2,3,4,5};
	cout<<"value at(3): "<<arr_name1.at(3)<<endl; // at() is a member of array class tamplate
	cout << "arr[3]: "<<arr_name1[3]<<endl; // operator[] is also an member of array class tamplate
	cout << "value at front: "<<arr_name1.front()<<endl;// front() will give the 1st index value i.e 10;
       	cout <<"value at back: " <<arr_name1.back()<<endl;	//back()  will give the last index value i.e 0;
	
	// fill value in array
	arr_name1.fill(10);		// fill() will fill 10 in all index 
	for(int i=0;i<8;i++)
		cout<<arr_name1[i]<<endl;

	//swap two array
	arr_name1.swap(arr_name2);
	cout<<"arr1: ";
	for(int i=0;i<8;i++)
		cout<<arr_name1[i]<<" ";
	cout<<endl;
	cout<<"arr2: ";
	for(int i=0;i<8;i++)
		cout<<arr_name2[i]<<" ";
	cout<<endl;

	// size() function
	cout<<"size of arr1: "<<arr_name1.size()<<endl;
	cout<<"size of arr2: "<<arr_name2.size()<<endl;
	
	
}

