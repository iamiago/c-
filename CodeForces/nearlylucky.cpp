#include <iostream>

using namespace std;

bool isLucky(int value)
{

    return (value == 4 || value == 7);
}

int main()
{
    long long n;
    cin >> n;
    long long cpt = 0;
    while (n > 0)
    {
        long long a = n % 10;

        if (a == 4 || a == 7)
        {
            cpt++;
        }
        n /= 10;
    }
    if (isLucky(cpt))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}

// cout << cpt << endl;

// return 0;
// }