#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n, cpt = 0;
    scanf("%d", &n);
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == "Tetrahedron")
            cpt += 4;
        if (s[i] == "Cube")
            cpt += 6;

        if (s[i] == "Octahedron")
            cpt += 8;
        if (s[i] == "Dodecahedron")
            cpt += 12;
        if (s[i] == "Icosahedron")
            cpt += 20;
    }
    cout << cpt << endl;
    return 0;
}