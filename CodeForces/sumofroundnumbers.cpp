#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    int n;

    while (t--)
    {
        scanf("%d", &n);
        vector<int> a;
        if (n >= 1000)
        {
            int rest = n % 1000;
            // cout << rest << endl;
            a.push_back(n - rest);
            // cout << n - rest << endl;
            n %= 1000;
            // cout << n << endl;
        }
        if (n >= 100)
        {
            int rest = n % 100;
            a.push_back(n - rest);
            n %= 100;
        }
        if (n >= 10)
        {
            int rest = n % 10;
            a.push_back(n - rest);
            n %= 10;
        }
        if (n < 10 && n > 0)
        {
            a.push_back(n);
        }
        sort(a.begin(), a.end());
        cout << a.size() << "\n";
        for (int i = 0; i < (int)a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}