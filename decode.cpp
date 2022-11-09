#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> str,tmp1;
	string out;
	string decode;
	int n,l,hel,decode_1;
	int tmp;
	
	cin >> n >> l;
	hel = l/2;
	for(int i=0;i<l;i++)
	{
		str.push_back(i);
	}	

	while(n--)
	{
		cin >> decode;
	
	
		for(int i:decode)
		{
			if(i=='1')
				decode_1++;
		}
		if(decode_1%2)
		{
			
			for(int i=hel-1;i>=0;i--)
			{
				tmp = str[i];
				if(l%2)
				{
					str[i] = str[i+hel+1];
					str[i+hel+1] = tmp;				
				}
	
				else
				{
					str[i] = str[i+hel];
					str[i+hel] = tmp;	
				}
			}
		}
		
		int j=0;
		for(int i=0;i < l;i++)
		{
			if(decode[i]=='1')
			{
				tmp1.push_back(str.back());	
				str.pop_back();
			}
			else
			{
				tmp1.push_back(str[j]);
				j++;
			}
		}
		str=tmp1;
		tmp1.clear();
		decode.clear();
		decode_1=0;
	}
	cin >> out;
	decode=out;
	for(int i=0;i<l;i++)
	{
		decode[str[i]]=out[i];
	}
	cout << decode << endl;
	return 0;
}