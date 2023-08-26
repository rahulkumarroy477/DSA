#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> adj[],vector<bool> &vis,stack<int> &s){
    vis[node] =true;
    for(auto vertex:adj[node])
    {
        if(!vis[vertex])    dfs(vertex,adj,vis,s);
    }
    s.push(node);
}
int main()
{
    int v,e;
    cin>>v>>e;
    // edge lists
    vector<pair<int,int>> edges;
    for(int i =0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }

    // edges to graph
    vector<int> adj[v];
    for(auto x:edges)
    {
        adj[x.first].push_back(x.second);
    }

    stack<int> s;
    // visited array
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++)
    {
        if(!vis[i]) dfs(i,adj,vis,s);
    }

    // stack to vector
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    for(auto x:ans) cout<<x<<endl;
}

