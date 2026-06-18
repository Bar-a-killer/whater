#include <bits/stdc++.h>
using namespace std;
#define yuri ios::sync_with_stdio(0),cin.tie(0);
#define int long long
#define endl "\n"
typedef pair<int,int> pii;
const int maxn = 500005;
vector<int> v[maxn];
int in[maxn];
int out[maxn];
int anc[maxn][21];
int timee = 1;
int dep[maxn];
void dfs1(int r,int fa) {
    in[r] = timee++;
    anc[r][0] = fa;
    for(auto nxt:v[r]) {
        if(nxt != fa) {
            dep[nxt] = dep[r]+1;
            dfs1(nxt,r);
        } 
    }
    out[r] = timee++;
}

bool is_auc(int a,int b) {
    return in[a] <= in[b] && out[a] >= out[b];
}
int lca(int a,int b) {
    if(is_auc(a,b)) return a;
    if(is_auc(b,a)) return b;
    for(int i = 20;i >= 0;i--) {
        if(anc[a][i]  && anc[a][i] != b && !is_auc(anc[a][i], b))
            a = anc[a][i];
    }
    return anc[a][0];
}
int dist(int a,int b){
    int L=lca(a,b);
    return dep[a]+dep[b]-2*dep[L];
}
void solve() {
    int n;
    cin >> n;
    int q;cin >> q;
    timee = 1;
    for(int i = 1; i <= n; i++) {
        v[i].clear();
        fill(anc[i], anc[i]+21, 0);
    }
    int m;
    for(int i = 0;i < n-1;i++) {
        int a,b,c;
        cin >> a >> b;
        v[a].push_back({b});
        v[b].push_back({a});
    }
    dep[1] = 0;
    dfs1(1,0);
    for(int j = 1; j <= 20; j++) {
        for(int i = 1; i <= n; i++) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
    for(int i = 0;i < q;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        int x=lca(a,b);
        int y=lca(b,c);
        int z=lca(a,c);
        int p=x;
        if(dep[y]>dep[p]) p=y;
        if(dep[z]>dep[p]) p=z;
        cout << p  << " ";
        cout << (dist(a,b)+dist(b,c)+dist(c,a))/2<< "\n";
    }
}
signed main() {
    yuri;
    solve();
    return 0;
}