#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX; // Define infinity

typedef pair<int, int> PII;

vector<PII> adjList[1000]; // Define adjacency list

int prim(int start, int n) {
    priority_queue<PII, vector<PII>, greater<PII> > pq; // Define priority queue
    vector<int> key(n, INF); // Initialize key vector to infinity
    vector<bool> visited(n, false); // Initialize visited vector to false
    int mst = 0; // Initialize mst to 0
    
    pq.push(make_pair(0, start)); // Add starting node to priority queue
    key[start] = 0; // Set starting node's key to 0
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        mst += key[u];
        for (PII v : adjList[u]) {
            int w = v.second;
            if (!visited[w] && v.first < key[w]) {
                key[w] = v.first;
                pq.push(make_pair(key[w], w));
            }
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
        adjList[u].push_back(make_pair(w, v));
        adjList[v].push_back(make_pair(w, u));
    }
    int start;
    cin >> start; // Input starting node
    cout << "Weight of minimum spanning tree is : "<<prim(start, n) << endl; // Output minimum spanning tree weight
    return 0;
}
