#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    long long a, b;
    while (t--)
    {
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }

        long long num1 = max(a, b) - min(a, b);
        long long ans = 0;
        long long ss = num1 / 10;
        ans += ss;
        if (num1 % 10)
            cout << ans + 1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}