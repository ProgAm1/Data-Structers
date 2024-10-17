#include <iostream>
using namespace std;

const int Size = 5;
int Queue[Size];
int front = -1;
int rear = -1;

void EnQueue(int value)
{

    if (rear == Size - 1)
    {
        cout << "Queue is Full! , cant put this value: " << value << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        Queue[rear] = value;
    }
    else
    {
        rear++;
        Queue[rear] = value;
    }
}
void display()
{
    if (front != -1 && rear != -1)
    {

        cout << "Queue is: ";
        for (int i = front; i <= rear; i++)
        {
            cout << Queue[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Queue is empty (;";
    }
}

int DeQueue()
{
    if (front == -1 && rear == -1)
    {
        cout << "\nQueue is empty" << endl;
    }
    else if (front == rear)
    {
        cout << "\nthe Queue that was deleting is " << Queue[front] << ", and the Queue became empty (;" << endl;
        front = -1;
        rear = -1;
    }
    else
    {
        cout << "\nthe Queue that was deleted: " << Queue[front] << endl;
        Queue[front] = ++front;
        cout << "Queue after deletion: ";
        for (int i = front; i <= rear; i++)
        {
            cout << Queue[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);
    EnQueue(40);
    EnQueue(50);
    display();
    DeQueue();
    DeQueue();
    DeQueue();
}
