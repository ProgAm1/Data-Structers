#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node *next = NULL;
};

Node *front = NULL;
Node *rear = NULL;

void enQueue(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void display()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        Node *temp = front;
        cout << "Queue elemnt: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}
void deQueue()
{
    if (front == NULL && rear == NULL)
    {
        cout << "\nQueue is empty!" << endl;
        return;
    }
    else if (front == rear)
    {
        cout << "\nThe elemnt that was deleted: " << front->data << endl;
        front = NULL;
        rear = NULL;
        cout << "Queue became empty (;" << endl;
    }
    else
    {
        cout << "\nThe elemnt that was deleted: " << front->data << endl;
        Node *temp = front->next;
        front->next = NULL;
        front = temp;
        cout << "Queue After deletion: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}
void peek()
{
    if (front == NULL && rear == NULL)
    {
        cout << "\nQueue is empty!" << endl;
        return;
    }
    else
    {
        cout << "The peek of elemnt is: " << front->data << endl;
    }
}
bool isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);
    enQueue(60);
    display();
    peek();
    deQueue();
    peek();
    deQueue();
    peek();
    deQueue();
    peek();
    cout << isEmpty();
}
