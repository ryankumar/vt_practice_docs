#include<iostream>
using namespace std;
template <class A>

class MATH
{
	A i;
	public:
	A avg()
	{
		i=(10+20+30)/4.5;
		return i;
	}
};

int main()
{
	MATH<float> obj;
	cout<<obj.avg()<<endl;
}
