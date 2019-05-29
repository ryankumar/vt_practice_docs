#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

struct point_result
{
	int count;
	vector< vector<float> > vect;
};


class point
{
	private:
		float x,y;
	public:
		point() {};
		void set(float a,float b);
		
		static point* ref_point(point p[],float a,float b,int size)
		{
			point *ret=NULL;
			int i=0;
			for(i=0;i<size;i++){
				if(p[i].x==a && p[i].y==b)
				{
					ret=&p[i];
					return ret; 
				}
			}
			return NULL;
		}

		int operator==(const point p1);
		void display();
		point_result count(float k,point p[],int size);
};


// Set value for each point
void point:: set(float a,float b)
{
	x=a;
	y=b;

}

// Operator overload
int point:: operator==(const point p1)
{
	if((x==p1.x) && (y==p1.y))
		return 1;
	return 0;
}


// Count points with in range
struct point_result point:: count(float k,point p[],int size)
{
	int dist;
	int count=0;
	struct point_result data;
	for(int i=0;i<size;i++)
	{
		if(*this==p[i])
			continue;
		else
		{
			dist=sqrt( ( (x-p[i].x) * (x-p[i].x) ) + ( (y-p[i].y) * (y-p[i].y) ) );
			if(dist==k)
			{
				count++;
				data.vect.push_back({p[i].x ,p[i].y});
			}
		}

	}
	if(count==0)
		cout<<"No points with in "<<k<<" range"<<endl;
	data.count=count;
	return data;

}

// MAIN() function
int main()
{
	point p[10];
	point *ret;
	int k,total=0;
	float a,b;
	float x,y;
	point_result data;

	for(int i=0;i<10;i++)
	{
		cout<<"enter "<<i+1<<"st points with x and y value"<<endl;
		cin>>a;
		cin>>b;
		p[i].set(a,b);
	}

	cout<< "choose one ref point with cordinate x and y value : ";
	cin >>x;
	cin >>y;

	ret=point::ref_point(p,x,y,10);
	if(ret==NULL){
		cout<<"\ngiven point is not matching"<<endl;
		return 0;
	}	


	cout<<"enter k for radius :";
	cin>>k;
	data=ret->count(k,p,10);
	cout<<"total number of points within range is :";
	cout<<data.count<<endl;
	cout<<"points are :";
	for(auto p : data.vect)
		cout<<p[0]<<" , "<<p[1]<<endl;

}
