#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int s[4];
    int value = 0;
    scanf("%d%d%d%d", &s[0], &s[1], &s[2], &s[3]);

    sort(s, s + 4);

    for (int i = 0; i < 4; i++)
    {
        if (s[i] == s[i + 1])
        {
            value++;
        }
    }
    cout << value << endl;

    return 0;
}