#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int value;
        Node *next;

        Node(int val)
        {
            value = val;
            next = NULL;
        }
};

void display(Node *n)
{
    if(n == NULL)
        cout << "The linked list is empty!!!" << endl;
    else 
    {
        cout << "The desired linked list is: ";
        while(n != NULL)
        {
            cout << n->value;
            if(n->next != NULL)
                cout << " -> ";
            n = n->next;
        }
        cout << endl << endl;
        }
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

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtSpecificPosition(Node *&head, int pos, int val)
{
    if(pos == 1)
    {
        insertAtHead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    int i = 0;
    Node *temp = head;
    while (i < pos-2)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int searchValueFromUniqueList(Node *&head, int key)
{
    int count = 1;
    Node *temp = head;
    while(temp->value != key)
    {
        if(temp->next == NULL)
            return -1;
        temp = temp->next;
        count++;
    }
    return count;
}

void searchValueFromDuplicationEnableList(Node *&head, int key)
{
    int size = countLength(head);
    int position[size+1], k=1, flag=0, count=1;
    Node *temp = head;
    while (temp != NULL)
    {
        if(temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->next;
        count++;
    }
    if(flag == 0)
        cout << "The search value is not yet in the list!!!" << endl << endl;
    else
    {
        position[0] = k;
        cout << "The value is found at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if(i < position[0]-1)
                cout << ", ";
        }
        cout << endl << endl;
    }
}

struct Test
{
    int position[1000];
};

Test searchValueFromDuplicationEnableListReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;
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

void insertAfterSpecificUniqueValue(Node *&head, int searchValue, int value)
{
    int position;
    position = searchValueFromUniqueList(head, searchValue);
    insertAtSpecificPosition(head, position+1, value);
}

void insertAfterSpecificDuplicateValue(Node *&head, int searchValue, int value)
{
    int count = 1;
    Test T;
    T = searchValueFromDuplicationEnableListReturn(head, searchValue);
    if(T.position[0] == 1)
        cout << "The searched value is not in the list yet!!!" << endl << endl;
    else 
    {
        int size = T.position[0];
        for (int  i = 1; i < size; i++)
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
        head = head->next;
        delete temp;
    }
    else 
        cout << "There is no value in the linked list!!!" << endl << endl;
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if(temp != NULL && temp->next != NULL)
    {
        while (temp->next->next != NULL)
            temp = temp->next;
        Node *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    else if(temp != NULL && temp->next == NULL)
        deletionAtHead(head);
    else 
        cout << "There is no value in the linked list!!!" << endl << endl;
}

void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    int size = countLength(head);
    if(position <= size)
    {
        if(position == 1)
            deletionAtHead(head);
        else if(position == size)
            deletionAtTail(head);
        else 
        {
            int i = 2;
            while(i<position)
            {
                temp = temp->next;
                i++;
            }
            Node *delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }
    else 
        cout << "Position out of bound!!!" << endl << endl;
}

void deletionByValueUniqueList(Node *&head, int value)
{
    int position = searchValueFromUniqueList(head, value);
    if(position == -1)
        cout << "Value not found in the linked list!!!" << endl << endl;
    else    
        deletionAtSpecificPosition(head, position);
}

void deletionByValueDuplicateAbleList(Node *&head, int value)
{
    int count = 0;
    Test T;
    T = searchValueFromDuplicationEnableListReturn(head, value);
    if(T.position[0] == 1)
        cout << "The searched value is not in the list yet!!!" << endl << endl;
    else 
    {
        int size = T.position[0];
        for (int  i = 1; i < size; i++)
        {
            deletionAtSpecificPosition(head, T.position[i]-count);
            count++;
        }
        
    }
}

int main()
{
    Node *head = NULL;
    int value, position;
    cout << "Choice 1: Display the list" << endl
            << "Choice 2: Count the length of linked list" << endl
            << "Choice 3: Insert at head" << endl
            << "Choice 4: Insert at tail" << endl
            << "Choice 5: Insert at specific position" << endl
            << "Choice 6: Search a value (Unique List)" << endl
            << "Choice 7: Search a value (Duplication Enable List)" << endl
            << "Choice 8: Insert after a specific value (Unique List)" << endl
            << "Choice 9: Insert after a specific value (Duplication Enable List)" << endl
            << "Choice 10: Deletion  at head" << endl
            << "Choice 11: Deletion at tail" << endl
            << "Choice 12: Deletion at a specific position" << endl
            << "Choice 13: Deletion by value (Unique List)" << endl
            << "Choice 14: Deletion by value (Duplication Enable List)" << endl
            << "Choice 0: Exit" << endl;

    cout << "Your choice: " ;
    int choice;
    cin >> choice;
    while (choice != 0)
    {
       switch (choice)
       {
       case 1:
            display(head);
            break;

       case 2:
            cout << "Element number of the linked list: ";
            cout << countLength(head) << endl << endl;
            break;
       
       case 3:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
       
       case 4:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
       
       case 5:
            cout << "Enter the desired position: ";
            cin >> position;
            if(countLength(head)+1 < position)
            {
                cout << "Sorry given position is not valid!!!" << endl << endl;
                break;
            }
            cout << "Enter the value: ";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            display(head);
            break;

       case 6:
            if(head == NULL)
            {
                cout << "The linked list is still empty!!!" << endl << endl;
                break;
            }
            cout << "Enter the value to search: ";
            cin >> value;
            position = searchValueFromUniqueList(head, value);
            if(position != -1)
                cout << "The value is in the position: " << position << endl <<endl;
            else
                cout << "The does not found in this linked list!!!" << endl <<endl;
            break;

       case 7:
            if(head == NULL)
            {
                cout << "The linked list is still empty!!!" << endl << endl;
                break;
            }
            cout << "Enter the value to search: ";
            cin >> value;
            searchValueFromDuplicationEnableList(head, value);
            break;

       case 8:
            cout << "Enter the value of search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertAfterSpecificUniqueValue(head, searchValue, value);
            break;

       case 9:
            cout << "Enter the value of search: ";
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertAfterSpecificDuplicateValue(head, searchValue, value);
            break;

       case 10:
            deletionAtHead(head);
            break;

        case 11:
            deletionAtTail(head);
            break;

        case 12:
            if(head == NULL)
            {
                cout << "There is no value the linked list!!!" << endl << endl;
                break;
            }
            cout << "Enter the desired position: ";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            break;

        case 13:
            cout << "Enter the value of delete: ";
            int delValue;
            cin >> delValue;
            deletionByValueUniqueList(head, delValue);
            break;
        
        case 14:
            cout << "Enter the value of delete: ";
            cin >> delValue;
            deletionByValueDuplicateAbleList(head, delValue);
            break;
       
       default:
        break;
       } 
       cout << "Your next choice: ";
       cin >> choice;
    }
    
    return 0;
}