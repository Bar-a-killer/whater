#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	set<string> vec;
	int n,j;
	bool b;
	cin >> n;
	string tmp;
	while(n--)
	{
		cin >> tmp;
		b = vec.count(tmp);
		if(!b)
		{
			vec.insert(tmp);
			cout << "OK" << endl;
		}
		else
		{
			j=0;
			tmp+=to_string(j);
			while(b)
			{
				tmp.pop_back();
				tmp+=to_string(++j);
			}
			cout << tmp << endl;
			vec.insert(tmp);
		}	
	}
}