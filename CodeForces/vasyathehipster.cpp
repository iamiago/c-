#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int cpt = 0;
    int Min = min(a, b);
    if (a == b)
    {
        cpt = 0;
    }
    else if (a < b)
    {
        if ((b - a) % 2 == 0)
        {
            cpt = (b - a) / 2;
        }
        else
        {
            if (b - a <= 1)
            {
                cpt = 0;
            }
            else
            {
                cpt = ((b - a) / 2);
                // cout << cpt << endl;
            }
        }
    }
    else
    {
        if ((a - b) % 2 == 0)
        {
            cpt = (a - b) / 2;
        }
        else
        {
            if (a - b <= 1)
            {
                cpt = 0;
            }
            else
            {

                cpt = ((a - b) / 2);
                // cout << cpt << endl;
            }
        }
    }
    cout << Min << " " << cpt << endl;
    // (cpt == 0 || cpt == 1) ? cout << Min << " " << cpt << endl : cout << Min << " " << cpt << endl;
    return 0;
}