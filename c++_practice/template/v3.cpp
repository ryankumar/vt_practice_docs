/* similar to default function arguments, if one template parameter has a default argument, then all template parameters following it must also have default arguments. For example, the compiler will not allow the following program
 *
 * */
//1. we will get error for this programm.

/*
#include<iostream>
using namespace std;

template<class T=char ,class U, class V> class A
{
T a;
U b;
V c;
};

int main()
{
A obj;
cout<<"size of obj "<<sizeof(obj)<<endl;
}

*/

// 2. here also you will get error 

/*
#include<iostream>
using namespace std;

template<class T=char ,class U, class V> class A
{
T a;
U b;
V c;
};

int main()
{
A <char,int,int>obj;
cout<<"size of obj "<<sizeof(obj)<<endl;
}
*/

//3. here also same error
/*
#include<iostream>
using namespace std;

template<class T ,class U=char, class V> class A
{
T a;
U b;
V c;
};

int main()
{
A<char,char,char> obj;
cout<<"size of obj "<<sizeof(obj)<<endl;
}

*/

//4. but here we will get required output

#include<iostream>
using namespace std;

template<class T ,class U, class V=char> class A
{
	T a;
	U b;
	V c;
};

int main()
{
	A<int,char> obj1;
	A<int,int> obj2;
	A<int,int,int> obj3;
	A<int,char,int> obj4;
	
	cout<<"size of obj1 "<<sizeof(obj1)<<endl;
	cout<<"size of obj2 "<<sizeof(obj2)<<endl;
	cout<<"size of obj3 "<<sizeof(obj3)<<endl;
	cout<<"size of obj4 "<<sizeof(obj4)<<endl;
}

