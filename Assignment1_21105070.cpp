// name = Dhruv agrawal
// Sid = 21105070
// branch = ECE
// Assignment n0. = 1
// Family linked list

//***************************************************************************************************************************************************//

#include <iostream>
using namespace std;

class Node
{
public:
    // Creating class objects
    string name;
    int age;
    Node *next;
    Node *prev;

    Node(string name, int age)
    {
        this->name = name;
        this->age = age;
        next = NULL;
        prev = NULL;
    }
};

// function to insert data at the end of the linked list
void append(Node *&head, string name, int age)
{
    Node *temp = head;
    Node *new_node = new Node(name, age);
    // inserting node in empty list
    if (temp == NULL)
    {
        head = new_node;
    }
    // inserting node in non-empty list
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// function to insert data at the start of the linked list
void insert_at_head(Node *&head, string name, int age)
{
    Node *new_node = new Node(name, age);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}

// function to display data from start of the linked list
void display_from_start(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "[Name:" << temp->name << " Age:" << temp->age << "]"
             << "<=>";
        temp = temp->next;
    }
    cout << endl;
}

// function to display data from end of the linked list
void display_from_end(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << "[Name:" << temp->name << " Age:" << temp->age << "]"
             << "<=>";
        temp = temp->prev;
    }
    cout << endl;
}

// function to delete any index(0,n-1)
void delete_ind(Node *&head, int i)
{
    if (i == 0)
    {
        Node *temp = head;
        head = temp->next;
        head->prev = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        for (int j = 0; j < i; j++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

// function to delete last element
void pop(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

int main()
{
    Node *head = NULL;
    int no_of_family_mem;
    cout << "Enter Number Of Family Members:";
    cin >> no_of_family_mem;
    // Inserting family members details in doubly linked list
    for (int i = 1; i <= no_of_family_mem; i++)
    {
        string name;
        int age;
        cout << "Enter Family Member " << i << " Name:";
        cin >> name;
        cout << "Enter Family Member " << i << " Age:";
        cin >> age;
        append(head, name, age);
    }
    cout << endl;
    cout << "Doubly Linked list with my family members as elements is shown below:" << endl;
    cout << endl;
    display_from_start(head);
}

/*
BONUS QUESTION
Ans= This can be done by sorting the doubly linked list in decending order according to age, by doing so we will get a doubly linked list in which older generation people will be closer to head in double linked list and new generation people will be closer to tail in doubly linked list.
*/