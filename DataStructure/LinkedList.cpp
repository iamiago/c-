#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
// cette variable global est accessible n'importe où
struct Node *head;

void Insert(int data);
void Print();
void Delete(int n);
void Reverse();
void PrintRecursive(struct Node *list);

void PrintRevursiveReverse(struct Node *list);
void ReverseRecursive(struct Node *list);

void Insert(int x) // Cette fonction ajoute un element en tête de liste
{
    // Node* temp = (Node*)malloc(sizeof(Node));
    Node *temp = new Node();
    // (*temp).data =x;
    temp->data = x;
    temp->next = head;
    // if(head != NULL) temp->next = head;
    head = temp;
}

void Print()
{
    struct Node *temp = head;
    cout << "La liste: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Delete(int n)
{
    struct Node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        delete temp1;
        return;
    }
    int i;
    for (i = 0; i < n - 2; ++i)
        temp1 = temp1->next;

    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

struct Node *Reverse(struct Node *head)
{

    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void PrintRecursive(struct Node *list)
{
    if (list == NULL)
    {
        cout << endl;
        return;
    }
    cout << list->data << ' ';
    PrintRecursive(list->next);
}

void PrintRevursiveReverse(struct Node *list)
{
    if (list == NULL)
    {
        return;
    }

    PrintRevursiveReverse(list->next);
    cout << list->data << ' ';
}
/*
void ReverseRecursive(struct Node *list)
{
    if (list->next == NULL)
    {
        head = list;
        return;
    }
    ReverseRecursive(list->next);
    struct Node *aux = list->next;
    aux->next = list;
    list->next = NULL;
}
*/

int main()
{
    head = NULL;
    // la list est vide au départ
    // cout << "Combien de numeros dans la liste ? " << '\n';
    // int n, i, x;
    // cin >> n;
    // for (i = 0; i < n; i++)
    // {
    //     cout << "Entrez un numero" << endl;
    //     cin >> x;
    //     Insert(x);
    //     Print();
    // }
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
    PrintRecursive(head);
    PrintRevursiveReverse(head);
    head = Reverse(head);
    cout << "\n[reverse function call]" << endl;
    Print();
    PrintRecursive(head);
    PrintRevursiveReverse(head);
    int n;
    cout << endl;
    cout << "Entrer une position a supprimer :" << endl;
    cin >> n;
    Delete(n);
    Print();
}