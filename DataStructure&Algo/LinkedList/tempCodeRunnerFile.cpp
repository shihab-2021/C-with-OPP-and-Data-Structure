else 
    {
        int size = T.position[0];
        for (int  i = 1; i < size; i++)
        {
            deletionAtSpecificPosition(head, T.position[i]-count);
            count++;
        }
        
    }