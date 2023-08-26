// dfs
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> adj[],vector<bool> &vis){
	vis[node]=true;
	cout<<node<<endl;
	for(int vertex:adj[node])
	{
		if(!vis[vertex]){
			dfs(vertex,adj,vis);
		}
	}	
}
int main(){
	// storing graph undirected
	int v,edges;
	cin>>v>>edges;
	vector<int> adj[v];
	vector<bool> vis(v,false);
	for(int i =0;i<edges;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// dfs also true for disconnected graph
	for(int i =0;i<v;i++){
		if(!vis[i])	dfs(i,adj,vis);
	}		
	return 0;
}