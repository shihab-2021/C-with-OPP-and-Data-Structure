#include<bits/stdc++.h>
using namespace std;

template <typename N> class Node
{
public:
    N value;
    Node *next;
    Node *prev;

    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
}; 

template <typename S> class Stack
{
    Node <S> *head;
    Node <S> *Top;
    int count = 0;
public:
    Stack()
    {
        head = NULL;
        Top = NULL;
    }
    // PUSH
    void push(S val)
    {
        Node <S> *newNode = new Node <S> (val);
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
    S pop()
    {
        Node <S> *delNode;
        delNode = Top;
        S check;
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
    S top()
    {
        if(Top == NULL)
            cout << "There is not value in the stack!!!" << endl << endl;
        else 
            return Top->value;  
    }
};
