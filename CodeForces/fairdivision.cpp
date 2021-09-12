#include <iostream>
#include <vector>
using namespace std;

void test_case()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i)
    {

        scanf("%d", &a[i]);
    }
    int two = 0, one = 0;
    for (auto x : a)
    {
        if (x == 2)
            two++;
        else
            one++;
    }
    if ((two % 2 == 0 && one % 2 == 0) || (two % 2 == 1 && one % 2 == 0 && one != 0))
        cout << "yes\n";
    else
        cout << "no\n";
}

void test_case2()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    scanf("%d", &n);
    vector<int> a(n, 0);
    bool oneValid = false, twoValid = false;
    int two = 0, one = 0;
    for (int i = 0; i < n; ++i)
    {

        scanf("%d", &a[i]);
        if (a[i] == 1 && oneValid == false)
        {
            one += a[i];
            oneValid = true;
        }
        else if (a[i] == 1 && oneValid == true)
        {
            two += a[i];
            oneValid = false;
        }
        else if (a[i] == 2 && twoValid == false)
        {
            one += a[i];
            twoValid = true;
        }
        else if (a[i] == 2 && twoValid == true)
        {
            two += a[i];
            twoValid = false;
        }
    }
    if (one == two)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        test_case2();
    }
    return 0;
}