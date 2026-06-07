
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define cl(X) (X<<1)
#define cr(X) ((X<<1)+1)
#define INF 1e18
struct Compress {
    vector<int> xs;
    void add(int v) { xs.push_back(v); }
    void build() {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
    }
    int get(int v) {
        return lower_bound(xs.begin(), xs.end(), v) - xs.begin() + 1;
    }
    int origin(int i) { return xs[i - 1]; }
    int size() { return xs.size(); }
}cp;
class seg_T {
public:
    int n;
    vector<int> odd_len, even_len;
    vector<int> total;
    vector<int> tag;
    seg_T(int a,vector<int>& s) {
        n = a;
        odd_len.assign(n*4 + 5,0);
        even_len.assign(n*4+5,0);
        total.assign(n*4+5,0);
        tag.assign(n*4+5,0);
        build(1,1,n,s);
    }
    void build(int id, int l, int r, vector<int>& xs) {
        total[id] = xs[r] - xs[l - 1];
        even_len[id] = total[id];
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(cl(id), l, mid, xs);
        build(cr(id),mid + 1,r,xs);
    }
    void flip(int id) {
        swap(odd_len[id], even_len[id]);
        tag[id] ^= 1;
    }
    void push(int id) {
        if (tag[id]) {
            flip(cl(id));
            flip(cr(id));
            tag[id] = 0;
        }
    }
    void pull(int id) {
        odd_len [id] = odd_len [cl(id)] + odd_len [cr(id)];
        even_len[id] = even_len[cl(id)] + even_len[cr(id)];
    }
    void update(int id, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) { 
            flip(id); return; 
        }
        push(id);
        int mid = (l + r) >> 1;
        update(cl(id), l, mid, ql, qr);
        update(cr(id), mid + 1, r, ql, qr);
        pull(id);
    }
    void update(int l, int r) { 
        update(1,1,n,l,r); 
    }
    int query()  { 
        return odd_len[1];  
    }
};
void solve() {
    int n;
    cin >> n;
    vector<tuple<int,int,int,bool>> a;
    for(int i = 0;i < n;i++) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.push_back({y1,x1,x2,1});
        a.push_back({y2,x1,x2,0});
        cp.add(x1);cp.add(x2);
    }
    cp.build();
    seg_T t(cp.size()-1,cp.xs);
    sort(a.begin(),a.end());
    int ans = 0;int prey = -1;
    int i = 0;
    while(i<a.size()) {
        int cury = get<0>(a[i]);
        if(prey >= 0 && cury>prey)
            ans += t.query()*(cury-prey);
        while (i < a.size() && get<0>(a[i]) == cury) {
            t.update(cp.get(get<1>(a[i])), cp.get(get<2>(a[i]))-1);
            i++;
        }
        prey = cury;
    }
    cout << ans << endl;
}
signed main() {
    solve();
}