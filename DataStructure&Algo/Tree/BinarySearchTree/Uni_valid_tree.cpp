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
 
bool is_unival(treeNode *root)
{
    if(root==NULL)
        return false;
    int level = 0;
    queue<treeNode*> q;
    q.push(root);
    q.push(NULL);
    int mainValue = root->data;
 
    while (!q.empty())
    {
        treeNode *checkNode = q.front();
        q.pop();
        if(checkNode != NULL)
        {
            if(checkNode->data!=mainValue)
                return false;
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
    return true;
}
 
int main()
{
    int a;
    cin >> a;
    treeNode *root  = new treeNode(a);
    queue<treeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        treeNode *presentRoot = q.front();
        q.pop();
        int x, y;
        cin >> x >> y;
        treeNode *n1 = NULL;
        treeNode *n2 = NULL;
        if(x!=-1)
            n1 = new treeNode(x);
        if(y!=-1)
            n2 = new treeNode(y);
        presentRoot->leftChild = n1;
        presentRoot->rightChild = n2;
 
        if(n1!=NULL)
            q.push(n1);
        if(n2!=NULL)
            q.push(n2);
    }
 
    bool check = is_unival(root);
    if(check)
        cout << "This is an uni-valued tree." << endl;
    else
        cout << "This is not an uni-valued tree." << endl;
   
    return 0;
}
 
/*
Test 1:
1        
1 1
1 1 -1 1
-1 -1 -1 -1 -1 -1
Output: This is an uni-valued tree.
 
Test 2:
2
2 2
5 2 -1 -1
-1 -1 -1 -1
Output: This is not an uni-valued tree.
*/
