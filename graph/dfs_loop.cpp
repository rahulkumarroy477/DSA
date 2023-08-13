#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
bool vis[100];
void bfs(int vertex)
{
    queue<int> qu;
    qu.push(vertex);
    vis[vertex] = true;
    while(!qu.empty())
    {
        int val = qu.front();
        cout<<val<<"-->";
        qu.pop();
        for(auto child:graph[val])
        {
            if(vis[child])  continue;
            qu.push(child);
            cout<<child<<" ";
            vis[child] = true;

        }
        cout<<endl;
    }
}
void dfs(int vertex)
{
    stack<int> st;
    st.push(vertex);
    vis[vertex] = true;
    while(!st.empty())
    {
        int val = st.top();
        cout<<val<<endl;
        st.pop();
        for(auto child:graph[val])
        {
            if(vis[child]) continue;
            st.push(child);
            vis[child] = true;
        }
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    return 0;
}