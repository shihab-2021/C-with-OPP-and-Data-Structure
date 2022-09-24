#include<bits/stdc++.h>
using namespace std;

class Priority_Queue
{
private:
    vector<int> v;
    int leftChild(int i)
    {
        return (i*2)+1;
    }
    int rightChild(int i)
    {
        return (i*2)+2;
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    void heapify(int start)
    {
        int left_index = leftChild(start);
        int right_index = rightChild(start);
        int smallest = start;
        if(left_index < v.size() && v[left_index] < v[smallest])
            smallest = left_index;
        if(right_index < v.size() && v[right_index] < v[smallest])
            smallest = right_index;
        swap(v[start], v[smallest]);
        if(smallest != start)
            heapify(smallest);
    }
public:
    void Push(int val)
    {
        v.push_back(val);
        int pos = v.size()-1;
        while(v[pos] < v[parent(pos)])
        {
            swap(v[pos], v[parent(pos)]);
            pos = parent(pos);
        }
    }
    int Top()
    {
        return v[0];
    }
    void Pop()
    {
        v[0] = v[v.size()-1];
        v.pop_back();
        heapify(0);
    }
    bool Empty()
    {
        return v.size() == 0;
    }
    void printVector()
    {
        cout << endl;
        for(auto i:v)
            cout << i << " ";
        cout << endl << endl;
    }
};

int main()
{
    Priority_Queue pq;
    pq.Push(10);
    pq.Push(40);
    pq.Push(20);
    pq.Push(8);
    pq.Push(99);
    pq.Push(9);
    pq.Push(15);
    pq.Push(17);

    pq.printVector();

    // pq.Pop();
    // pq.printVector();
    // pq.Push(1);
    // pq.printVector();

    while (!pq.Empty())
    {
        int v = pq.Top();
        pq.Pop();
        cout << v << endl;
    }

    return 0;
}