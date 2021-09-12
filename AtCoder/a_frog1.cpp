#include "bits/stdc++.h"

const int INF = 1e9 + 5;
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for (int &x : h)
    {
        std::cin >> x;
    }
    std::vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j : {i + 1, i + 2})
        {
            if (j < n)
            {
                dp[j] = std::min(dp[j], dp[i] + abs(h[i] - h[j]));
            }
        }
    }
    std::cout << dp[n - 1] << std::endl;
    return 0;
}

// echo " test " > in.txt
// Get-Content in.txt | ./a