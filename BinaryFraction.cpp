#include <iostream>
#include <math.h>

//Decimal into Binary fractional, only for 4 digits. if we want to make it longer we will have to
using namespace std;
int main() 
{
 float n,bin,f1=0,f2,f3=0.1;
 int x,x1;
 int fact,rem,temp,i;
 
cout<<"Enter Decimal" ;
cin>>n;	

x1=0;
fact=1;
x=n;
f2=n-x;

while (x!=0)
  {
  	rem=x%2;
  	x1=x1+rem*fact;
  	x=x/2;
  	fact=fact*10;
  }
  for (i=1;i<=3;i++)
  	{
  		f2=f2*2;
  		temp=f2;
  		f1=f1+f3*temp;
  		
  		if (temp==1)
  		f2=f2-temp;
  		f3=f3/10;
	  }
 bin=x1+f1;
 cout<<"Equivalent Binary Value" << bin;
}

