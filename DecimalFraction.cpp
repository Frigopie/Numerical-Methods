#include <iostream>
//Decimal into Binary fractional
using namespace std;
int main() {
	

int arr[100], i=0,j;
int n;
cout<< "Enter a Decimal Positive";
cin>>n;
while (n>0)
{
	arr[i]=n%2;
	i++;
	n=n/2;
}
cout<< "In binary:";
for (j=i-1,j>=0;j--;)
{
	cout<<arr[j];
}
return 0;
}
