#include <iostream>
using namespace std;
int main()
{
    int n, points;
    cin >> n >> points;
    int min(points), max(points), amazing(0);
    // cout << min << " : " << max << " : " << amazing << endl;
    while (--n)
    {
        cin >> points;

        if (points < min)
        {
            min = points;
            amazing++;
            // cout << "MIN CHANGE -- " << min << " : " << max << " : " << amazing << endl;
        }
        if (points > max)
        {
            max = points;
            amazing++;
            // cout << "MAX CHANGE -- " << min << " : " << max << " : " << amazing << endl;
        }
    }

    cout << amazing << endl;
}