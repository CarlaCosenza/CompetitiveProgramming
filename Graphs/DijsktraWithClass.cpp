#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node{
	private: 
		int id;
		vector <Node*> adj;
		vector <int> adjw;
		int dist;

	public:
		Node(int id){
			this->id = id
			this->dist = 1e6;
		}
		void addNeighbor(Node* node, int weight){
			adj.push_back(node);
			adjw.push_back(weight);
		}
		int getDist(){
			return dist;
		}
		void setDist(int dist){
			this->dist = dist;
		}
		vector <Node*> getAdj(){
			return adj;
		}
		vector <int> getAdjw(){
			return adjw;
		}
};

class Graph{
	private:
		int vertices;
		unordered_map <int, Node*> nodes;
	public:
		Graph(int vertices, int node){
			this->vertices = vertices;
		}

		void addEdge(int source, int dest, int weight){
			if(nodes.count(source) == 0){
				nodes[source] = new Node(source);
			}
			if(nodes.count(dest) == 0){
				nodes[dest] = new Node(source);
			}
			nodes[source]->addNeighbor(nodes[dest], weight);
		}

		void dijkstra(int node){
			priority_queue < pair <int, Node*> > pq;
			pq.push({0, nodes[node]});
			while(!pq.empty()){
				Node* currentNode = pq.top().second;
				int distance = -pq.top().first;
				pq.pop();

				for(int i = 0 ; i < currentNode->getAdj().size() ; i++){
					Node* adjNode = currentNode->getAdj()[i];
					int d = currentNode->getAdjw()[i];
					if(adjNode->getDist() > d + distance){
						adjNode->setDist(d+distance);
						pq.push({-adjNode->getDist(),adjNode});
					}
				}
			}

			return;
		}
}