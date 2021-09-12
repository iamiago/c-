#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        i % 2 == 0 ? s += "I hate " : s += "I love ";
        i != n - 1 ? s += "that " : s += "it ";
    }

    cout << s << endl;
    return 0;
}