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

void preOrder(treeNode *root, string &check) // Root Left Right
{
    if(root == NULL)
        return;
    check += to_string(root->data);
    preOrder(root->leftChild, check);
    preOrder(root->rightChild, check);
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

void printLeaves(treeNode *root)
{
    if(root==NULL)
        return;
    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << " ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void printLeftNonLeaves(treeNode *root)
{
    if(root==NULL)
        return;
    if(root->leftChild!=NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
    else if(root->rightChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
}

void printRightNonLeaves(treeNode *root)
{
    if(root==NULL)
        return;
    if(root->rightChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
    else if(root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
}

void boundaryTraversal(treeNode *root)
{
    if(root==NULL)
        return;
    cout << root->data << " ";
    // LB Non-Leaves
    printLeftNonLeaves(root->leftChild);
    // LB Leaves
    printLeaves(root->leftChild);
    // RB Leaves
    printLeaves(root->rightChild);
    // RB Non-Leaves
    printRightNonLeaves(root->rightChild);
}

int main()
{
    int n;
    cin >> n;
    treeNode *allNodes[n];
    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }
    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;
        allNodes[i]->data = value;
        if(left>n-1 || right>n-1)
        {
            cout << "Invalid Index" << endl;
            break; 
        }
        if(left != -1)
            allNodes[i]->leftChild = allNodes[left];
        if(right != -1)
            allNodes[i]->rightChild = allNodes[right];
    }
    printTree(allNodes[0],  0);

    string inOrderTraversal = "";
    inOrder(allNodes[0], inOrderTraversal);
    cout << "In order Traversal: " << inOrderTraversal << endl;
    string preOrderTraversal = "";
    preOrder(allNodes[0], preOrderTraversal);
    cout << "Pre order Traversal: " << preOrderTraversal << endl;
    string postOrderTraversal = "";
    postOrder(allNodes[0], postOrderTraversal);
    cout << "Post order Traversal: " << postOrderTraversal << endl;
    
    string levelOrderTraversal = "";
    int maxValueAtk = levelOrder(allNodes[0], levelOrderTraversal, 2);
    cout << "Level Order Traversal: " << levelOrderTraversal << endl;
    cout << endl << maxValueAtk << endl;

    boundaryTraversal(allNodes[0]);

    cout << "level: " ; 
    printLeaves(allNodes[0]);
    
    return 0;
}

/*
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
Pre order Traversal: 013425786
Post order Traversal: 341785620
*/