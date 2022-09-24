#include<bits/stdc++.h>
using namespace std;

vector<int> v[100];
bool visit[100];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        if(visit[parent] == true)
            continue;
        cout << parent << endl;
        for (int i = 0; i < v[parent].size(); i++)
        {
            int children = v[parent][i];
            if(visit[children] == false) 
                q.push(children);
        }
        visit[parent] = true;
    }
    
}

void dfs(int src)
{
    cout << src << endl ;
    visit[src] = true;
    for(int i=0; i<v[src].size(); i++)
    {
        int children = v[src][i];
        if(visit[children] == false)
            dfs(children);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(visit, false, sizeof(visit));
    bfs(0);
    // dfs(1);

    return 0;
}

/*
for bfs
6 7 
5 3
4 5
1 0
1 2
1 3
3 0
4 3

for dfs
7 7
1 2
1 6
2 3
2 4
6 4
6 7
4 5
*/ 