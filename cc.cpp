#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> graph[], int vis[]){
	vis[node] = 1;

	for(int child : graph[node]){
		if(!vis[child]){
			dfs(child, graph, vis);
		}
	}
}
int main(){
	int n, e;
	cin >> n >> e;
	vector<int> graph[n+1];
	for(int i = 0; i<n; i++){
		int v,u;
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	int vis[n+1] = {0};
	int count = 0;
	for(int i = 1; i<=n; i++){
		if(!vis[i]){
			dfs(i, graph, vis);
			count++;
		}
	}
	cout << count << endl;
	return 0;
}