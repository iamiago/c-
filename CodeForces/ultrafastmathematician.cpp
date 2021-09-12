#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main()
{
    // int n, m;
    string s, t;
    cin >> s >> t;
    string answer = s;

    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == t[i])
        {
            answer[i] = '0';
        }
        else
        {
            answer[i] = '1';
        }
    }
    cout << answer << endl;

    return 0;
}