
// C++ program for implementation of Newton Raphson Method for 
// solving equations 
#include<bits/stdc++.h> 
#define EPSILON 0.001 
using namespace std; 
  
// An example function whose solution is determined using 
// Bisection Method. The function is written here
double func(double x) 
{ 
    return x*x*x - x*x + 2;         // Our function
} 
  
// Derivative of the above function which is 3*x^x - 2*x 
double derivFunc(double x) 
{ 
    return 3*x*x - 2*x; // Here we write the derivative
} 
  
// Function to find the root 
void newtonRaphson(double x) 
{ 
    double h = func(x) / derivFunc(x); 
    while (abs(h) >= EPSILON) 
    { 
        h = func(x)/derivFunc(x); 
   
        // x(i+1) = x(i) - f(x) / f'(x)   
        x = x - h; 
    } 
  
    cout << "The value of the root is : " << x; 
} 
  
// Driver program to test above 
int main() 
{ 
    double x0 = -10; // Initial values assumed 
    newtonRaphson(x0); 
    return 0; 
} 
