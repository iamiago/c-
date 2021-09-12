#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += p[i];
    }
    float answer = ((float)sum / (float)(n * 100));
    cout << answer * 100 << endl;
    return 0;
}