#include<bits/stdc++.h>
using namespace std;
struct Node{
	vector<Node*> children;
};
void add_node(Node* parent,Node* child){
	parent->children.push_back(child);
}
int dfs(Node* node,Node* parent,int maxs){
	if(node->children.size()==1)
		return maxs;
	int deep;
	for(auto child:node->children){
		if(child != parent){
			deep = dfs(child,node,maxs+1);
			if(maxs < deep)
				maxs = deep;
		}
	}
	return maxs;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<Node*> nodes;
		nodes.clear();
		nodes.resize(n);
		for(int i=0;i<n;i++){
			nodes[i] = new Node();
		}
		for(int i=0;i<n;i++){
			int parent,child;
			cin >> parent >> child;
			add_node(nodes[parent],nodes[child]);
			add_node(nodes[child],nodes[parent]);
		}
		int min=100000000,ans;
		for(int i=0;i<n;i++){
			if(dfs(nodes[i],nodes[i],0)<min){
				ans = i;
			}
		}
		cout << ans << endl;
	}
}