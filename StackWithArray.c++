#include <iostream>
using namespace std;

// Stack implementation using array

const int Size = 5; // Stack size
int stack[Size];    // Stack
int top = -1;       // variable that will be used for discovered if stack is empty or overloaded
// , and known the stack size

void push(int value) // Push value
{

    if (top == Size - 1) // make statement toknow if stack is full (top = 4)
    {
        cout << "stack is overloaded" << endl; // print text that stack is overloaded
    }
    else
    {
        top++;              // insert 1 to index of stack
        stack[top] = value; // push value
    }
}

void display() // Display the stack valuse
{

    if (top == -1) // make statement to know if stack is empty by see the top equal -1 (index starts from 0);
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        // while(top!=-1){
        //     cout<<stack[top]<<endl;
        //     top--;
        // }
        cout << "Valuse of Stack are: "; // print a message
        for (int i = top; i >= 0; i--)   // loop to print values for stake (Last in , First out)

        {

            cout << stack[i] << " ";
        }
    }
    cout << endl;
}

int pop()
{

    if (top == -1)
    {
        cout << "the stach is empty" << endl;
    }
    else
    {
        cout << "the stack that was popped: ";
        cout << stack[top--] << endl;
        cout << "Valuse of Stack after pop: "; // print a message
        for (int i = top; i >= 0; i--)         // loop to print values for stake (Last in , First out)

        {

            cout << stack[i] << " ";
        }
    }

} // Pop value

int peek()
{

    if (top == -1)
    {
        cout << "\nthe stack are empty";
    }
    else
    {

        cout << "\nthe peek of the stack is: ";
        cout << stack[top];
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
    // display();
    peek();
}