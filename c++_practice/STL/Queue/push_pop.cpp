#include <iostream> 
#include <queue> 

using namespace std; 

void showq(queue <int> gq) 
{ 
	queue <int> g = gq; 
	while (!g.empty()) 
	{ 
		cout << '\t' << g.front(); 
		g.pop(); 
	} 
	cout << '\n'; 
} 

int main() 
{ 
	queue <int> gquiz; 
	queue <int> qquiz;
	gquiz.push(10); 
	gquiz.push(20); 
	gquiz.push(30); 


	cout << "The queue gquiz is : "; 
	showq(gquiz); 
	
	
	qquiz.push(1); 
	qquiz.push(2); 
	qquiz.push(3); 
	
	cout << "The queue qquiz is : "; 
	showq(qquiz);

	swap(gquiz,qquiz);
	cout<<"After swap "<<endl;

	cout << "The queue gquiz is : "; 
	showq(gquiz);

	cout << "The queue qquiz is : "; 
	showq(qquiz);

	cout << "\ngquiz.size() : " << gquiz.size(); 
	cout << "\ngquiz.front() : " << gquiz.front(); 
	cout << "\ngquiz.back() : " << gquiz.back(); 

	cout << "\ngquiz.pop() : "; 
	gquiz.pop(); 
	showq(gquiz); 

	return 0; 
} 
