#include <bits/stdc++.h>
using namespace std;

public class Node{
	public:
		bool isEnd;
		vector <*Node> nodes(26, NULL);
		Node(){
			isEnd = false;
		}
};

public class Trie{
	public:
		Node* root = new Node();

		Node* insertChar(char c, Node* node){
			int index = c - 'a';
			if(node->nodes[index] != NULL) return node->nodes[index];
			Node* newNode = new Node();
			node->nodes[index] = newNode;
			return newNode;
		}

		void insertString(string s){
			Node* node = root;
			for(int i = 0 ; i < s.size() ; i++) node = insertChar(s[i], node);
			node->isEnd = true;
			return;
		}

		bool search(string s){
			Node* node = root;
			for(int i = 0 ; i < s.size() ; i++){
				int index = s[i] - 'a';
				if(node->nodes[index] == NULL) return false;
				node = node->nodes[index];
			}
			return node->isEnd;
		}
};