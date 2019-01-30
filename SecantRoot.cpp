#include<iostream>
#include<cmath>

using namespace std;

float f(float x)
	{
		return cos(x)-x;
	}
int main(){

	float a=0.5;
	float b=1;
	float x=(a+b)/2;
    float e= 1.0e-6;

  while (abs(f(x))>e) {
  	if (f(a)*f(x)<0)
  	         b=x;
  	    else 
		  a=x;
		  x=(a+b)/2;     
  	 
  	cout << x << " " <<f(x)<< endl;
  	
  } 

return 0;
}	
