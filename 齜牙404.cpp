#include<bits/stdc++.h>
using namespace std;
int mod = 1000007;
int k = 10;
int main() {
	int a;
	cin >> a;
	string str;
	cin >> str;
	vector<int> hash(a);
	vector<long long> tws(a);
	long long r = 1;
	hash[0] = str[0] - 'a' +1;
	tws[0] = 1;
	for (int i = 1; i <= a; i++) {
	    tws[i] = (r * tws[i-1] * k) % mod;
	    hash[i] = (r * hash[i-1] + (str[i] - 'a' + 1) * tws[i]) % mod;
	    hash[i] = (hash[i] + mod) % mod;
	    cout << i << ":" << hash[i] << endl;
	}
	int ans = 0;
	
	for(int i = 1;i <= a ; i++) {
		for(int j = i-1;j >= i/2;j--) {
//			cout << i << " " << j << ":" << endl;
//			cout << (hash[j] + hash[j] * tws[j+1] % mod) % mod << "\n" << hash[i] << "\n" << hash[j] + hash[j] * tws[j+1] % mod - hash[i] << endl;
			if(((hash[j] + hash[j] * tws[j+1] % mod) % mod - hash[i]) % tws[i] == 0) {
				ans += j;
				
				break;
			}
		}
	}
	cout << ans << endl;
}