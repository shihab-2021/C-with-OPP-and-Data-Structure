
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