
#include <iostream> 
using namespace std; 
  
class Point 
{ 
	    int x, y; 
	public:
	   Point( ){}
	   Point(int a,int b) {x=a;y=b;} 
//      Point(const Point &p) { x = p.x; y = p.y; } 
	       void show()
	       {
		       cout<<"x= "<<x<<"y= "<<y<<endl;
	       }


	       void set()
	       {
		       x=10;
		       y=20;
	       }
}; 
  
int main() 
{ 
	    Point p1(3,4);  // COMPILER ERROR 
	        Point p2 = p1;
	       p2.show();

	      

	       Point p4(5,6);
	       Point p3;
	       p3=p4;
	       p3.show();

	       Point *p5=new Point();
	       Point *p6=p5;
	       p6->show();
	       delete[] p5;

		    return 0; 
}

