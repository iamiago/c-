#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s[3], answer;
    cin >> s[0] >> s[1] >> s[2];
    cout << endl;
    // cout << s[0] << " : " << s[1] << " : " << s[2] << endl;
    for (int i = 0; i < 3; i++)
    {
        sort(s[i].begin(), s[i].end());
    }
    // cout << s[0] << " : " << s[1] << " : " << s[2] << endl;
    answer = s[0] + s[1];
    sort(answer.begin(), answer.end());
    // cout << s[2] << " : " << answer << endl;

    (answer == s[2]) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}