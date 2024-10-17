#include <iostream>
using namespace std;

struct node
{
    int data = 0;
    node *next;
};

node *head = NULL;

void insertNode(int value)
{

    node *newNode;
    node *last;
    newNode = new node;
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = NULL;
    }
}

int display()
{

    node *currentNode = head;

    if (head == NULL)
    {
        cout << "linked list is empty\n"
             << endl;
    }
    else
    {
        currentNode = head;
        while (currentNode != NULL)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
    }
    cout << endl;
}

void insertNodeatbeginning(int value)
{
    node *newNode;
    newNode = new node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void deleteBegNode()
{
    node *firstNode;

    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        firstNode = head;
        head = firstNode->next;
        firstNode->next = NULL;
        delete (firstNode);
    }
}

void deleteNode(int value)
{
    node *cr;
    node *pre;
    cr = head;
    pre = head;

    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    if (cr->data == value)
    {
        head = cr->next;
        cr->next = NULL;
        free(cr);
    }
    else
    {
        while (cr->data != value)
        {
            pre = cr;
            cr = cr->next;
            if (cr == NULL)
            {
                cout << "Value not found in list" << endl;
                break;
            }
        }
        pre->next = cr->next;
        free(cr);
    }
}
void deleteLastNode()
{
    node *crNode;
    crNode = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (crNode->next == NULL)
    {
        delete (crNode);
        head = NULL;
    }
    else
    {
        node *cr;
        node *pre;
        cr = head;
        pre = head;
        while (cr->next != NULL)
        {
            pre = cr;
            cr = cr->next;
        }
        pre->next = NULL;
        free(cr);
    }
}

int main()
{
    insertNode(10);
    insertNode(20);
    insertNode(30);
    insertNode(40);
    insertNode(50);
    cout << "Original Linked List: " << endl;
    display();
    insertNodeatbeginning(100);
    cout << "Linked List after inserting Node 100 at the beginning: " << endl;
    display();
    deleteNode(20);
    cout << "Linked List after deleting Node 20: " << endl;
    display();
    deleteLastNode();
    cout << "Linked List after deleting Last node: " << endl;
    display();
}