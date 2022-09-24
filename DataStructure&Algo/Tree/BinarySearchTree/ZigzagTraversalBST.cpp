#include<bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

treeNode* insertionBST(treeNode* root, int value)
{
    treeNode* newNode = new treeNode(value);
    if(root == NULL)
    {
        root = newNode;
        return root;
    }
    // value < root->data
    if(value < root->data)
        root->leftChild = insertionBST(root->leftChild, value);
    // value > root->data
    else if(value > root->data)
        root->rightChild = insertionBST(root->rightChild, value);
    
    return root;
}

void inOrder(treeNode *root, string &check) // Left Root Right
{
    if(root == NULL)
        return;
    inOrder(root->leftChild, check);
    check += (to_string(root->data)+" ");
    inOrder(root->rightChild, check);
}

void zigzagTraversal(treeNode* root)
{
    stack<treeNode*> currentLevel;
    stack<treeNode*> nextLevel;
    bool leftToRight = true;
    currentLevel.push(root);

    while (!currentLevel.empty())
    {
        treeNode* x = currentLevel.top();
        currentLevel.pop();
        cout << x->data << " ";
        if(leftToRight)
        {
            if(x->leftChild)
                nextLevel.push(x->leftChild);
            if(x->rightChild)
                nextLevel.push(x->rightChild);
        }
        else 
        {
            if(x->rightChild)
                nextLevel.push(x->rightChild);
            if(x->leftChild)
                nextLevel.push(x->leftChild);
        }
        if(currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
    
}

int main()
{
    int n;
    cin >> n;
    treeNode* root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insertionBST(root, value);
    }
    string traversal = "";
    inOrder(root, traversal);
    cout << traversal << endl;
    zigzagTraversal(root);
    
    return 0;
}
/*
10
11 5 9 43 34 1 2 7 8 21
*/ 