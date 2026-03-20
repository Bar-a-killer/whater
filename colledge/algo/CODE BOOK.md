---
title: CODE BOOK

---

# CODE BOOK
## Opening
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define f first
#define INF 1e18
#define s second
#define FOR(I,N) for(int I=0;I<(N);I++)
#define yuri ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
void solve() {
}
signed main() {
    yuri;
    solve();
}
```
## BIT
```cpp
struct Binary_Indexed_Tree{
    int n;
    vector<long long> bit;
    int lowbit(int x){
        return x&-x;
    }
    void init(int _n){
        n = _n+1;
        bit = vector<long long>(n,0);
    }
    void update(int x,int v){
        for(; x<n; x+=lowbit(x)){
            bit[x] += v;
        }
    }
    long long query(int x){
        long long ret = 0;
        for(; x>0; x-=lowbit(x)){
            ret += bit[x];
        }
        return ret;
    }
}BIT;
```
## dijk
```cpp
vector<pair<int,int>>vec[N];
void dijkstra(int s,int t){
    int dis[N];
    for(int i=0;i<N;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({dis[s],s});
    while(pq.empty()==0){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto [v,w]:vec[u]){
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}
```