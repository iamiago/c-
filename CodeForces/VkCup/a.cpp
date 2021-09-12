#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int nbGames = a + b;
        set<int> ans;
        for (int alice_tot : {nbGames / 2, (nbGames + 1) / 2})
        {

            for (int alice_won_first = 0; alice_won_first <= min(a, alice_tot); ++alice_won_first)
            {

                if (a - alice_won_first <= nbGames - alice_tot)
                {
                    if (alice_tot - alice_won_first + (a - alice_won_first) >= 0)
                        ans.insert(alice_tot - alice_won_first + (a - alice_won_first));
                    // cout << alice_tot - alice_won_first + (a - alice_won_first) << " ";
                }
            }
            // cout << endl;
        }
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}