#include <iostream>
#include <list>
#include <cstring>
#include <string>
using namespace std;

//<key,value>  ex: 905, Bob
class HashTable
{
    // combien de collections utilise-t-on
private:
    static const int hashGroups = 10;
    // on a un tableau qui contient des list et chaque list contienra des pairs (une paire, 1000 paires, etc.)
    list<pair<int, string>> table[hashGroups]; // List 1, Index 0, list 2, index 1....

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const
{
    int sum{};
    for (int i = 0; i < hashGroups; i++)
    {
        sum += table[i].size();
    }
    if (!sum)
    {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key)
{
    return key % hashGroups;
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists. Value replaced.\n";
            break;
        }
    }
    if (!keyExists)
    {
        cell.emplace_back(key, value);
    }
    return;
}

void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Item removed.\n";
            break;
        }
    }
    if (!keyExists)
    {
        cout << "[WARNING] Key not found. Pair not removed. \n";
    }
}

void HashTable::printTable()
{
    cout << "=== Hash Table ===\n";
    for (int i{}; i < hashGroups; i++)

    {

        if (table[i].size() == 0)
            continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++)
        {
            cout << "<Key: " << bItr->first << ",  Value: " << bItr->second << ">\n";
        }
        if (i == hashGroups - 1)
        {
            cout << "=== End ===\n";
        }
    }
}

int main()
{
    HashTable ht;

    if (ht.isEmpty())
    {
        cout << "Table is empty.\n";
    }
    else
    {
        cout << "Table is not empty.\n";
    }

    ht.insertItem(905, "Bob");
    ht.insertItem(19, "Tom");
    ht.insertItem(12, "Donald");
    ht.insertItem(4, "Rob");
    ht.insertItem(2, "John");
    ht.printTable();

    ht.insertItem(2, "iago");
    ht.printTable();

    ht.removeItem(19);
    ht.removeItem(100);

    if (ht.isEmpty())
    {
        cout << "Table is empty.\n";
    }
    else
    {
        cout << "Table is not empty.\n";
    }
    return 0;
}