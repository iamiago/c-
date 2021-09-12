#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    int a[101], maximum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        maximum = max(maximum, a[i]);
    }
    int cpt = 0;
    for (int i = 0; i < n; i++)
    {
        cpt += maximum - a[i];
    }
    cout << cpt << endl;

    return 0;
}