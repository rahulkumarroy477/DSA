/*
4 5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int graph[N][N];
bool vis[N][N];
void dfs(int i, int j, int n, int m)
{
    vis[i][j] = true;
    if(j-1>=0 && !vis[i][j-1] && graph[i][j-1]) dfs(i,j-1,n,m);
    if(j+1<=m && !vis[i][j+1] && graph[i][j+1]) dfs(i,j+1,n,m);
    if(i-1>=0 && !vis[i-1][j] && graph[i-1][j]) dfs(i-1,j,n,m);
    if(i+1<=n && !vis[i+1][j] && graph[i+1][j]) dfs(i+1,j,n,m);
    return ;
}
int main()
{
    int m, n, count = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j])
                continue;
            count++;
            dfs(i, j, n, m);
        }
    }
    cout << count << endl;
}
