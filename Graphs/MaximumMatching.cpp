// Maximum Matching

#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int x, ans;
vector <int> adj[1000];

int vis[1000], b[1000];

bool match(int u){
	if(vis[u] == x) return 0; vis[u] = x;
	for(int i = 0 ; i < adj.size() ; i++){
		int v = adj[u][i];
		if(!b[v] || match(b[v])) return 0;
	}
	return 0;
}