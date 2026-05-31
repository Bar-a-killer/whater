#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yuri ios::sync_with_stdio(0),cin.tie(0);
const int MOD = 1e9+7;
int dp[1<<20+1][22];
int fpow(int a,int b){
    int res = 1; a %= MOD;
    while(b > 0){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int inv(int a) {
    return fpow(a,MOD-2);
}
signed main() {
    yuri
    int n;
    cin >> n;
    bool mv[22][22];
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> mv[i][j];
        }
    }
    dp[1][0] = 1;
    int ans[22] = {0};
    for(int mask = 1;mask < 1 << n;mask++) {
        for(int u = 0;u < n;u++) {
            if(dp[mask][u] == 0) continue;
            if (!(mask & (1 << u))) continue;
            int k = 0;
            for(int i = 0;i < n;i++) {
                if(mv[u][i] && !(mask & (1 << i))) k++;
            }
            if(k == 0) {
                ans[u] = (ans[u] + dp[mask][u]) % MOD;
                continue;
            } else {
                int invk = inv(k);
                for(int v = 0;v < n;v++) {
                    if(mv[u][v] && !(mask & (1 << v))) {
                        dp[mask | (1 << v)][v] = \
                        (dp[mask|(1<<v)][v] + dp[mask][u] % MOD * invk) % MOD;
                    }
                }
            }
        }
    }
    for(int i = 0;i < n;i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}