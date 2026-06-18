
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define cl(X) (X<<1)
#define cr(X) ((X<<1)+1)
#define INF 1e18
class seg_T{
    public:
    int n;
    vector<int> seg_tree;
    vector<int> datas;
    vector<int> tag;
    vector<int> first;vector<int> diff;
    seg_T(int a) {
        seg_tree = vector<int>(a * 4+5, 0);
        tag = vector<int>(a * 4+5, 0);
        first = vector<int>(a * 4+5, 0);
        diff = vector<int>(a * 4+5, 0);
        n = a;
        datas.resize(n+1,0);
    }
    void input_datas() {
        for(int i = 1;i <= n;i++) {
            cin >> datas[i];
        }
    }
    void push(int id,int l,int r) {
        if(diff[id]) {
            seg_tree[id] += (first[id]*2 + (r-l)*diff[id]) * (r-l+1) / 2;
            if(l != r) {
                diff[cl(id)] += diff[id];
                diff[cr(id)] += diff[id];
                first[cl(id)] += first[id];
                first[cr(id)] += first[id] + ((l+r)/2 - l + 1) * diff[id];
            }
            diff[id] = first[id] = 0;
        }
    }
    void pull(int id,int l,int r) {
        int mid = (l+r) >> 1;
        push(cl(id),l,mid);
        push(cr(id),mid+1,r);
        seg_tree[id] = seg_tree[cl(id)]+seg_tree[cr(id)]; 
    }
    void build(int id,int l,int r) {
        if(l==r) {
            seg_tree[id] = datas[l];
            return;
        }
        int mid = (l+r)>>1;
        build(cl(id),l,mid);
        build(cr(id),mid+1,r);
        pull(id,l,r);
    }
    void build() {
        build(1,1,n);
    }
    int query(int l,int r,int sl,int sr,int id) {
        push(id,l,r);
        if(sl<=l&&r<=sr){
            return seg_tree[id];
        }
        int mid = (l+r) >> 1;
        int res = 0;
        if(sl <= mid) {
            res += query(l,mid,sl,sr,cl(id));
        }
        if(sr > mid) {
            res += query(mid+1,r,sl,sr,cr(id));
        }
        return res;
    }
    int query(int l,int r) {
        return query(1,n,l,r,1);
    }
    void update(int l,int r,int id,int ql,int qr) {
        push(id,l,r);
        if(ql<=l&&r<=qr) {
            first[id] += (l - ql + 1);
            diff[id]++;
            return;
        }
        int mid = (l+r) >> 1;
        if(ql <= mid) {
            update(l,mid,cl(id),ql,qr);
        }
        if(qr > mid) {
            update(mid+1,r,cr(id),ql,qr);
        }
        pull(id,l,r);
    }
    void update(int l,int r) {
        update(1,n,1,l,r);
    }
    void throwout() {
        for(int i = 0;i<n*2;i++) {
            cout << seg_tree[i] << " ";
        }
        cout << endl;
        for(int i = 0;i<n*2;i++) {
            cout << tag[i] << " ";
        }
        cout << endl << endl;
    }
};
void solve() {
    int n,q;
    cin >> n >> q;
    seg_T t(n);
    t.input_datas();
    t.build();
    for(int i = 0;i<q;i++) {
        int op=0;
        cin >> op;
        int l,r;
        cin >> l >> r;
        if(op == 2) {
            cout << t.query(l+1,r+1) << endl;
        } else {
            t.update(l+1,r+1);
        }
    }
}
signed main() {
    solve();
}