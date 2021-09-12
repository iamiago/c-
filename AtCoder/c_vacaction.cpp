#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
void test()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }

    vector<int> dp(n, 0);

    int MAX = max(a[0], b[0]);
    MAX = max(MAX, c[0]);
    dp[0] = MAX;

    for (int i = 0; i < n; ++i)
    {
        int Max = max({a[i], b[i], c[i]});

        if (i >= 1)
            dp[i] = max(dp[i], dp[i - 1] + Max);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
}
int main()
{

    int n;
    scanf("%d", &n);
    vector<int> dp(3);

    for (int day = 0; day < n; ++day)
    {
        vector<int> new_dp(3, 0);
        vector<int> c(3);

        for (int i = 0; i < 3; ++i)
        {
            scanf("%d", &c[i]);
        }

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i != j)
                {
                    new_dp[j] = max(new_dp[j], dp[i] + c[j]);
                }
            }
        }
        dp = new_dp;
    }

    cout << max({dp[0], dp[1], dp[2]}) << endl;

    return 0;
}