#include <iostream>

#include <vector>
using namespace std;
int main()
{
    int n, cpt = 0;
    scanf("%d", &n);
    vector<int> mag(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &mag[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (mag[i] == mag[i + 1])
            continue;
        else
        {
            cpt++;
        }
    }
    cout << cpt << endl;

    return 0;
}