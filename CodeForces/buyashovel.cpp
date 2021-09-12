#include <iostream>
using namespace std;
int main()
{
    int k, r;
    scanf("%d%d", &k, &r);
    int lastdigit = k % 10;
    int cpt = 0;
    int counter = 0;
    if (lastdigit == r)
    {
        cout << 1 << endl;
    }
    else
    {
        while (lastdigit != r)
        {

            counter += k;
            lastdigit = counter % 10;
            // cout << lastdigit << " " << counter << endl;
            // cout << lastdigit % r << endl;
            cpt++;
            if (counter % 10 == 0)
            {

                break;
            }
        }
        cout << cpt << endl;
        // cout << cpt << ": k=" << k << endl;
    }
    return 0;
}