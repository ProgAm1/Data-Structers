#include <iostream>
using namespace std;

//   ******Double Linked List******   //

// our struct called Node has ( prev - data - next)
struct Node
{

    int data;   // The variable to be saved is of integer type
    Node *next; // the pointer that will be refers to the next node
    Node *prev; // the pointer that will be refers to the before node
};
Node *head = NULL;

// funcation to creating a new node
void insertNode(int value)
{
    Node *newNode = new Node(); // create new node
    Node *temp;                 // creat a variable for discovering the last node
    newNode->data = value;      // set data to equal the value that will be insert
    if (head == NULL)           // we put condition if the head is NULL , that means
    // the node we want to insert will be at the beginning
    {
        head = newNode;       // so, we set the head to refers to the new node we inserted
        newNode->next = NULL; // set the next of the nwe node to NULL
        newNode->prev = NULL; // set the prev of the nwe node to NULL
    }
    else // if the head wasn't equal to NULL, that means there is a node refers with the head
    // so, we have to go through all the nodes to find out the last node whose next is NULL
    {
        temp = head;               // we refers temp to the head
        while (temp->next != NULL) // Make a loop to find the last Node
        {
            temp = temp->next; // Make temp pass through each node and take its next node ,
            // until while loop stop whene the next equal NULL
        }
        temp->next = newNode; // Here we set the next of Last node to equal the
        // new node that becomes last node
        newNode->prev = temp; // set the prev of last node to equal the node before it ,
        // (temp stopped it node which was the last node )
        newNode->next = NULL; // set the next of the nwe node to NULL
    }
}

void display() // A funcation to show node functions and their values
{
    Node *temp = head;                               // we start from the head
    if (head == NULL)                                // make conditional if the head is NULL, thats means no Node
        cout << "The linked list is empty " << endl; // print text that the linked list is empty

    else // if the head wasn't equal to NULL, that means there is a node refers with the head and other
    //  nodes connected with each other so, we have to go through all the nodes and print its data which equle
    //  to (value) until find out the last node which next is NULL and print its valus than while loop stopped
    {
        while (temp != NULL)
        {
            cout << temp->data << " "; // print the data of the current node
            temp = temp->next;         // move to the next node by refers with the next of the nodes
        }
    }
    cout << endl;
}

void insertNodeAtTheBeginning(int value) // insert a node at the beginning
{

    Node *new_Node = new Node(); // make new node
    Node *temp;                  // make pointer to save ID of second node also the next and prev of the node
    new_Node->data = value;      // set data to equal the value that will be insert
    new_Node->prev = NULL;       // set prev of new node to equle NULL , becouse first node has always
    // NULL prev
    if (head == NULL) // set condation if head equle Null , we can refers the head with new node
    {
        head = new_Node;       // refers the head with new node
        new_Node->next = NULL; // set next node to Null
    }
    else
    {
        temp = head;           // set the temp refers with head to save information of second node (next , prev)
        head = new_Node;       // refers the head with new node
        new_Node->next = temp; // refers the next of new node with the temp (ID of second node)
        temp->prev = new_Node; // refers the prev of second node with ID of node before it ( first/new node)
    }
}
void displayrevers() // function to display revers of the Nodes
{

    Node *temp = head; // creat a variable for discovering the last node
    if (head == NULL)  // set condation if head equal to Null , print text (there is not node to reverse)
    {
        cout << "there is not node to reverse " << endl; // print text (there is not node to reverse)
    }
    else
    {
        while (temp->next != NULL) // we put a loop here to let temp discover the the last node
        {
            temp = temp->next; // moving next to each node until the last node (next = NULL)
        }
        while (temp != NULL) // while the compiler arrived here, thats mean we are in the last node
        {
            cout << temp->data << " "; // here we print the data value
            temp = temp->prev;         // and go back by prev and when it equal to Null we will know that we reached the
            // first node and the loop will stop
        }
    }
}

void deleteFirstNode() // Funcation to delete the first node
{
    if (head != NULL)
    {
        Node *temp = head; // make pointer to dael with the first node that we want to delete
        head = head->next; // set the head to take the pionter of next node we want to delete
        head->prev = NULL; // set the prev of head (new first node) to be Null
        temp->next = NULL; // set the next of temp(old first node that we deleted) NULL , make it
        // swims in the space of memory
        delete (temp); // funcation to delete the node
    }
    else
    {
        cout << "The linked list is empty !" << endl; // no need to explanation (:
    }
}

void deleteLastNode() // Funcation to delete the last node
{
    if (head != NULL)
    {
        Node *temp = head; // creat a variable for discovering the last node

        while (temp->next != NULL) // we put a loop here to let temp discover the the last node
        {
            temp = temp->next; // moving next to each node until the last node (next = NULL)
        }
        Node *cur = temp->prev; // make new Pointer to deals with before last Node
        cur->next = NULL;       // make next of new last node NULL
        temp->prev = NULL;      // make prev of old last node NULL , let her swims in the space of the memory
        free(temp);             // funcation to delete the node
    }
}

int main()
{

    cout << "The orginal linked list" << endl;
    insertNode(10);
    insertNode(20);
    insertNode(30);
    display();
    cout << "\nLinked list after insert node at th beginning" << endl;
    insertNodeAtTheBeginning(5);
    display();
    cout << "\nLinked list after deleteing first node" << endl;
    deleteFirstNode();
    display();
    cout << "\nLinked list after delete the last node" << endl;
    deleteLastNode();
    display();
    cout << "\nLinked list after reverse" << endl;
    displayrevers();

    return 0;
}
