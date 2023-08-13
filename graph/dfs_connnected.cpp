/*
Example 1 : -
1---2      4-----5    8
|  /       |     |
| /        |     |
3          6-----7
8 7
1 3
1 2
2 3
4 5
4 6
6 7
5 7

Example 2:-
1----2----3
| \  |    |
|  \ |    |
4    5----6
6 7
1 4
1 2
1 5
2 5
2 3
3 6
5 6
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e+5;
vector<int> graph[N];
bool visited[N];
int loop = 0;
bool dfs(int vertex, int par)
{
    //  take action after entering the vertex

    bool isLoop = false;
    visited[vertex] = true;
    for (int child : graph[vertex])
    {

        if (visited[child])
        {
            if (child == par)
                continue;
            else
            {
                loop++;
                // it will only find loop when graph has single loop in each connected component
                return true;
            }
        }

        isLoop |= dfs(child, vertex);
    }

    return isLoop;
}
int main()
{
    // adjacency list
    int m, n, x, y;
    cin >> m >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bool isLoopExists = false;
    for (int i = 1; i <= m; i++)
    {
        if (visited[i])
            continue;
        if (dfs(i, 0))
        {
            isLoopExists = true;
            break;
        }
    }
    cout << isLoopExists << endl;
    cout<<loop<<endl;
}
