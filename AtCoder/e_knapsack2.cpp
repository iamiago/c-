#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

const ll INF = 1e18L + 5;
int main()
{
    ll n, w;
    cin >> n >> w;
    vector<int> weight(n), value(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &weight[i], &value[i]);
    }
    int sum_value = 0;
    for (int x : value)
    {
        sum_value += x;
    }
    vector<long long>
        dp(sum_value + 1, INF);

    dp[0] = 0;
    for (int item = 0; item < n; ++item)
    {
        for (int i = sum_value - value[item]; i >= 0; --i)
        {
            dp[i + value[item]] = min(dp[i + value[item]], dp[i] + weight[item]);
        }
    }
    // for (int i = 0; i <= w; ++i)
    //     cout << dp[i] << " ";

    // cout << endl;

    ll answer = 0;

    for (int i = 0; i <= sum_value; ++i)
    {
        if (dp[i] <= w)
        {
            answer = max(answer, (ll)i);
        }
        // answer = min(answer, dp[i]);
    }
    cout << answer << endl;
    // cout << dp[w] << endl;
    return 0;
}