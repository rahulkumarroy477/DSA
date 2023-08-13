// 7 4
// 1 3
// 1 4
// 1 2
// 5 6
#include<bits/stdc++.h>
using namespace std;
const int N = 100;
// int graph[N][N];
vector<int> graph[N];

void edgeTograph(vector<pair<int,int>> edges,vector<int> graph[])
{
    for(auto x:edges)
    {
        graph[x.first].push_back(x.second);
        graph[x.second].push_back(x.first);
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    // for(int i = 0;i<n;++i)
    // {
    //     int x,y;
    //     cin>>x>>y;
    //     graph[x].push_back(y);
    //     graph[y].push_back(x);
        // graph[x][y]=1;
        // graph[y][x]=1;

    // }
    // for(int i =0;i<m;i++)
    // {
    //     for(int j =0;j<m;j++)
    //     {
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    
}


