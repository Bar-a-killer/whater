#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define int long long

signed main() {
    int bf[1000][1000];
    int n;
    cin >> n;
    for(int i = 0;i < 1000;i++) {
        for(int j = 0;j < 1000;j++) {
            bf[i][j] = INF;
            if(i == j) bf[i][j] = 0;
        }
    }
    pair<int,int> metrix[505];
    for(int i = 0;i < n;i++) {
        int a,b;
        cin >> a >> b;
        metrix[i] = {a,b};
    }
    for(int k = 0;k < 500;k++) {
        for(int i = 0;i < 500;i++) {
            for(int j = 0;j < 500;j++) {
                bf[i][j] = min(bf[i][j],bf[i][k]+bf[k+1][j]+metrix[i].first*metrix[k].second*metrix[j].second);
            }
        }
    }
}