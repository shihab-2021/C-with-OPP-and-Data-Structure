#include<bits/stdc++.h>
using namespace std;

vector<int> v[100];
bool visit[100];

void BFS(int source)
{
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int parent = q.front();
        cout << parent << " ";
        q.pop();
        for(int i=0; i<v[parent].size(); i++)
        {
            int children = v[parent][i];
            if(visit[children]==false)
                q.push(children);
        }
        visit[parent] = true;
    }
    
}

void DFS(int source)
{
    cout << source << " ";
    visit[source] = true;
    for(int i=0; i<v[source].size(); i++)
    {
        int children = v[source][i];
        if(visit[children]==false)
            DFS(children);
    }
}

int main()
{
    int node, edge, root;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        if(i==0)
            root = a;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // Just print the vector(only if needed)
    // for (int i = 0; i < node; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < v[i].size(); j++)
    //         cout << v[i][j] << ", ";
    //     cout << endl;
    // }

    memset(visit, false, sizeof(visit));

    // cout << "BFS: ";
    // BFS(root);
    cout << "DFS: "; 
    DFS(root);
    
    return 0;
}