#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> v(n + 5, 0); // a vector fo length n filled with zeros

    long long S = 0;
    for (int i = 0; i < n; i++)
        cin >> v[i], S += v[i];

    if (S & 1)
    {
        cout << "NO\n";
        return 0;
    }
    map<long long, int> first, second;

    first[v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        second[v[i]]++;
    }

    long long Sdash = 0;
    for (int i = 0; i < n; i++)
    {
        Sdash += v[i];
        if (Sdash == S / 2)
        {
            cout << "YES\n";
            return 0;
        }
        if (Sdash < S / 2)
        {
            long long x = S / 2 - Sdash;
            // delete element from second half, and insert into first  half
            if (second[x] > 0)
            {
                cout << "YES\n";
                return 0;
            }
        }
        else
        {
            long long y = Sdash - S / 2;
            if (first[y] > 0)
            {
                cout << "YES\n";
                return 0;
            }
        }
        first[v[i + 1]]++;
        second[v[i + 1]]--;
    }
    cout << "NO\n";
    return 0;
}