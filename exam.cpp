#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define f first
#define s second
pair<string,string> tmp;
vector<pair<string,string> >  datas;
vector<pair<string,string> >  save;


int n=0;

void print(int i=n)
{
    while(i--)
        cout << ' ';
}

void EtoC()
{
    int det;
    print();
    cout << tmp.f << endl;
    getch();
    print();
    cout << tmp.s << endl;


}

void CtoE()
{
    int det;
    print();
    cout << tmp.s << endl;
    getch();
    print();
    cout << tmp.f << endl;


}

bool theelse(char det)
{
    if(det=='3')
    {
        cout << "start here" << endl;
        while(!datas.empty())
        {
            tmp=datas.back();
            print();
            cout << tmp.f << "\n" << tmp.s << endl;
            datas.pop_back();
        }
    }
    else if(det=='4')
    {
        print();
        printf("%d\n",datas.size());
    }
    else if(det=='5')
        return 1;
    return 0;
}
int main()
{
	srand( time(NULL) );

	int i=0;
	while( tmp.f != "0" )
	{
		i++;
		cin >> tmp.f;
		cin >> tmp.s;
		datas.push_back(tmp);
	}
	save=datas;
	int mode=0,ra;
	char det='0';
	cout << "輸入排版空格數" << endl;
	cin >> n;
	cout << "__________\n|試煉開始|\n|________|" << endl;
	cout << "按1進入英翻中\n按2進入中翻英" << endl;
	while(mode != 1 && mode != 2)
        cin >> mode;
	while(!datas.empty())
	{

		ra=rand()%datas.size();
		tmp = datas[ra];

		if(mode==1)
		{
		    EtoC();
		}
		else if(mode==2)
		{
            CtoE();
		}
		cout << '\n';
        print();
        cout << "正確按1 不正確按2\n按3輸出剩下所有單字 按4顯示剩下單字數量並結束" << endl;
        print();
        det = getche();
        cout << endl;
        if(det=='1')
        {
            datas.erase (datas.begin()+ra);
        }
        else if(theelse(det))
            break;
	}
	printf("恭喜全過");
}
