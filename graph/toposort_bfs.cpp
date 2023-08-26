#include <bits/stdc++.h>
using namespace std;
void topoSort(vector<pair<int, int>> edges, int v, int e)
{
    vector<int> adj[v];
    for (const auto x : edges)
    {
        adj[x.first].push_back(x.second);
    }

    // store indegree
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }
    // insert element with indegree 0
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // take out element and reduce indegree
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto x : adj[node])
        {
            indegree[x]--;
            if(indegree[x]==0)  q.push(x);
        }
    }
    cout << "Topo sort: " << endl;
    for (auto x : ans)
        cout << x << " ";
}
bool isCyclic(vector<pair<int, int>> edges, int v, int e)
{
    vector<int> adj[v];
    for (const auto x : edges)
    {
        adj[x.first].push_back(x.second);
    }

    // store indegree
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }
    // insert element with indegree 0
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // take out element and reduce indegree
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto x : adj[node])
        {
            indegree[x]--;
            if(indegree[x]==0)  q.push(x);
        }
    }
    cout<<cnt<<endl;
    return cnt==v;
}
int main()
{

    int v, e;
    cin >> v >> e;

    // edges
    vector<pair<int, int>> edges;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    cout<<isCyclic(edges,v,e)<<endl;
    
    topoSort(edges,v,e);
// 6 6
// 5 0
// 4 0
// 5 2
// 4 1
// 2 3
// 3 1

}