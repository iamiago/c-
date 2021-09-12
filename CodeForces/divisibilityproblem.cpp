#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    vector<int> answer(t);
    for (int i = 0; i < t; i++)
    {
        long long a, b;
        cin >> a >> b;
        if (a % b == 0)
            answer[i] = a % b;
        else
            answer[i] = b - a % b;
    }

    for (int i = 0; i < t; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}