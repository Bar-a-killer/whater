#include<bits/stdc++.h>
using namespace std;
int mod = 1000007;

int main() {
	int a;
	cin >> a;
	string str;
	cin >> str;
	vector<int> hash(a+1);
	vector<int> tws(a+1);
	
	hash[1] = str[0] - 'a';
	tws[1] = 1;
	for(int i = 2;i <= a ; i++) {
		tws[i] = (tws[i-1] * 26) % mod;
		hash[i] = (hash[i-1] + (str[i-1]-'a')*tws[i]) % mod;
	}
	int ans = 0;
	
	for(int i = 2;i <= a ; i++) {
		for(int j = i-1;j >= i/2;j--) {
			if((hash[j] + hash[j] * tws[j+1] % mod - hash[i]) % tws[i] == 0) {
				ans += j;
				cout << i << " " << j << endl;
				break;
			}
		}
	}
	cout << ans << endl;
}