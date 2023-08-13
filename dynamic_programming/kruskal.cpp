#include <iostream>
#include <vector>
#include <algorithm>

/*
6 8
1 2 4
1 3 4
2 3 2
3 4 3
3 5 2
3 6 4
4 6 3
5 6 3
*/
using namespace std;

const int MAXN = 1000; // Define maximum number of nodes

struct Edge {
    int u, v, w;
};

vector<Edge> edgeList; // Define edge list
int parent[MAXN]; // Define parent array

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    parent[find(u)] = find(v);
}

int kruskal(int n) {
    sort(edgeList.begin(), edgeList.end(), [](const Edge& e1, const Edge& e2) {
        return e1.w < e2.w;
    }); // Sort edges by weight
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i; // Initialize parent array
    }
    
    int mst = 0; // Initialize mst to 0
    
    for (Edge e : edgeList) {
        if (find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            mst += e.w;
        }
    }
    
    return mst;
}

int main() {
    int n, m;
    cin >> n >> m; // Input number of nodes and edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // Input edge information
        edgeList.push_back({u, v, w});
    }
    cout <<"Minimum cost weight is : "<<kruskal(n) << endl; // Output minimum spanning tree weight
    return 0;
}
