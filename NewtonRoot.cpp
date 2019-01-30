#include<iostream>
#include<cmath>

using namespace std;

float f(float x)
	{
		return cos(x)-x;
	}
int main(){

	
	
	float x=10/2;
    float e= 1.0e-6;

  while (abs(f(x))>e) {
  	x=x/f(x)/df(x);
  	 
  	cout << x << " " <<f(x)<< endl;
  	
  } 

return 0;
}	
