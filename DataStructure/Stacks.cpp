#include <iostream>
#include <stack>
using namespace std;
//Stack is a abstrac data type ADT which means we only talk about features / operations no implementation

#define MAX_SIZE 101
struct Stack
{
    int tab[MAX_SIZE];
    int top = -1;

    void test()
    {
        cout << "test" << endl;
    }
    void push(int x)
    {
        if (top == MAX_SIZE - 1)
        {
            std::cout << "Error: Stack overflow" << endl;
            return;
        }
        tab[++top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            std::cout << "No elements to remove " << endl;
            return;
        }
        top--;
    }

    int Top()
    {
        return tab[top];
    }

    void print()
    {
        int i;
        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
            std::cout << tab[i] << " ";

        cout << endl;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack tab;

    tab.isEmpty() == 1 ? cout << "Empty \n" : cout << "Not Empty\n";
    tab.push(2);
    tab.print();
    tab.push(4);
    tab.print();
    tab.push(8);
    tab.print();
    tab.pop();
    tab.print();
    tab.pop();
    tab.print();
    tab.isEmpty() == 1 ? cout << "Empty \n" : cout << "Not Empty\n";
    return 0;
}