#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    int n, a[55];
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (n == 1)
        {
            cout << "YES\n";
            continue;
        }
        sort(a, a + n);
        vector<int> v;
        int dif = 0;
        for (int i = 1; i < n; ++i)
        {
            dif = abs(a[i] - a[i - 1]);
            v.push_back(dif);
        }
        sort(v.begin(), v.end(), greater<int>());
        if (v[0] > 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
        // for (int i = 0; i < n; ++i)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
    }

    return 0;
}