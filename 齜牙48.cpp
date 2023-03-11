#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	node *l;
	node *r;
};

void dfs(node* n)
{
	if(n->l!=NULL)
		dfs(n->l);
	if(n->r!=NULL)
		dfs(n->r);
	cout << n->a;
}
int main()
{
	vector<node> tree;
	int N,input;
	node root,tmp;
	cin >> N;
	cin >> input;
	tmp.a = input;
	tree.push_back(tmp);
	for(int i=1;i<N;i++)
	{
		cin >> input;
		tmp.a = input;
		tree.push_back(tmp);
		root = tree[0];
		while(1)
		{
			if(root.a>tree.back().a)
			{
				if(root.l!=NULL)
					root = *root.l;
				else
				{
					root.l = &tree.back();
					break;
				}
			}
			else
			{
				if(root.r!=NULL)
					root = *root.r;
				else
				{
					root.r = &tree.back();
					break;
				}
			}
		}
	}
	dfs(&tree[0]);
}