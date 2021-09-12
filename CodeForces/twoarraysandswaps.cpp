#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int main(int argc, char **argv)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> a(n);
        for (auto &it : a)
            cin >> it;
        vector<int> b(n);
        for (auto &it : b)
            cin >> it;
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        // cout << "a[i]: " << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // cout << "b[i]: " << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << b[i] << " ";
        // }
        // cout << endl;

        int cpt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < k)
                cpt += max(a[i], b[i]);
            else
                cpt += a[i];
        }

        cout << cpt << endl;
    }

    return 0;
}