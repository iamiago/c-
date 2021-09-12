#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, cpt = 0;
    scanf("%d", &n);
    vector<int> h(n), a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &h[i], &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == h[j])
                cpt++;
        }
    }
    cout << cpt << endl;

    return 0;
}