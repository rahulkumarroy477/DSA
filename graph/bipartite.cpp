/*
Example:
            1---------2
            |         | \
            |         |  \
            |         |   3
            |         |  /
            |         | /
            4---------5

6 6
1 4
1 2
2 5
2 3
4 5
5 3

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<int> graph[N];
bool vis[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}