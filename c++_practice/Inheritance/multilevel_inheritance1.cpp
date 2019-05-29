#include <iostream>
using namespace std;

class Mammal {
	public:
		Mammal()
		{
			cout << "Mammals can give direct birth." << endl;
		}
};

class WingedAnimal:public Mammal {
		public:
			WingedAnimal()
			{
				cout << "Winged animal can flap." << endl;
			}
};

class Bat: public WingedAnimal {
	public:
		Bat()
		{
			cout << "bat is derived from Mammal and Wingedanimal"<<endl;
		}

};

int main()
{
	Bat b1;
	WingedAnimal w;
	return 0;
}
