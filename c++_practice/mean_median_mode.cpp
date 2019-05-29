#include <bits/stdc++.h>
#include <vector>
#include<iostream>
 using namespace std;
template<typename T>
 class statistic{
	 static int size;
	 public:
		 float Mean(vector<T> &vect);
		 float median(vector< T> &vect);
		 vector<T> mode(vector<T> &vect);
 };

 template<typename T>
 float statistic<T>:: Mean(vector<T> &vect)
{
	size=vect.size();
	float mean=0;
	int rem=0;
	for(auto it=vect.begin();it!=vect.end();it++)
	{
		try{
			if(sizeof(*it)==1)
				throw *it;
		}
		catch(T x){
			cout <<"Exception caught ,"<<x <<"is not a int or float\n";
			return 0;
		}
			
		mean+=(*it)/size;
		rem+= (int)(*it)%size;
	}

	if(rem>size)
		mean+=rem/size;
	return mean;

}

template<typename T>
float statistic<T>:: median(vector<T> &vect)
{
	int mid;
	float mid_ele;
	vector<T>v1=vect;
	sort(v1.begin(),v1.end());
	mid=size/2;
	if(size%2==0)
		mid_ele=(float)(v1[mid] +v1[mid-1])/2;
	else
		mid_ele=v1[mid];
	return mid_ele;
}

template<typename T>
vector<T> statistic<T>:: mode(vector<T> &vect)
{
	vector<T>v1;
	int max_count=0,max=0,i=0;
	int size=vect.size();
	auto it=vect.begin();
	bool hash[123456]={0};
	while(it!=vect.end())
	{
		max=count(vect.begin(),vect.end(),*it);
		if(max>max_count)
			max_count=max;
		it++;
	}

	it=vect.begin();
	while(it!=vect.end())
	{
		if(hash[(int)*it]==0){
		if(count(vect.begin(),vect.end(),*it)==max_count)
		{
			v1.push_back(*it);
		}
		}
		hash[(int)*it]=1;
		it++;
	}

	return v1;
}

template<typename T>
int statistic<T> :: size=0;
int main()
{
	vector<float> vect;
	statistic<float> obj;
	int n;
	float ele;
	cout<<"enter the size for list : ";
	cin>> n;

	cout<<"\n enter elements for list :";
	
	for(int i=0;i<n;i++){
	cin >>ele;
	vect.push_back(ele);
	}
	cout<<"Mean = "<<obj.Mean(vect);
	cout<<"\nMedian= "<<obj.median(vect);
	cout<<"\nmode= ";
	vector<float>v1=obj.mode(vect);
	for(auto it=v1.begin();it!=v1.end();it++)
		cout<<*it <<" ";
	cout<<endl;


}
