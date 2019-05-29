#include <iostream>
using namespace std;

class  CPolygon { 
	protected: 
	  int width, height; 
	public: 
	  void set_values (int a,  int b) 
		         { width=a; height=b;} 
}; 

class CRectangle: public CPolygon { 
	public : 
		int x;
		int area () { 	return (width * height); } 
}; 

class CTriangle:  public CPolygon { 
	public : 
		int y;
		int  area () {  return  (width * height / 2); } 
}; 
int main () { 
	 CRectangle rect; 
	 CTriangle trgl;
	 CPolygon pol;
	 cout<<"size of base :  "<<sizeof(pol)<<endl;
	 cout<<"size of derived rectangle :  "<<sizeof(rect)<<endl;
	 cout<<"size of derived rectangle :  "<<sizeof(trgl)<<endl;
	 rect.set_values (4,5); 
	 trgl.set_values (4,5); 
	 cout << rect.area() << endl; 
	 cout << trgl.area() << endl; 
	 return 0; 
 } 
