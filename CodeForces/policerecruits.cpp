#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[100001];
    int crime_untreated = 0;
    int police_available = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            police_available += a[i];
            // cout << "police available: " << police_available << endl;
        }
        else
        {
            if (police_available < 1)
            {
                crime_untreated++;
                // cout << "crime untreated: " << crime_untreated << endl;
            }
            else
            {
                police_available--;
                // cout << "police available: " << police_available << endl;
            }
        }
    }
    cout << crime_untreated << endl;
    return 0;
}