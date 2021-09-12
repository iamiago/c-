#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int n, p, q;
    scanf("%d", &n);
    scanf("%d", &p);
    // cout << p << endl;
    vector<int> a(p);

    for (int i = 0; i < p; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    vector<int> levels(q);
    // cout << q << endl;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &levels[i]);
    }
    set<int> answer;
    sort(a.begin(), a.end());
    sort(levels.begin(), levels.end());
    a.insert(a.end(), levels.begin(), levels.end());

    for (int i = 0; i < (int)a.size(); i++)
    {
        answer.insert(a[i]);
        // cout << a[i] << " ";
    }
    for (int i = 0; i < (int)levels.size(); i++)
    {
        answer.insert(a[i]);
        // cout << levels[i] << " ";
    }
    auto itr = answer.begin();
    for (int i = 1; i <= n; i++)
    {

        // cout << *itr << endl;
        if (*itr != i)
        {
            cout
                << "Oh, my keyboard!\n";
            return 0;
            // break;
        }
        itr++;
    }

    // for (auto x : answer)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    cout << "I become the guy.\n";
    return 0;
}