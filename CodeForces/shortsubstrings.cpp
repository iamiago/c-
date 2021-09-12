#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    vector<string> a(t);

    for (int i = 0; i < t; ++i)
    {
        string s;
        cin >> a[i];
        int len = a[i].length();
        for (int j = 0; j < len - 1; ++j)
        {
            if (j == 0)
            {
                s += a[i][j];
            }
            if (a[i][j] == a[i][j - 1])
            {
                s += a[i][j];
                j++;
            }
        }
        s += a[i][len - 1];
        cout << s << endl;
    }
}