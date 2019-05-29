#include<iostream>
using namespace std;

class text
{
	const int i=30;
	public:
	text(int x)
	{
		i=const_cast<int>(x);
	}
	void show()
	{
		cout<<i<<endl;
	}
};

int main()
{
	text t(30);
	text s(20);
	t.show();
	s.show();
}
