#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define X first
#define Y second
typedef pair<long long,long long> Pt;

ll countPair(const Pt &a,const Pt &b) {
	return (a.X - b.X)*(a.X - b.X)+(a.Y - b.Y)*(a.Y - b.Y);
}

long long cross(const Pt &a,const Pt &b) {
	return a.X * b.Y - a.Y * b.X;
}

long long times(const Pt &a,const Pt &b) {
	return a.X * b.X + a.Y * b.Y;
}
Pt mines(const Pt &a,const Pt &b) {
	return make_pair(a.X-b.X,a.Y-b.Y);
}

ll ori(const Pt &a,const Pt &b,const Pt &c) {
	if(cross(mines(b,a),mines(c,a)) == 0) return 0;
	return cross(mines(b,a),mines(c,a)) < 0 ? -1 : 1;
}
bool btw(const Pt &a,const Pt &b,const Pt &c) {
	if(ori(a,b,c) != 0) return 0;
	return times(mines(a,b),mines(a,c)) < 0;
}
int main(void) {
	ios::sync_with_stdio(0),cin.tie(0);
	ll N;
	cin >> N;
	Pt a1,b1,a2,b2;
	for(int i=0;i<N;i++) {
		cin >> a1.X >> a1.Y >> a2.X >> a2.Y >> b1.X >> b1.Y >> b2.X >> b2.Y;
		bool a123 = ori(a1,a2,b1);
		bool a124 = ori(a1,a2,b2);
		bool a341 = ori(b1,b2,a1);
		bool a342 = ori(b1,b2,a2);
		if(a123 == 0 && a124 == 0 && (btw(a1,a2,b1) || btw(a1,a2,b2) || btw(b1,a1,a2) || btw(b2,a1,a2))) {
			cout << "Yes" << endl;
			continue;
		}
		if(a123 * a124 <= 0 && a341 * a342 <= 0) {
			cout << "Yes" << endl;
			continue;
		}
		cout << "No" << endl;
	}
}