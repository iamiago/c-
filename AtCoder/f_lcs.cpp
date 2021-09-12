#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
using ll = long long;

const ll INF = 1e18L + 5;

void max_self(int &a, int b)
{
    a = max(a, b);
}
int main()
{

    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int i = 0; i < (int)a.length(); ++i)
    {
        for (int j = 0; j < (int)b.length(); ++j)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
        }
    }
    int answer = 0;
    for (auto row : dp)
    {
        for (int value : row)
        {
            max_self(answer, value);
        }
    }

    cout << answer << endl;
    return 0;
}