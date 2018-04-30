#include <bits/stdc++.h>

using namespace std;

int base[128];
bool visMajor[20][20];
bool visMinor[20][20];
int Major[7] = {2,2,1,2,2,2,1};
int Minor[7] = {2,1,2,2,1,2,2};
bool okMajor[20],okMinor[20];

string trans(int x)
{
	char ret;
	int ma = -1;
	for (char i='A';i<='G';i++)
	if (base[i] <= x && base[i] > ma)
	{
		ma = base[i];
		ret = i;	
	} 
	//cout<<ret<<endl;
	string st = "!";
	st[0] = ret;
	//cout<<st<<endl;
	if (x != ma) st += "#";
	//return st;
	return st;
}

int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	base['C'] = 0;
	base['D'] = 2;
	base['E'] = 4;
	base['F'] = 5;
	base['G'] = 7;
	base['A'] = 9;
	base['B'] = 11;
	int T;
	memset(visMajor,false,sizeof(visMajor));
	memset(visMinor,false,sizeof(visMinor));
	for (int i=0;i<12;i++)
	{
		int Majornow = i, Minornow = i;
		for (int j=0;;j=(j+1)%7)
		{
			visMajor[i][Majornow] = true;
			Majornow = (Majornow + Major[j]) % 12;
			if (visMajor[i][Majornow]) break;
		}
		for (int j=0;;j=(j+1)%7)
		{
			visMinor[i][Minornow] = true;
			Minornow = (Minornow + Minor[j]) % 12;
			if (visMinor[i][Minornow]) break;
		}
	}
	/*
	for (int i=0;i<12;i++)
	if (visMajor[11][i]) //printf("%d\n",i);
	cout<<trans(i)<<endl;*/
	
	int _ = 0;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		memset(okMajor,true,sizeof(okMajor));
		memset(okMinor,true,sizeof(okMinor));
		scanf("%d",&N);
		while(N--)
		{
			char s[3];
			scanf("%s",s);
			int len = strlen(s);
			int pitch = base[s[0]];
			if (len > 1)
			{
				if (s[1] == '#') pitch++;
				if (s[1] == 'b') pitch--;
			}
			pitch = (pitch+12)%12;
			for (int i=0;i<12;i++)
			{	
				if (!visMajor[i][pitch]) okMajor[i] = false;
				if (!visMinor[i][pitch]) okMinor[i] = false;
			}
		}
		vector<string>ans;
		ans.clear();
		printf("Case #%d: ",++_);
		for (int i=0;i<12;i++)
		{
			if (okMajor[i])
				ans.push_back("M" + trans(i));
		}
		for (int i=0;i<12;i++)
		{
			if (okMinor[i])
				ans.push_back("m" + trans(i));
		}
		if (ans.size() == 0) puts("None");
		else 
		{
			sort(ans.begin(),ans.end());
			for (int i=0;i<ans.size();i++)
				cout<<ans[i]<<" \n"[i==ans.size()-1];
		}
	}
}
