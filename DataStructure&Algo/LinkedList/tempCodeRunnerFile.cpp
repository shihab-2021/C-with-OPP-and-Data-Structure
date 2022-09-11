Node *slow = head;
    Node *fast = head;
    while(fast!=NULL && fast->Next!=NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
        if(slow->Next==fast->Next)
            return true;
    }
    return false;