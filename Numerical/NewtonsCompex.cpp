#include <iostream>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cassert>

using namespace std;

int signum(std::complex<double> z)
{
    if (z.real() < 0 || z.imag() < 0) return -1;
    else if (z.real() >= 0 || z.imag() >= 0) return 1;
}

// POST: The function is intended to solve a cubic equation with       coefficients a, b, c and d., such that
//      ax^3 + bx^2 + cx + d = 0. If there exist infinitely many solutions, we output -1, i.e. if a=b=c=d=0
//      (trivial solution).

void solve(std::complex<double> a, std::complex<double> b,   std::complex<double> c, std::complex<double> d, std::complex<double>& x1, std::complex<double>& x2, std::complex<double>& x3)
{
    complex<double> i = complex<double> (0, 1.0);
    // Consider implementing Cardano's method for obtaining the solution of a degree 3 polynomial, as suggested
   // We must hence define the discriminant D of such an equation through complex doubles Q and R
    std::complex<double> Q;
    Q = (3.0*a*c - pow(b, 2)) / (9.0*pow(a, 2));
    cout << "Q=" << Q << endl;

    std::complex<double> R;
    R = (9.0*a*b*c - 27.0*d*pow(a, 2) - 2.0*pow(b, 3)) / (54.0*pow(a, 3));
    cout << "R=" << R << endl;

    std::complex<double> D;
    D = pow(Q, 3) + pow(R, 2);

    // Possible types of output for discriminant
    if (abs(D) < 0.0)
    {
        cout << "The cubic has three distinct, real roots." << endl;
    }

    else if (abs(D) == 0.0)
    {
        cout << "The cubic has three real roots, at least two of which are equal." << endl;
    }

    else if (abs(D) > 0.0)
    {
        cout << "The cubic has one real root and two complex conjugate roots." << endl;
    }

    // Defining two further complex double variables S and T, which are required to obtain the final solution for x1, x2 and x3
    std::complex<double> S;
    std::complex<double> SPrime;
    SPrime = R+sqrt(Q*Q*Q + R*R);
    cout << "SPrime=" << SPrime << endl;

    if (signum(SPrime) == -1)
    {
        S = (-1)*pow(abs(SPrime), 0.3333333333333);        
    }

    else if (signum(SPrime) == 1)
    {
        S = pow(abs(SPrime), 0.3333333333333);
    }

    cout << "S=" << S << endl;

    std::complex<double> T;
    std::complex<double> TPrime;
    TPrime = (R-sqrt(Q*Q*Q + R*R));

    if (signum(TPrime) == -1)
    {
        T = (-1)*pow(abs(TPrime), 0.3333333333333);        
    }

    else if (signum(TPrime) == 1)
    {
        T = pow(abs(TPrime), 0.3333333333333);
    }

    cout << "T=" << T << endl;
    cout << "TPrime= " << TPrime << endl;

    // Expressions for the solutions
    x1 = S + T - (b/(3.0*a));
    x2 = (-0.5)*(S + T) - (b/(3.0*a)) + (sqrt(3.0)*0.5)*(S - T)*i;
    x3 = conj(x2);

    if (abs(x1) < 0.000000000001)
    {
        x1 = 0;
    }
}

// Driver code
int main ()
{
    // Taking user input for a, b, c and d
    std::complex<double> a, b, c, d, x1, x2, x3;
    cout << "Please enter the coefficients of the polynomial in successive order." << endl;
    cin >> a >> b >> c >> d;

    solve (a, b, c, d, x1, x2, x3);
    cout << x1 << ", " << x2 << ", " << x3 << "." << endl;

    return 0;
}
