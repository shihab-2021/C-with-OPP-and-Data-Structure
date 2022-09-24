#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int value;
        Node *next, *previous;
    Node(int val)
    {
        value = val;
        previous = NULL;
        next = NULL;
    }
};

void displayFromHead(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if(n->next != NULL)
            cout << " -> ";
        n = n->next;
    }
    cout << endl << endl;
}

void displayFromTail(Node *n)
{
    while (n->next != NULL)
    {
        n = n->next;
    }
    while (n != NULL)
    {
        cout << n->value;
        if(n->previous != NULL)
            cout << " -> ";
        n = n->previous;
    }
    cout << endl << endl;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
}

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->previous = temp;
}

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int searchValueUniqueList(Node *head, int key)
{
    if(head == NULL)
        return -1;
    Node *temp = head;
    int count = 1;
    while (temp->value != key)
    {
        if(temp->next == NULL)
            return -1;
        temp =  temp->next;
        count++;    
    }
    return count;
}

void searchValueDuplicateEnableList(Node *&head, int key)
{
    int size = countLength(head);
    Node *temp = head;
    int position[size+1], k=1, count=1, flag=0;
    while (temp != NULL)
    {
        if(temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        count++;
        temp = temp->next;
    }
    if(flag == 0)
        cout << "The searched value is not yet in the list!!!" << endl;
    else
    {
        position[0] = k;
        cout << "The value is found at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if(i < position[0]-1)
                cout<< ", ";
        }
        cout << endl << endl;
    }
}

struct Test
{
    int position[1000];
};

Test searchValueDuplicateEnableListReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k=1, count=1;
    while(temp != NULL)
    {
        if(temp->value == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->next;
        count++;
    }
    T.position[0] = k;
    return T;
}

void insertAtSpecificPosition(Node *&head, int pos, int val)
{
    int size = countLength(head);
    if(pos > size)
    {
        if(pos == size+1)
        {
            insertAtTail(head, val);
            return;
        }
        cout << "Given position is not valid!!!" << endl << endl;
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int i=1;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    newNode->previous = temp;
    temp->next = newNode;
    temp = temp->next->next;
    temp->previous = newNode;
}

void insertValueDuplicateEnableList(Node *&head, int searchValue, int value)
{
    int count = 1;
    Test T;
    T = searchValueDuplicateEnableListReturn(head, searchValue);
    if(T.position[0] == 1)
        cout << "The searched value is not in the list yet!!!" << endl;
    else
    {
        int size = T.position[0];
        for (int i = 1; i < size; i++)
        {
            insertAtSpecificPosition(head, T.position[i]+count, value);
            count++;
        }
    }
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if(temp != NULL)
    {
        head = temp->next;
        head->previous = NULL;
        delete temp;
    }
    else 
        cout << "There is no value in the linked list!!!" << endl << endl;
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
}

int main()
{
    Node *head = new Node(0);
    Node *one = new Node(1);
    Node *two = new Node(2);
    head->next = one;
    one->next = two;
    one->previous = head;
    two->previous = one;
    insertAtTail(head, 4);
    insertAtTail(head, 2);
    displayFromHead(head);
    // insertAtSpecificPosition(head, 4, 3);
    // insertAtSpecificPosition(head, 5, 4);
    insertValueDuplicateEnableList(head, 2, 2);
    // searchValueDuplicateEnableList(head, 4);
    // cout << countLength(head) << endl << endl;
    displayFromHead(head);
    displayFromTail(head);

    return 0;
}