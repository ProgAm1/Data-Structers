#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};
BSTNode *root = NULL;

BSTNode *createNode(int value)
{
    BSTNode *newNode = new BSTNode;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BSTNode *insert(BSTNode *root, int value)
{
    if (root == NULL)
    {
        root = createNode(value);
    }
    else if (value <= root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

bool Search(BSTNode *root, int value)
{
    if (root == NULL)

        return false;

    else if (root->data == value)
        return true;
    else if (value <= root->data)
        return Search(root->left, value);
    else
        return Search(root->right, value);
}
int FindMin(BSTNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return FindMin(root->left);
}

int FindMax(BSTNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return FindMax(root->right);
}
int FindHeight(struct BSTNode *root)
{
    if (root == NULL)
        return -1;

    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

void LevelOrder(BSTNode *root)
{
    if (root == NULL)
        return;

    queue<BSTNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        BSTNode *temp = Q.front();
        cout << temp->data << " ";
        if (temp->left != NULL)
            Q.push(temp->left);
        if (temp->right != NULL)
            Q.push(temp->right);
        Q.pop();
    }
}

void PreOrder(BSTNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void inOrder(BSTNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void PostOrder(BSTNode *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
bool IsSubTreeGreater(BSTNode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data > value && IsSubTreeGreater(root->left, value) && IsSubTreeGreater(root->right, value))
        return true;

    else
        return false;
}
bool IsSubTreeLesser(BSTNode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data <= value && IsSubTreeLesser(root->left, value) && IsSubTreeLesser(root->right, value))
        return true;

    else
        return false;
}

bool IsBST(BSTNode *root)
{
    if (root == NULL)
        return true;
    if (IsSubTreeLesser(root->left, root->data) && IsSubTreeGreater(root->right, root->data) && IsBST(root->left) && IsBST(root->right))
        return true;
    return false;
}

int main()
{
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 7);

    cout << "The queue Order of data is: ";
    LevelOrder(root);
    cout << endl;

    cout << "the Pre Order of data is: ";
    PreOrder(root);
    cout << endl;

    cout << "The in Order of data is: ";
    inOrder(root);
    cout << endl;

    cout << "The Post Order of data is: ";
    PostOrder(root);
    cout << endl;

    int x;
    cout << "\nEnter an integer to search: ";
    cin >> x;
    if (Search(root, x) == true)
        cout << "Founded" << endl;
    else
        cout << "Not Founded" << endl;

    cout << "the min value of the tree is: " << FindMin(root) << endl;
    cout << "the max value of the tree is: " << FindMax(root) << endl;
    cout << "the Height of tree is: " << FindHeight(root);
    cout << endl;
    cout << "Is Binary Search Tree? " << (IsBST(root) ? " Yes" : " No") << endl;

    return 0;
}
