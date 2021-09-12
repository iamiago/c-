#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <climits>
#include <unordered_map>

using namespace std;

void isPresent(bool present)
{
    if (present == 1)
    {
        cout << "Found \n";
    }
    else
    {
        cout << "Not found\n";
    }
}

bool strictlyGreaterThan(int x, int y)
{
    return x > y;
}

void vectorDemo()
{
    vector<int> A = {11, 2, 3, 14};

    cout << A[1] << endl;
    sort(A.begin(), A.end()); // O(NlogN)

    bool present = binary_search(A.begin(), A.end(), 3);

    isPresent(present);
    present = binary_search(A.begin(), A.end(), 6);
    isPresent(present);
    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100);
    isPresent(present);

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);

    // first occurence of 100 in the vector
    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100);  // >= iterator pointing to the first occurence of value 100  --
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // > iteratpr pointin to the first element strictly greater than 100 ( in our case  to value 123)

    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl; // 5

    //sorting in decreasing order
    sort(A.begin(), A.end(), strictlyGreaterThan);

    // vector<int>::iterator it3;
    // for (it3 = A.begin(); it3 != A.end(); it3++)
    // {
    //     cout << *it3 << " ";
    // }
    // cout << endl;

    //ecrit plus rapidement
    for (int &x : A) // on done la référence si on souhaite modifier les valuers a chaque iteration
    {
        x++;
        cout << x << " ";
    }
    cout << endl;
}

void setDemo()
{
    set<int> s;
    //inser operation is done in log(n) time
    s.insert(1);
    s.insert(2);
    s.insert(-1);
    s.insert(-1);
    s.insert(-1);

    s.insert(20);
    s.insert(-4);

    for (int x : s)
        cout << x << " ";

    cout << endl;
    auto it = s.find(-1);
    if (it == s.end())
    {
        cout << "Element not found. \n";
    }
    else
    {
        cout << "Found: " << *it << endl;
    }

    auto it2 = s.lower_bound(-1);
    auto it3 = s.upper_bound(-1);
    cout << *it2 << " " << *it3 << endl;

    auto it4 = s.upper_bound(20);
    if (it4 == s.end())
    {
        cout << "Element not found. \n";
    }
    else
    {
        cout << "Found: " << *it4 << endl;
    }
}

void mapDemo()
{
    map<int, int> a;
    a[1] = 100;
    a[2] = -1;
    a[3] = 2;
    a[254] = 35;

    map<char, int> cnt;
    string x = "this is a test string for testing purpose";
    for (char c : x)
    {
        cnt[c]++;
    }

    cout << "String: " << x << "\nnumber of 'a' in the string: " << cnt['a'] << "\nnumber of 't' in the string: " << cnt['t'] << "\nnumber of 'z' in the string: " << cnt['z'] << endl;
}

void testingThePowerOfStl()
{
    // [x,y]   [2,3]  [10,20]  [30,400] [401,450]  what interval contains 401?
    set<pair<int, int>> s;
    s.insert({401, 450});
    s.insert({30, 400});
    s.insert({10, 20});
    s.insert({2, 3});

    // for (auto x : s)
    // {
    //     cout << "<" << x.first << ", " << x.second << "> ";
    // }
    // cout << endl;

    int point = 50;

    auto it = s.upper_bound({point, INT_MAX}); // strictlyGreaterThan
        // cout << "<" << it->first << " " << it->second << ">" << endl;

    if (it == s.begin())
    {
        cout << "The given point is not lying in any interval... \n";
        return;
    }

    it--;

    pair<int, int> current = *it;
    if (current.first <= point && point <= current.second)
    {
        cout << "Yes its present in the interval: [" << current.first << ", " << current.second << "]" << endl;
    }
    else
    {
        cout << "The given point is not lying in any interval... \n";
    }
}

void unorderedMapDemo()
{
    map<char, int> m;
    unordered_map<char, int> u;

    string s = "iago gama de souza";
    // add(key,value) - logN for map and O(1) for unordered_map

    for (char c : s)
        m[c]++;

    for (char c : s)
        u[c]++;

    cout << "Map:" << endl;
    for (auto x : m)
        cout << "|char: " << x.first << ", ocurrences: " << x.second << "|\n";
    // cout << endl;

    cout << "UnorderedMap:" << endl;
    for (auto x : u)
        cout << "|char: " << x.first << ", ocurrences:" << x.second << "|\n";
    cout << endl;
}
int main(int argc, char **arc)
{
    //C++ STL
    // vectorDemo();
    // setDemo();
    // mapDemo();
    unorderedMapDemo();
    // testingThePowerOfStl();

    return 0;
}