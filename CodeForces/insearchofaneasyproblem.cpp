#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, result;
    bool isHard = false;
    scanf("%d", &n);

    // vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &result);
        if (result == 1)
            isHard = true;
    }
    isHard ? cout << "HARD\n" : cout << "EASY\n";

    return 0;
}