#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

//a global variable is always accessible anywhere in the program
// its stored in the heap section of applications memory  (also called dynamic memory)
// its cleared from memory only if we explicitly free/remove it
// to create a node in heap we use malloc/new operator
struct Node *head;

struct Node *getNewNode(int x)
{
    // local variables of a function will be cleared from memory when the function call is finished
    // a local variables lives in the stack section of applications memory
    // we cannot control its life time because its cleared from memory at the end of the function call
    // newNode is local to this function
    struct Node *newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL, newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x)
{
    // newNode is local to this funtion
    struct Node *newNode = getNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void Print()
{
    struct Node *temp = head;
    cout << "Forward: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void ReversePrint()
{
    struct Node *temp = head;
    if (temp == NULL)
        return; // si la list est vide on retourne

    // On parcours la liste jusqu'au dernier noeud
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // On parcours la liste à l'envers
    cout << "Reverse: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

main()
{
    head = NULL;
    InsertAtHead(2);
    Print();
    ReversePrint();

    InsertAtHead(4);
    Print();
    ReversePrint();

    InsertAtHead(6);
    Print();
    ReversePrint();
}
