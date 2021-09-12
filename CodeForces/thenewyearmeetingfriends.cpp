#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char **argv)
{
    int x[3];
    cin >> x[0] >> x[1] >> x[2];
    int MIN, MAX;
    MIN = min({x[0], x[1], x[2]});
    MAX = max({x[0], x[1], x[2]});
    // int dist = 0;
    // for (int i = 0; i < 3; i++)
    // {
    //     if (x[i] != MIN && x[i] != MAX)
    //     {
    //         dist += (MAX - x[i]) +  (x[i] - MIN);
    //     }
    // }
    cout << MAX - MIN << endl;

    return 0;
}