#include<bits/stdc++.h>
using namespace std;

class Node
{
    public: 
        int value;
        Node *Next;
        
        Node(int val)
        {
            value = val;
            Next = NULL;
        }
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp-> Next != NULL)
        temp = temp->Next;
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

void display(Node *n)
{
    while(n != NULL)
    {
        cout << n->value;
        if(n->Next != NULL)
            cout << " -> ";
        n = n->Next;
    }
    cout << endl << endl;
}
void printReverse(Node* head)
{
    // Base case
    if (head == NULL)
    return;
 
    // print the list after head node
    printReverse(head->Next);
 
    // After everything else is printed, print head
    cout << head->value << " ";
}
void reversedListPrint(Node *head) {
    if (head != NULL) {
        reversedListPrint(head->Next);
        if(head->Next != NULL)
            cout << " -> ";
        cout << head->value ;
    }
}

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
    return count;
}

void insertionAtSpecificPosition(Node *&head,int pos, int val)
{
    int i = 0;
    Node *temp = head;
    while (i < pos-2)
    {
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if(temp == NULL)
        return -1;
    while(temp->value != key)
    {
        if(temp->Next == NULL)
            return -1;
        temp = temp->Next;
        count++;
    }
    return count;
}

void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countLength(head);
    int position[size+1], k=1;
    int count = 1;
    int flag = 0;
    while (temp != NULL)
    {
        if(temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    cout << endl;
    if(flag==0)
        cout << "The searched value is not yet in the list" << endl;
    else 
    {
        position[0] = k;
        cout << " The value is found at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if(i<position[0]-1)
                cout << ", ";
        }
        cout << endl;
    }
}

struct Test
{
    int position[1000];
};

Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k=1;
    int count = 1;
    while (temp != NULL)
    {
        if(temp->value == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;
    return T;
}

void searchByValueUnique(Node *&head, int searchValue, int value)
{
    // Step 1: Search the position of the searchValue
    int position;
    position = searchByValueUnique(head, searchValue);
    // Step 2: Insert the value at the position+1
    insertionAtSpecificPosition(head, position+1, value);
}

void insertByValueDuplicate(Node *&head, int searchValue, int value)
{
    int count=1;
    Test T;
    T = searchByValueDuplicateReturn(head, searchValue);
    if(T.position[0] == 1)
        cout << "The searched value is not in the list yet.." << endl;
    else
    {
        int size = T.position[0];
        cout << "The value is found at position: ";
        for (int i = 1; i < size; i++)
        {
            insertionAtSpecificPosition(head, T.position[i]+count, value);
            count++;
        }
    }
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if(temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else 
        cout << "There is no value in the linked list" << endl;
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if(temp != NULL && temp->Next != NULL)
    {
        while(temp->Next->Next != NULL)
            temp = temp->Next;
        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else if(temp != NULL && temp->Next == NULL)
        deletionAtHead(head);
    else 
        cout << "There is no value in the linked list" << endl;
}

void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    if(position <= countLength(head))
    {
        if(position == 1)
            deletionAtHead(head);
        else if(position == countLength(head))
            deletionAtTail(head);
        else
        {
            int i = 1;
            while(i<position-1)
                temp = temp->Next;
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        cout << "Position out of bound" << endl;
    }
}

void deletionByValueUnique(Node *&head, int value)
{
    int position;
    position = searchByValueUnique(head, value);
    if(position == -1)
        cout << "Value not found in the linked list" << endl;
    else
        deletionAtSpecificPosition(head, position);
}

Node *reverseNonRecursive(Node *&head)
{
    if(head == NULL)
    {
        cout << "The list is empty!!!" << endl << endl;
        return head;
    }
    Node *prev = NULL;
    Node *current = head;
    Node *next = head->Next;
    while(true)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if(current == NULL)
            break;
        next = next->Next;
    }
    return prev;
}

Node *reverseRecursive(Node *&head)
{
    if(head->Next == NULL)
        return head;
    Node *newHead = reverseRecursive(head->Next);
    head->Next->Next = head;
    head->Next = NULL;
    return newHead;
}

int findMid(Node *&head)
{
    if(head == NULL)
        return -1;;
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    return slow->value;
}

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;
    int count = 1;
    while(temp->Next != NULL)
    {
        if(count == pos) 
            startNode = temp;
        temp = temp->Next;
        count++;
    }
    temp->Next = startNode;
}

bool detectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL && fast->Next!=NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
        if(slow->Next==fast->Next)
            return true;
    }
    return false;
}

void removeCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    do{
        slow = slow->Next;
        fast = fast->Next->Next;
    }while(slow!=fast);
    fast = head;
    while(fast->Next != slow->Next)
    {
        slow = slow->Next;
        fast = fast->Next;
    }
    slow->Next = NULL;
}

int main()
{
    Node *head = NULL;
    int value, position;
    cout << "Choice 1: Insertion at head." << endl
            << "Choice 2: Insertion at tail." << endl
            << "Choice 3: Insertion at specific position." << endl
            << "Choice 4: Search a value (Unique List)" << endl
            << "Choice 5: Search a value (Duplication enable List)" << endl
            << "Choice 6: Insertion after a specific value (Unique List)" << endl
            << "Choice 7: Insertion after a specific value (Duplication enable List)" << endl
            << "Choice 8: Deletion at head" << endl
            << "Choice 9: Deletion at tail" << endl
            << "Choice 10: Deletion at a specific position" << endl
            << "Choice 11: Deletion by value (Unique List)" << endl
            << "Choice 12: Reversal of list Non-recursive" << endl
            << "Choice 13: Reversal of list non-recursive" << endl
            << "Choice 14: Finding the mid (Slow-Fast Pointer Method)" << endl
            << "Choice 15: Make a cycle at K position" << endl
            << "Choice 16: Detect cycle in the list" << endl
            << "Choice 0: Exit" << endl;
    
    cout << "Your choice: ";
    int choice;
    cin >> choice;
    while (choice!=0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the Desired position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertionAtSpecificPosition(head, position, value);
            break;
        case 4:
            cout << "Enter the value to search: ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if(position != -1)
                cout << "The number is at position " << position << endl;
            else    
                cout << "The number is not yet in the list" << endl;
            break;
        case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if(T.position[0] == 1)
                cout << "The searched value is not in the list yet.." << endl;
            else
            {
                int size = T.position[0];
                cout << "The value is found at position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if(i<size-1)
                        cout << ", ";
                }
                cout << endl;
            }
            break;
        case 6: 
            cout << "Enter the value to search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            searchByValueUnique(head, searchValue, value);
            break;
        case 7: 
            cout << "Enter the value to search: ";
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertByValueDuplicate(head, searchValue, value);
            break;
        case 8:
            deletionAtHead(head);
            break;
        case 9:
            deletionAtTail(head);
            break;
        case 10:
            if(head == NULL)
            {
                cout << "There is no value in the linked list" << endl;
                break;
            }
            cout << "Enter the desired position: ";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            break;
        case 11:
            cout << "Enter the value of delete: ";
            int delValue;
            cin >> delValue;
            deletionByValueUnique(head, delValue);
            break;
        case 12:
            head = reverseNonRecursive(head);
            break;
        case 13:
            if(head == NULL)
            {
                cout << "The list is empty!!!" << endl << endl;
                break;
            }
            head = reverseRecursive(head);
            break;
        case 14:
            int mid;
            mid = findMid(head);
            if(mid == -1)
                cout << "The linked list is empty!!!" << endl << endl;
            else 
                cout << "Mid value is " << mid << endl << endl;
        case 15:
            cout << "Enter the desired position to create cycle: ";
            cin >> position;
            makeCycle(head, position);
            break;
        case 16:
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if(cycleStatus==true)
                cout << "There is a cycle in the list." << endl << endl;
            else
                cout << "There is no cycle in the list!!!" << endl << endl;
            break;
        case 17:
            cycleStatus = detectCycle(head);
            if(cycleStatus == true)
                removeCycle(head);
            else   
                cout << "There is no cycle in the list!!!" << endl << endl;
            break;
        default:
            break;
        }
        cout << "Your next choice: ";
        cin >> choice;
    }
    display(head);
    printReverse(head);
    cout << endl;
    reversedListPrint(head);
    cout << endl;
    cout << countLength(head) << endl;
    return 0;
}
