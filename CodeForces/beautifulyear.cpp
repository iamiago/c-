#include <iostream>

using namespace std;

bool isValid(int n)
{

    int a[4];
    for (int i = 0; i < 4; i++)
    {
        a[i] = n % 10;

        n /= 10;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j)
            {
                if (a[i] == a[j])
                    return false;
            }
        }
    }
    return true;
}

int main()
{

    int n;
    scanf("%d", &n);
    n++;
    // isValid(n);
    while (!isValid(n))
    {
        n++;
    }

    cout << n << endl;
    return 0;
}