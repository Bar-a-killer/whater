#include<bits/stdc++.h>
using namespace std;
#define For(i,x) for(int i = 0;i < x ; i++)
int main() {
	int T;
	cin >> T;
	while(T--) {
		int n,m;
		int p1,p2;
		bool graph[1000][1000] = {0};
		int father[1000] = {0};
		bool exist[1000];
		For(i,n) {
			exist[i] = 1;
		}
		cin >> n >> m;
		For(i,m) {
			cin >> p1 >> p2;
			graph[p1][p2] = 1;
			father[p2]++;
		}
		queue<int> output;
		bool go = 1;
		while(go) {
			go = 0;
			for(int i = n-1 ; i>=0 ; i--) {
				if(exist[i] && father[i] == 0) {
					exist[i] = 0;
					For(j,n) {
						if(graph[i][j] == 1) 
							father[j]--;
					}
					go = 1;
					output.push(i);
					//cout << "check!" << endl;
				}
			}
		}
		For(j,n) {
			if(exist[j]) 
				go = 1;
		}
		if(go)
			cout << "QAQ" << endl;
		else {
			while(output.size()) {
				cout << output.front() << " ";
				output.pop();
			}
			cout << endl;
		}
	}
}