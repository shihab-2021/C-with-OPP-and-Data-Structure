#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

class Stack
{
    Node *head;
    Node *Top;
    int count = 0;
public:
    // PUSH
    void push(int val)
    {
        Node *newNode = new Node(val);
        if(head == NULL)
        {
            head = Top = newNode;
            count++;
            return;
        }
        Top->next = newNode;
        newNode->prev = Top;
        Top = newNode;
        count++;
    }
    // POP
    int pop()
    {
        Node *delNode;
        delNode = Top;
        int check = -1;
        if(head == NULL)
        {
            cout << "Stack Underflow!!!" << endl << endl;
            return check;
        }
        if(Top == head)
            head = Top = NULL;
        else
        {
            Top = delNode->prev;
            Top->next = NULL;
        }
        check = delNode->value;
        delete delNode;
        count--;
        return check;
    }
    // EMPTY
    bool empty()
    {
        if(head == NULL)
            return true;
        else 
            return false;
    }
    // SIZE
    int size()
    {
        return count;
    }
    // TOP
    int top()
    {
        if(Top == NULL)
            cout << "There is not value in the stack!!!" << endl << endl;
        else 
            return Top->value;  
    }
};
