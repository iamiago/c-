#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < i + 3 && j < n; ++j)
        {
            dp[j] = min(dp[j], (dp[i] + abs(h[i] - h[j])));
        }
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[n - 1] << endl;
    return 0;
}