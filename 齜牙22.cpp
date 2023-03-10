#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int T,N;
	deque<int> datas;
	cin >> T;
	int tmp,uja1,uja2=0,uja3,ans=0;
	while(T--)
	{
		cin >> N;
		while(N--)
		{
			cin >> tmp;
			datas.push_back(tmp);
		}
		while(datas.size() != 0)
		{
			uja1=datas.front();
			datas.pop_front();
			while(uja1>uja2 && uja3>uja2 && uja3!=datas.back())
			{
				ans++;
				uja2 = uja3;
				uja3 =  
			}
		}
	}
}