#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 998244353;
int dp[2][2505] = {0};
signed main() {
    dp[1][0] = 1;
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) {
        memset(dp[i%2],0,sizeof(dp[i%2]));
        for(int r = 2504;r >= 0;r--) {
            for(int j = 1;j <= m;j++) {
                if(r-j >= 0) {
                    dp[i%2][r] = (dp[i%2][r] + dp[!(i%2)][r-j]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for(int i = k+1;i < 2505;i++) {
        ans = (ans + dp[(n-1)%2][i])%mod;
    }
    cout << ans << endl;
}