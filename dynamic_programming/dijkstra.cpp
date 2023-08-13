/*
{{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int S)
{
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int Node = pq.top().second;
        pq.pop();
        for (auto it : adj[Node])
        {
            if (dis + it.second < dist[it.first])
            {
                dist[it.first] = dis + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
    return dist;
}

int main()
{
    int n,v;
    printf("Enter no. of edges: ");
    cin>>n;
    printf("Enter no. of vertices: ");
    cin>>v;

    printf("Enter edge list: \n");
    vector<pair<int, int>> edges[v+1];  // v+1 is taken in the case 0 is also in the node
    for(int i =0;i<n;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges[u].push_back({v,wt});
    }
    printf("Enter source node : ");
    int S;
    cin>>S;
    vector<int> ans = dijkstra(v,edges,S);
    // for(auto x: ans)    cout<<x<<" ";
    printf("Shortest distance between all nodes from source %d : \n",S);
    for(int i =0;i<v;i++)   printf("%d --> %d = %d\n",S,i,ans[i]);
}

/*
6 3
0 1 1
1 0 1
0 2 6
2 0 6
1 2 3
2 1 3
2
*/