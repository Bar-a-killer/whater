#include <bits/stdc++.h>
using namespace std;
#define yuri ios::sync_with_stdio(0),cin.tie(0);
#define int long long
typedef pair<int,int> pii;
const int maxn = 400005;
vector<pii> v_all[maxn];
vector<pii> v[maxn];
int in[maxn];
int out[maxn];
int vis[maxn];
int anc[maxn][20];
int timee = 1;
int lcaw[maxn][20] = {0};
void dfs1(int r,int fa) {
    in[r] = timee++;
    anc[r][0] = fa;
    
    for(auto nxt:v[r]) {
        if(nxt.first != fa)
            dfs1(nxt.first,r);
        else 
            lcaw[r][0] = nxt.second;
    }
    out[r] = timee++;
}
bool is_auc(int a,int b) {
    return in[a] < in[b] && out[a] > out[b];
}
int lca(int a,int b) {
    if(is_auc(a,b)) return a;
    if(is_auc(b,a)) return b;
    for(int i = 20;i >= 0;i--) {
        if(anc[a][i] && !is_auc(anc[a][i], b))
            a = anc[a][i];
    }
    return anc[a][0];
}
int in_mst[maxn][maxn] = {0};
struct m {
    int w,u,v;
};
int toans = 0;
void mst() {
    int vis[maxn] = {0};
    priority_queue<m,vector<m>,greater<m>> que;
    vis[1] = 1;
    for(pii i:v_all[1]) {
        que.push({i.second,1,i.first});
    }
    while(!que.empty()) {
        auto to = que.top(); que.pop();
        if(vis[to.v]) continue;
        vis[to.v] = 1;
        for(pii i:v_all[to.v]) {
            que.push({i.second,1,i.first});
        }
        v[to.u].push_back({to.v,to.w});
        v[to.v].push_back({to.u,to.w});
        in_mst[to.u][to.v] = 1;
        in_mst[to.v][to.u] = 1;
        toans += to.w;
    }
}
signed main() {
    yuri;
    int n;
    cin >> n;
    vector<pii> input;
    for(int i = 0;i < n-1;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v_all[a].push_back({b,c});
        v_all[b].push_back({a,c});
        input.push_back({a,b});
    }
    dfs1(1,0);
    for(int j = 1; j <= log2(n); j++) {
        for(int i = 1; i <= n; i++) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
            lcaw[i][j] = max(lcaw[i][j],lcaw[lcaw[i][j - 1]][j - 1]);
        }
    }
    for(int i = 0;i < n-1;i++) {
        auto now = input[i];
        if(in_mst[now.first][now.second]) {
            cout << toans << endl;
        } else {
            int lcaa = lca(now.first,now.second);
            //cout << toans - max()
        }
    }
    return 0;
}