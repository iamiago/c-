#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'A')
        {
            a++;
        }
        if (s[i] == 'D')
        {
            b++;
        }
    }

    if (a == b)
        cout << "Friendship\n";
    if (a > b)
        cout << "Anton\n";
    if (a < b)
        cout << "Danik\n";
    return 0;
}