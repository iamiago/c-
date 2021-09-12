#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    vector<int> x(n, 0);
    for (auto &a : x)
        cin >> a;

    // vector<int> dp(n, 0);
    int diversity = 1;
    for (int i = 0; i < n; ++i)
    {
        if ((int)x.size() == 1)
            break;
        if (x[i] != x[i + 1])
            diversity++;
        else
        {
            while (x[i] == x[i + 1])
            {
                i++;
            }
            if (x[i] + 1 == x[i + 1])
            {
                x[i]++;
                x[i + 1]++;
                sort(x.begin(), x.end());
            }
            else
            {
                x[i]++;
            }
            if (x[i] != x[i + 1])
                diversity += 1;
        }
    }
    cout << "answer: " << diversity << endl;
}

void test_case2()
{
    int n;
    cin >> n;
    vector<int> x(n, 0);
    for (auto &a : x)
        cin >> a;

    // vector<int> dp(n, 0);
    int diversity = 1;
    set<int> s;
    s.insert(x[0]);
    for (int i = 1; i < n; ++i)
    {
        if (s.count(x[i]))
        {
            //x[i] is in set, count == 1
            x[i]++;
            s.insert(x[i]);
            diversity++;
        }
        else
        {
            s.insert(x[i]);
            diversity++;
        }
    }

    cout << (int)s.size() << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        test_case2();
    }
    return 0;
}