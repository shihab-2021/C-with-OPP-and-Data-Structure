#include<bits/stdc++.h>
using namespace std;

template <typename N> class Node
{ 
public:
    N value;
    Node *next;
    Node(N val)
    {
        value = val;
        next = NULL;
    }
};

template <typename Q> class Queue
{
    Node <Q> *front;
    Node <Q> *rear;
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // enqueue --> push(val)
    void push(Q val)
    {
        Node <Q> *newNode = new Node <Q> (val);
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
    Q pop()
    {
        Q check;
        if(rear == NULL)
        {
            cout << "Queue Underflow | There is no element in the Queue!!!" << endl;
            return check;
        }
        Node <Q> *delNode;
        delNode = front;
        front = front->next;
        if(front == NULL)
            rear = NULL;
        check = delNode->value;
        delete delNode;
        return check;
    }

    // peek --> Front() Back()
    Q Front()
    {
        Q check;
        check = front->value;
        return check;
    }
    Q Back()
    {
        Q check;
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