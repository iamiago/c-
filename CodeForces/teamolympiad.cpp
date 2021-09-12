#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    int t[5001];
    vector<pair<int, int>> v;

    int nbGroups[3] = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
        v.push_back(make_pair(t[i], 0));
        if (t[i] == 1)
            nbGroups[0]++;
        if (t[i] == 2)
            nbGroups[1]++;
        if (t[i] == 3)
            nbGroups[2]++;
    }
    int minimum = min({nbGroups[0], nbGroups[1], nbGroups[2]});

    vector<int> one, two, three;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == 1)
        {
            one.push_back(i);
        }
        else if (t[i] == 2)
        {
            two.push_back(i);
        }
        else
        {
            three.push_back(i);
        }
    }
    cout << minimum << endl;
    for (int i = 0; i < minimum; i++)
    {
        cout << one[i] + 1 << " " << two[i] + 1 << " " << three[i] + 1 << endl;
    }

    return 0;
}
