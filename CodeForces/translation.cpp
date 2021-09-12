#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    bool ok = true;
    cin >> s >> t;
    int j = (int)s.size() - 1;
    for (int i = 0; i < (int)s.size(); i++)
    {

        // cout << s[i] << " " << t[j] << endl;
        if (s[i] != t[j])
        {
            // cout << s[i] << " " << t[j] << endl;
            ok = false;
            break;
        }
        j--;
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}