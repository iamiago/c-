#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    // int cpt = 0;
    scanf("%d", &t);
    vector<long long> answer(t);
    vector<int> cpt(t, 0);
    for (int i = 0; i < t; i++)
    {
        cin >> answer[i];
    }
    // for (int i = 0; i < t; i++)
    // {
    //     if (answer[i] > 2)
    //     {
    //         int a = answer[i];
    //         int b = 0;
    //         while (a > b)
    //         {
    //             a--;
    //             b++;
    //             cpt[i]++;
    //         }
    //     }
    // }

    // for (int i = 0; i < t; i++)
    //     cpt[i] == 0 ? cout << cpt[i] << endl : cout << cpt[i] - 1 << endl;
    for (int i = 0; i < t; i++)
        answer[i] % 2 == 0 ? cout << ((answer[i] / 2) - 1) << endl : cout << ((answer[i] - 1) / 2) << endl;
    return 0;
}