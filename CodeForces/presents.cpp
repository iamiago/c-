#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    vector<int> answer(n, 0);
    for (int i = 0; i < n; i++)
    {
        answer[p[i] - 1] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}