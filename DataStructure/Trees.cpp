#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include <cstdint>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *GetNewNode(int data);
Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

Node *GetNewNode(int data)
{
    Node *newNode = new Node(); // allocating heap/ dynamic memoru
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
//whenever a function call finishes, the stack frame allocated to it is reclaimed.

int FindMinBST(Node *root)
{
    Node *current = root;
    if (root == NULL)
    {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}
int FindMaxBST(Node *root)
{
    Node *current = root;
    if (root == NULL)
    {
        cout << "Error: tree is empty\n";
        return -1;
    }
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

int FindMinRecursivBST(Node *root)
{
    if (root == NULL)
    {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }

    return FindMinBST(root->left);
}

bool SearchBST(Node *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return SearchBST(root->left, data);
    else
        return SearchBST(root->right, data);
}

int FindHeight(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

//breadth search
void LevelOrder(Node *root)
// Time-complexity: O(n) _ Space complexity:
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    //while there is at least one discovered Node
    while (!q.empty())
    {
        Node *current = q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
        q.pop(); // removing the element we've just visited
    }
}

//depth search
void Preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder(Node *root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

//Check if a given binary tree is a BST
bool IsSubtreeLesser(Node *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data <= value &&
        IsSubtreeLesser(root->left, value) &&
        IsSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}
bool IsSubtreeGreater(Node *root, int value)
{

    if (root == NULL)
        return true;
    if (root->data <= value &&
        IsSubtreeGreater(root->left, value) &&
        IsSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}
bool IsBinarySearchTree(Node *root)
{
    if (root == NULL)
        return true;
    if (IsSubtreeLesser(root->left, root->data) &&
        IsSubtreeGreater(root->right, root->data) &&
        IsBinarySearchTree(root->left) &&
        IsBinarySearchTree(root->right))

        return true;
    else
        return false;
}

// bool IsBinarySearchTRee2(Node *root)
// {
//     return IsBstUtil(root, INT_MIN, INT_MAX);
// }

bool IsBstUtil(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;

    if (root->data < minValue && root->data > maxValue &&
        IsBstUtil(root->left, minValue, root->data) &&
        IsBstUtil(root->right, root->data, maxValue))
        return true;
    else
        return false;
}
int main()
{

    Node *root = NULL; // empty tree
    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 3);
    root = Insert(root, 1);
    root = Insert(root, 105);
    root = Insert(root, 40);
    root = Insert(root, 43);
    root = Insert(root, 54);
    int number;
    cout << "Entrer un nummero pour la recherche: \n";
    cin >> number;
    if (SearchBST(root, number) == true)
        cout << "Trouve\n";
    else
        cout << "Pas trouve\n";

    cout << "Height of tree: " << FindHeight(root) << endl;
    cout << "Max element of tree: " << FindMaxBST(root) << endl;
    cout << "Min element of tree: " << FindMinRecursivBST(root) << endl;
    LevelOrder(root);
    cout << endl;
    Preorder(root);
    cout << endl;
    (IsBinarySearchTree(root) == 0) ? cout << "False\n" : cout << "True\n";
    cout << "Max = " << std::numeric_limits<int64_t>::max() << endl;
    cout << "Min = " << std::numeric_limits<int64_t>::min() << endl;

    long long max = std::numeric_limits<int64_t>::max();
    long long nbDigits = 0;
    int nbChar = 0;
    string s = to_string(max);
    for (char &c : s)
    {
        nbChar++;
    }
    cout << s << endl;
    while (max != 0)
    {
        max = max / 10;
        nbDigits++;
    }
    cout << "Nb chiffres dans max: " << nbDigits << " " << nbChar << endl;

    return 0;
}