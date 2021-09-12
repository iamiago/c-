#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int max = 0, min = 101, maxindex = 0, minindex = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            maxindex = i;
            max = a[i];
        }
        if (a[i] <= min)
        {
            minindex = i;
            min = a[i];
        }
    }

    if (maxindex > minindex)
        cout << (maxindex - 1) + (n - minindex) - 1;
    else
        cout << (maxindex - 1) + (n - minindex);
    return 0;
}