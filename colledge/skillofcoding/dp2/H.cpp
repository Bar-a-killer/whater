#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int dp[1000005][1000005] = {0};
signed main() {
    int n,m;
    cin >> n >> m;
    dp[1][1] = 1;
    for(int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        dp[a][b] = -1;
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            if(dp[i][j] == -1) continue;
            if((i+1) <= n && dp[i+1][j] != -1) dp[(i+1)][j] = (dp[(i+1)][j]+dp[i][j])%mod;
            if(j+1 <= n && dp[i][j+1] != -1) dp[i][j+1] = (dp[i][j+1]+dp[i][j])%mod;
        }
    }
    cout << dp[n][n];
}