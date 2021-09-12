#include <iostream>
#include <math.h>

using namespace std;

void factApprox(int n)
{

    cout << (long long int)(sqrt(2 * M_PI * n) * pow(n / exp(1), n) + 1);
}
void fact(int n)
{
    long long int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    cout << result;
}
int main()
{
    for (int i = 0; i < 21; i++)
    {
        cout << "Value : ";
        fact(i);
        cout << "   Approximation : ";
        factApprox(i);
        cout << endl;
    }
    return 0;
}