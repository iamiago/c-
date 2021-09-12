#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, cpt = 0;
    scanf("%d", &n);
    vector<int> p(n), q(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &p[i], &q[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (q[i] - p[i] >= 2)
        {
            cpt++;
        }
    }

    cout << cpt << endl;
    return 0;
}