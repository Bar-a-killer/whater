#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main()
{
	srand( time(NULL) );
	pair<string,string> tmp;
	vector<pair<string,string> >  data;
	vector<pair<string,string> >  save;
	int i=0;
	while( tmp.f != "0" )
	{
		i++;
		cin >> tmp.f;
		cin >> tmp.s;
		data.push_back(tmp);
	}
	save=data;
	int det,ra;
	while(!data.empty())
	{
		cin >> det;
		ra=rand()%data.size();
		tmp = data[ra];
		
		if(det==1)
		{
			cout << tmp.f << endl;
			system("pause");
			cout << tmp.s << endl;
			cin >> det;
			if(det==1)
				data.erase (data.begin()+ra);
		}
		else if(det==2)
		{
			cout << "start here" << endl;
			while(!data.empty())
			{
				tmp=data.back();
				cout << tmp.f << "\n" << tmp.s << endl;
				data.pop_back(); 
			}
		}
		else if(det==3)
		{
			
			cout << tmp.s << endl;
			system("pause");
			cout << tmp.f << endl;
			cin >> det;
			if(det==1)
				data.erase (data.begin()+ra);
		}
		else if(det==4)
		{
			printf("%d",data.size());
		}
		else
			break;	
	}
	printf("a");
}
