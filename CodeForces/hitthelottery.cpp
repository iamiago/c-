#include <iostream>
using namespace std;
int main()
{
    long long n, cpt = 0;
    cin >> n;

    while (n >= 100)
    {
        n -= 100;
        cpt++;
    }
    // cout << n << " : " << cpt << endl;
    while (n >= 20)
    {
        n -= 20;
        cpt++;
    }
    // cout << n << " : " << cpt << endl;
    while (n >= 10)
    {
        n -= 10;
        cpt++;
    }
    // cout << n << " : " << cpt << endl;
    while (n >= 5)
    {
        n -= 5;
        cpt++;
    }
    // cout << n << " : " << cpt << endl;
    while (n >= 0)
    {
        n -= 1;
        cpt++;
    }
    // cout << n << " : " << cpt << endl;
    cout << cpt - 1 << endl;
    return 0;
}