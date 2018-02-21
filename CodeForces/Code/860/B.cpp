#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

unordered_map<string,int>cnt;
unordered_map<string,bool>vis;
char s[70010][10];
int N;

void solve(int i)
{
	for (int L=1;L<=9;L++)
		for (int j=0;j+L-1<9;j++)
		{
			string tmp = "";
			for (int l=j;l<=j+L-1;l++) tmp+=s[i][l];
			if (cnt[tmp] == 1)
			{
				cout<<tmp<<endl;
				return;
			}
		}
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%s",s[i]);
		vis.clear();
		for (int j=0;j<9;j++)
			for (int k=0;k<9;k++)
			{
				string tmp = "";
				for (int l=j;l<=k;l++) tmp+=s[i][l];
				if (vis[tmp]) continue;
				vis[tmp] = true;
				cnt[tmp]++;
			}
	}
	for (int i=1;i<=N;i++)
	{
		solve(i);
	}
}
