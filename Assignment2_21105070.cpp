// Name = Dhruv agrawal
// SID = 21105070
// Branch = ECE
// Assignment n0. = 2
// Circular Linked List

//***************************************************************************************************************************************************//

#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *newnode = new node(val);

    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
        return;
    }
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

void insertAtTail(node *&head, int val)
{

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *newnode = new node(val);
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
}

void deleteAtHead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    node *todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

void deletion(node *&head, int pos)
{

    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count = 1;

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void display(node *head)
{

    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    insertAtHead(head, 5);
    display(head);
    deletion(head, 1);
    display(head);
}

/*
   Q2 = Some practical applications of circular linked list.
   Ans = 1.The real life application where the circular linked list is used is our Personal Computers, where multiple applications are running. All the running applications are kept in a circular linked list and the OS gives a fixed time slot to all for running. The Operating System keeps on iterating over the linked list until all the applications are completed.
   2. In multiplayer  games: All the Players are kept in a Circular Linked List and the pointer keeps on moving forward as a player's chance ends.
   3. Those interfaces where continuosly scrolling after last leads to start of the interface.
*/