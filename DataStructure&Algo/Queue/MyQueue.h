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

class Queue
{
    Node *front;
    Node *rear;
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // enqueue --> push(val)
    void push(int val)
    {
        Node *newNode = new Node(val);
        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
    }

    // dequeue --> pop()
    int pop()
    {
        int check = -1;
        if(rear == NULL)
        {
            cout << "Queue Underflow | There is no element in the Queue!!!" << endl;
            return check;
        }
        Node *delNode;
        delNode = front;
        front = front->next;
        if(front == NULL)
            rear = NULL;
        check = delNode->value;
        delete delNode;
        return check;
    }

    // peek --> Front() Back()
    int Front()
    {
        int check;
        check = front->value;
        return check;
    }
    int Back()
    {
        int check;
        check = rear->value;
        return check;
    }

    // empty() --> empty()
    bool empty()
    {
        if(front == NULL && rear == NULL)
            return true;
        else 
            return false;
    }
};