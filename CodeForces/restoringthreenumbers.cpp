#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long x[4];
    cin >> x[0] >> x[1] >> x[2] >> x[3];
    long long Max = max({x[0], x[1], x[2], x[3]});
    int a = Max - x[0];
    int b = Max - x[1];
    int c = Max - x[2];
    int d = Max - x[3];
    if (a == 0)
        cout << b << " " << c << " " << d << endl;
    if (b == 0)
        cout << a << " " << c << " " << d << endl;
    if (c == 0)
        cout << a << " " << b << " " << d << endl;
    if (d == 0)
        cout << a << " " << b << " " << c << endl;
    // cout << Max << endl;
    return 0;
}