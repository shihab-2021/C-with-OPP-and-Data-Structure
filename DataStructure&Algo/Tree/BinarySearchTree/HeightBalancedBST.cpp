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

treeNode *insert_bst(int l, int r, int a[])
{
    if(l > r) return NULL;
    int mid = l+(r-l)/2;
    treeNode *newNode = new treeNode(a[mid]);
    newNode->leftChild = insert_bst(l, mid-1, a);
    newNode->rightChild = insert_bst(mid+1, r, a);
    return newNode;
}

void level_order(treeNode *root)
{
    queue<treeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        treeNode *parent = q.front();
        q.pop();
        cout << parent->data << " ";
        if(parent->leftChild != NULL)
            q.push(parent->leftChild);
        if(parent->rightChild != NULL)
            q.push(parent->rightChild);
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    treeNode *root = NULL;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    root = insert_bst(0, n-1, a);
    level_order(root);
    return 0;
    
}