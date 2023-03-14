#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    vector<Node*> children;
};
void add_node(Node* parent, Node* child) {
    parent->children.push_back(child);
}
int count_children(Node* node) {
    int count = 0;
    for (auto child : node->children) {
        count += 1 + count_children(child);
    }
    return count;
}
int main()
{
	int T;
	cin >> T;
	int m,n;
	int parent,child;
	vector<Node*> boxes;
	while(T--){
		cin >> m >> n;
		boxes.clear();
        boxes.resize(m+1);
		for(int i=1;i<=m;i++)
		{
			boxes[i] = new Node();
            boxes[i]->data = i;
		}
		cin >> parent >> child;
		add_node(boxes[parent],boxes[child]);
		n--;
		while(n--){
            cin >> parent >> child;
            add_node(boxes[parent],boxes[child]);
        }
        int p,q;
		cin >> p;
		while(p--)
		{
			cin >> q;
			cout << count_children(boxes[q])+1 << endl;
		}
	}

}
/*
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    int num_descendants; // 維護子孫節點數量
    vector<Node*> children;
};
void add_node(Node* parent, Node* child) {
    parent->children.push_back(child);
}
void count_descendants(Node* node) {
    node->num_descendants = 0;
    for (auto child : node->children) {
        count_descendants(child);
        node->num_descendants += 1 + child->num_descendants;
    }
}
int main()
{
    int T;
    cin >> T;
    int m,n;
    int parent,child;
    vector<Node*> boxes;
    while(T--){
        cin >> m >> n;
        boxes.clear();
        boxes.resize(m+1);
        for(int i=1;i<=m;i++)
        {
            boxes[i] = new Node();
            boxes[i]->data = i;
            boxes[i]->num_descendants = 0;
        }
        cin >> parent >> child;
        add_node(boxes[parent],boxes[child]);
        n--;
        while(n--){
            cin >> parent >> child;
            add_node(boxes[parent],boxes[child]);
        }
        count_descendants(boxes[1]); // 從根節點開始計算子孫節點數量
        int p,q;
        cin >> p;
        while(p--)
        {
            cin >> q;
            cout << boxes[q]->num_descendants + 1 << endl; // 直接返回節點的子孫節點數量
        }
    }
}
*/