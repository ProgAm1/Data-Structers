#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *top = NULL;

void push(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
void display()
{
    if (top == NULL)
    {
        cout << "Stack is empty";
    }

    else
    {
        cout << "Stacks is: ";
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}
int pop()
{

    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else
    {
        Node *temp = top;
        top = temp->next;
        cout << "poped elemnt is: " << temp->data << endl;
        temp->next = NULL;
        cout << "Stacks after poping: ";
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int peek()
{
    if (top == NULL)
    {
        cout << "\nStack is empty" << endl;
        return -1;
    }
    else
    {
        int value = 0;
        value = top->data;
        cout << "\nthe peek of the stack is: " << value << endl;
    }
}

int main()
{

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();

    cout << endl;

    pop();
    peek();
}