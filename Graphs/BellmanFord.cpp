#include <bits/stdc++.h>
using namespace std;

#define INF 100000

int V, E;
vector <int> adj[INF];
vector <int> adjw[INF];

vector <int> bellmanFord(int source){
	vector <int> dist(V, INF);
	dist[source] = 0;
	int v, w;

	for(int i = 0 ; i < V-1 ; i++){
		for(int u = 0 ; u < V ; u++){
			for(int j = 0 ; j < adj[u].size() ; j++){
				v = adj[u][j];
				w = adjw[u][j];
				dist[v] = min(dist[v], dist[u] + w);
			}
		}
	}

	return dist;
}

int main(){

	scanf("%d %d", &V, &E);
	for(int i = 0 ; i < E ; i++){
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		adj[a].push_back(b);
		adjw[a].push_back(w);
	}

	vector <int> dist = bellmanFord(0);

	for(int i = 0 ; i < dist.size() ; i++){
		printf("Distance to %d equal to %d\n", i, dist[i]);
	}

	return 0;

}
