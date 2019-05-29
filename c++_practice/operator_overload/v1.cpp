#include<iostream>
using namespace std;

class integer{
	int i;
	public :
	integer() {}
	integer(int x) : i(x) {}
	const integer& operator+ (const integer& rv)  {  // we can write: integer operator+(integer rv)
		cout << "opeartor +" <<endl;
		integer temp;
		temp.i=i+rv.i;
		return temp;
	}

	integer operator +=(const integer& rv){ // intger opearator +=(intger rv)
		cout<< "operator +=" << endl;
		integer temp;
		i=i+(++rv.i);
		return *this;
	}

	void display()
	{
		cout<<"a="<<i<<endl;
	}
};

int main()
{
	integer a(1) ,b(2) ,c(3);
	a+=b+c;
	a.display();
}
