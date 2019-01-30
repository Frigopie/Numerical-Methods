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
  	x=a-f(a)*(b-a)/(f(b)-f(a));
  	cout << x << " " <<f(x)<< endl;
  	b=x;
  } 

return 0;
}	
