#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define For(i,x) for(int i = 0;i < x;i++)
typedef pair<int,int> Pt;
bool cmp(Pt a,Pt b) {
	return a.F < b.F;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	vector<Pt> coin;
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int f, s;
        Pt tmp;
        For(i, N) {
            cin >> tmp.F >> tmp.S;
            coin.pb(tmp);
        }
        sort(coin.begin(),coin.end(),cmp);
        
        dp[200*100][20001] = {};
        
        for(int i = 0;i < N;i++) {
        	for(int k = 0;k < M;k++) {
        		for(int j = 1;j < coin[i].S;j++) {
        			dp[i][k] = dp[i - j][k] + dp[i - j][k - coin[i].F*j];
        		}
        	}
        }
        
        
        
        if (Dp(dp[0],dp[1],N,M))
            cout << "Yes" << endl;
        else
            cout << "No"  << endl;
        for (; ptr > 0; ptr--) {
            dp[0][ptr] = 0;
            dp[1][ptr] = 0;
        }
    }
    return 0;
}