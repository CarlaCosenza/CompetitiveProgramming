#include <bits/stdc++>
using namespace std;

vector <int> dijkstra(vector <int> &adj[N], vector <int> &adjw[N], int n){
	vector <int> dist(N, 1e7+7);
	priority_queue <pair<int, int>> pq;
	pq.push(make_pair(0, n));
	pq.pop();

	while(!pq.empty()){
		int u = pq.top().second;
		int d = -pq.top().first;
		for(int i = 0 ; i < adj[u].size() ; i++){
			int v = adj[u][i];
			int w = adjw[u][i];
			if(dist[v] > d+w){
				dist[v] = d + w;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}

	return dist;
}