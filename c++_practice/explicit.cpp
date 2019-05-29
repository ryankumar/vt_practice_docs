#include<iostream>
#include<string>
using namespace std;

// without explicit keyword
/*
   class A
   {
   int i;
   public:
   A(int x) :i(x){}
   void show()
   {
   cout<<i;
   }

   };

   int main()
   {
   A a(5);
   a.show();
// or we can write
//	A(5).show();

//or we can write
//A a=5;
//a.show();



}
*/

// with explicit keyword
class A
{
	int i;
	public:
	explicit A(int x) :i(x){}
	void show()
	{
		cout<<i;
	}

};

int main()
{
	A a=(A)5;
	a.show();
}

