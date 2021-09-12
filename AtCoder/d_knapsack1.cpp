#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int n, w;
    scanf("%d%d", &n, &w);
    vector<int> dp(w + 1);

    for (int item = 0; item < n; ++item)
    {
        int weight, value;
        scanf("%d%d", &weight, &value);
        // cout << "value of weight : " << weight << " value of value : " << value << endl;
        for (int i = w - weight; i >= 0; --i)
        {

            // cout << "value of i : " << i << " value of dp[i] : " << dp[i] << "  max(dp[i+weight]=" << dp[i + weight] << " ,dp[i]+value=" << dp[i] + value << ") = " << max(dp[i + weight], dp[i] + value) << endl;
            dp[i + weight] = max(dp[i + weight], dp[i] + value);
        }
        // for (int i = 0; i < w + 1; i++)
        // {
        //     cout << " i = " << i << " dp[i] = " << dp[i] << " ";
        // }
        // cout << endl;
    }
    int answer = 0;
    for (int i = 0; i <= w; ++i)
    {
        answer = max(answer, dp[i]);
    }

    printf("%d", answer);
    return 0;
}