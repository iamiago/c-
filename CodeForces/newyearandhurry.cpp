#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;
int main()
{
    int n, k, cpt = 0;

    int answer = 0;
    int hours = 60 * 4;
    cin >> n >> k;
    // for (int i = 0; i < n; i++)
    // {
    //     while (k > 0)
    //     {
    //         k -= (5 * i);
    //         cpt++;
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        if (hours - answer - k >= 0)
        {

            // assert(hours - answer - k >= 0);
            answer += i * 5;
            // cout << hours - answer << " : " << k << endl;
            // cout << hours - answer - k << endl;
            if (hours - answer - k >= 0)
            {
                cpt++;
            }
        }
    }
    cout << cpt << endl;
    return 0;
}