#include<bits/stdc++.h>
using namespace std;

const int N = 2002;
int maze[N][N], visited[N][N];
int level[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;

    q.push(src);

    while(!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for(int i=0; i<4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    pair<int, int> src, dst;
    for(int i=0; i<n; i++)
    {
        string input;
        cin >> input;
        for(int j=0; j<m; j++)
        {
            if(input[j] == '#')
            {
                maze[i][j] = -1;
            }
            else if(input[i] == 'A')
            {
                src = {i, j};
            }
            else if(input[i] == 'B')
            {
                dst = {i, j};
            }
        }
    }
}