#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k, l, m, n, d;
    scanf("%d%d%d%d%d", &k, &l, &m, &n, &d);
    vector<int> answer(d + 1, 0);
    for (int i = k; i <= d; i += k)
    {
        if (answer[i] == 0)
            answer[i]++;
    }
    for (int i = l; i <= d; i += l)
    {
        if (answer[i] == 0)
            answer[i]++;
    }
    for (int i = m; i <= d; i += m)
    {
        if (answer[i] == 0)
            answer[i]++;
    }
    for (int i = n; i <= d; i += n)
    {
        if (answer[i] == 0)
            answer[i]++;
    }
    int result = 0;
    for (int i = 0; i <= d; i++)
    {
        result += answer[i];
    }
    std::cout << result;

    return 0;
}