#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    set<char> a;
    for (int i = 0; i < (int)s.length(); i++)
    {
        // cout << s[i] << endl;
        if (s[i] >= 'a' && s[i] <= 'z')
            a.insert(s[i]);
    }
    cout << a.size() << endl;
}