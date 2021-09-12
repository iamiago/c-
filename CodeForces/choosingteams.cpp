#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char **argv)
{
    int n, k;
    scanf("%d%d", &n, &k);
    int y[2001];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
    }
    int cpt = 0;
    for (int i = 0; i < n; i++)
    {
        if (y[i] <= 5 - k)
        {
            cpt++;
        }
    }
    if (cpt >= 3)
    {

        cout << cpt / 3 << endl;
    }
    else
    {
        // cout << cpt << endl;
        cout << "0" << endl;
    }

    return 0;
}