#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    n % 2 == 0 ? cout << n / 2 << endl : cout << (-1) * ((n + 1) / 2) << endl;
    return 0;
}