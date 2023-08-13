#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, v;
    cout << "Enter no. of edges : ";
    cin >> n;
    cout << "Enter no. of vertices : ";
    cin >> v;

    vector<vector<int>> edges;
    cout << "Enter edges with their weight : " << endl;
    // edges --> node1 node2 edgeWt
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }

    // int s;
    // cout<<"Enter source vertex : ";
    // cin>>s;
    // cout<<endl;
    for (int s = 0; s < v - 1; s++)
    {
        vector<int> dist(v, 1e9);
        dist[s] = 0;
        for (int i = 0; i < v - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e9 and dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        printf("shortest Distance of other vertices from source vertex %d are : \n", s);

        for (int i = 0; i < v; i++)
            printf("%d --> %d = %d\n", s, i, dist[i]);
        cout<<endl;
    }
}

/*
input1
7 6
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3
0

input 2
4 3
0 1 5
1 0 3
1 2 -1
2 0 1
0
*/