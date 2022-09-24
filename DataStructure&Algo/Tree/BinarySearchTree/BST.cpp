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

void inOrder(treeNode *root, string &check) // Left Root Right
{
    if(root == NULL)
        return;
    inOrder(root->leftChild, check);
    check += (to_string(root->data)+" ");
    inOrder(root->rightChild, check);
}

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

treeNode* searchBST(treeNode * root, int value)
{
    if(root == NULL)
        return NULL;

    if(root->data == value)
    {
        cout << root->data;
        return root;
    }
    else if(value < root->data)
    {
        cout << root->data << " -> ";
        searchBST(root->leftChild, value);
    }
    else 
    {
        cout << root->data << " -> ";
        searchBST(root->rightChild, value);
    }
}

treeNode* inOrderSuccessor(treeNode* root)
{
    treeNode* curr = root;
    while(curr->leftChild != NULL)
        curr = curr->leftChild;
    return curr;
}

treeNode* deletionBST(treeNode* root, int value)
{
    if(value < root->data)
        root->leftChild = deletionBST(root->leftChild, value);
    else if(value > root->data)
        root->rightChild = deletionBST(root->rightChild, value);
    else
    {
        // Implementation of 3 case 
        if(root->leftChild == NULL)
        {
            // Case 1
            treeNode* temp = root->rightChild;
            free(root);
            return temp;
        }
        else if(root->rightChild==NULL)
        {
            // Case 2
            treeNode* temp = root->leftChild;
            free(root);
            return temp;
        }
        else 
        {
            // Case 3
            treeNode* temp = inOrderSuccessor(root->rightChild);
            root->data = temp->data;
            root->rightChild = (deletionBST(root->rightChild, temp->data));
        }

        return root;
    }
}

void spacePrint(int level)
{
    for(int i=0; i<level; i++)
        cout << "   ";
}

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

int main()
{
    int n;
    cin >> n;
    treeNode* root = NULL;
    for(int i=0; i<n; i++)
    {
        int value;
        cin >> value;
        root = insertionBST(root, value);
    }
    string traversal = "";
    inOrder(root, traversal);
    cout << traversal << endl;

    printTree(root, 0);

    int key;
    cout << "Enter value for search: ";
    cin >> key;
    if(searchBST(root, key) == NULL)
        cout << endl << "Value does not exits in the BST!!!" ;
    else
        cout << endl << "Value exits in the BST!!!";
    cout << endl << endl;

    cout << "Enter value for deletion: ";
    cin >> key;
    root = deletionBST(root, key);
    string afterDelete = "";
    inOrder(root, afterDelete);
    cout << afterDelete << endl;
    printTree(root, 0);
    int value;
        cin >> value;
        root = insertionBST(root, value);
        afterDelete = "";
    inOrder(root, afterDelete);
    cout << afterDelete << endl;
        printTree(root, 0);
        cout << "Enter value for deletion: ";
    cin >> key;
    root = deletionBST(root, key);
    afterDelete = "";
    inOrder(root, afterDelete);
    cout << afterDelete << endl;
    printTree(root, 0);

    return 0;
}
/*
9
11 5 9 43 34 1 2 7 21

11
10 40 20 8 99 16 15 17 11 14 1

13
7 5 12 3 6 9 15 1 4 8 10 13 17
*/ 