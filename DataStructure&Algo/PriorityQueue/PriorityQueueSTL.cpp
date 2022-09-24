#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PAIR;

int main()
{
    priority_queue<int, vector<int>> pQ;
    pQ.push(1);
    pQ.push(2);
    pQ.push(3);
    while (!pQ.empty())
    {
        cout << pQ.top() << endl;
        pQ.pop();
    }
    cout << endl;

    // with greater 
    cout << "With greater" << endl;
    priority_queue<int, vector<int>, greater<int>> PQ;
    PQ.push(1);
    PQ.push(2);
    PQ.push(3);
    while (!PQ.empty())
    {
        cout << PQ.top() << endl;
        PQ.pop();
    }
    cout << endl;

    // with pair
    cout << "With pair " << endl;
    priority_queue<PAIR, vector<PAIR>> pq;
    pq.push(make_pair(1, 4));
    pq.push(make_pair(2, 5));
    pq.push(make_pair(3, 6));
    while (!pq.empty())
    {
        cout << pq.top().first << " | " << pq.top().second << endl;
        pq.pop();
    }
    cout << endl;

    // with pair & greater 
    cout << "With pair & greater " << endl;
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> Pq;
    Pq.push(make_pair(1, 4));
    Pq.push(make_pair(2, 5));
    Pq.push(make_pair(3, 6));
    while (!Pq.empty())
    {
        cout << Pq.top().first << " | " << Pq.top().second << endl;
        Pq.pop();
    }
    cout << endl;

    return 0;
}