#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, h;
    scanf("%d%d", &n, &h);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int cpt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > h)
        {
            cpt += 2;
        }
        else
        {
            cpt++;
        }
    }
    cout << cpt << endl;
    return 0;
}