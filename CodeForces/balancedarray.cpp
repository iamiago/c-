#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        n /= 2;
        if (n % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            cout << i * 2 << " ";
        }
        for (int i = 1; i < n; i++)
        {
            cout << i * 2 - 1 << " ";
        }
        cout << 3 * n - 1 << endl;
    }
    return 0;
}