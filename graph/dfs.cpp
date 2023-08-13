#include <bits/stdc++.h>
using namespace std;
const int N = 1e+5;
vector<int> graph[N];
bool visited[N];
vector<vector<int>> ans;
vector<int> temp;

// dfs using stack
void dfs()
{
    stack<int> st;
    st.push(10);
    st.push(12);
    st.push(13);
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
}
void dfs(int vertex)
{
    //  take action after entering the vertex

    visited[vertex] = true;
    temp.push_back(vertex);
    for (int child : graph[vertex])
    {
        // take action on child befor entering child node

        // cout<<"parent is "<<vertex<<", Child is "<<child<<endl;
        if (visited[child])
            continue;
        dfs(child);
        // take action after exiting child node
    }
    //    take action before exiting vertex

    return;
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
    for (int i = 1; i <= m; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        ans.push_back(temp);
        temp.clear();
        count++;
    }
    cout << count << endl;
    for (auto x : ans)
    {
        for (int v : x)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}
// 8 5
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7