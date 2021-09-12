#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> rep(n + 1);
        rep[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            rep[i] = rep[i / 2] + i % 2;
        }
        return rep;
    }
};

int main()
{

    int n;
    Solution solution;
    std::cout << "Veillez renter un nombre:" << std::endl;
    std::cin >> n;
    std::vector<int> a = solution.countBits(n);
    std::cout << "Tableau: [";
    for (int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i];
        if (i != a.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    return 0;
}