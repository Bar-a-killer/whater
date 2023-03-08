#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> datas;
	int tmp,maxx=0;
	for(int i=0;i<n;i++){
		cin >> tmp;
		datas.push_back(tmp);
	}
	int head,tail;
	for(int i=n-1;i>=0;i--){
		head=i;tail=i;
		while(--head>0)
			if(datas[head]<datas[i])
				break;
		while(++tail<n-1)
			if(datas[tail]<datas[i])
				break;
		while(datas.size() > 0 && datas.back() > datas[i])
			datas.pop_back();
		cout << tail-head << endl;
		maxx = max(maxx,(tail-head)*datas[i]);
	}
	cout << maxx << endl;
}