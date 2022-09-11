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

void printTree(treeNode *root, int level);
void spacePrint(int level);

void printTree(treeNode *root, int level)
{
    if(root == NULL)
        return;
    if(root->leftChild == NULL && root->rightChild == NULL) // CASE 1
    {
        cout << root->data << endl;
        return; 
    }
    else  // CASE 2
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if(root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level+1);
    }

    if(root->rightChild !=NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level+1);
    }

}

void spacePrint(int level)
{
    for(int i=0; i<level; i++)
        cout << "   ";
}

void inOrder(treeNode *root, string &check) // Left Root Right
{
    if(root == NULL)
        return;
    inOrder(root->leftChild, check);
    check += to_string(root->data);
    inOrder(root->rightChild, check);
}

void preOrderTraversal(treeNode *root, string &check) // Root Left Right
{
    if(root == NULL)
        return;
    check += to_string(root->data);
    preOrderTraversal(root->leftChild, check);
    preOrderTraversal(root->rightChild, check);
}
void postOrder(treeNode *root, string &check) // Left Right Root
{
    if(root == NULL)
        return;
    postOrder(root->leftChild, check);
    postOrder(root->rightChild, check);
    check += to_string(root->data);
}

int levelOrder(treeNode *root, string &check, int k)
{
    if(root==NULL)
        return -1;
    int level = 0;
    queue<treeNode*> q;
    q.push(root);
    q.push(NULL);
    int max = -9999;

    while (!q.empty())
    {
        treeNode *checkNode = q.front();
        q.pop();
        if(checkNode != NULL)
        {
            if(level==k)
                if(max<checkNode->data)
                    max = checkNode->data;

            cout << checkNode->data << " ";
            check += to_string(checkNode->data);
            if(checkNode->leftChild != NULL)
                q.push(checkNode->leftChild);        
            if(checkNode->rightChild != NULL)
                q.push(checkNode->rightChild);        
        }
        else
            if(!q.empty())
            {
                q.push(NULL);
                level++;
            }
    }
    return max;
}

int searchInOrder(int inOrder[], int current, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if(inOrder[i]==current)
            return i;
    }
    return -1;
}

treeNode *buildTreePreIn(int preOrder[], int inOrder[], int start, int end)
{
    static int id = 0;
    int current = preOrder[id];
    id++;
    treeNode *newNode = new treeNode(current);
    if(start==end)
        return newNode;

    int pos = searchInOrder(inOrder, current, start, end);

    newNode->leftChild = buildTreePreIn(preOrder, inOrder, start, pos-1);
    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos+1, end);

    return newNode;
}

int main()
{
    int n;
    cin >> n;
    int preOrder[n], inOrder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> inOrder[i];
    }

    treeNode *root = buildTreePreIn(preOrder, inOrder, 0, n-1);
    string checkPre = "";
    preOrderTraversal(root, checkPre);
    cout << checkPre << endl << endl;
    
    return 0;
}

/*
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

Root: 0
Left: 
   Root: 1
   Left: 3
   Right: 4
Right: 
   Root: 2
   Left: 
      Root: 5
      Left: 7
      Right: 8
   Right: 6

In order Traversal: 314075826
Pre order Traversal: 314075826
Post order Traversal: 314075826
*/