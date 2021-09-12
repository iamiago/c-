#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int n, cpt = 0;
    scanf("%d", &n);
    string s;
    cin >> s;
    map<char, int> p;
    for (char &c : s)
    {
        c = tolower(c);
        p[c]++;
        // cout << c << " : " << p[c] << endl;
    }

    char character = 'a';
    for (int i = 0; i < 26; i++)
    {
        auto t = p.find(character);
        // cout << t->first << " : " << t->second << endl;
        if (t->first == character)
        {
            cpt++;
        }
        character++;
    }
    // cout << endl;
    // cout << cpt << endl;
    cpt >= 26 ? cout << "YES\n" : cout << "NO\n";
    return 0;
}