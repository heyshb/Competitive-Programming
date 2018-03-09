#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[200],t[200],p[200];
int N,M,kmp[200];
vector<string>ans;
map<string,int>vis;

void getkmp()
{
	kmp[1] = 0;
	for (int i=2;i<=M;i++)
	{
		int now = kmp[i-1];
		while(true)
		{
			if (t[now + 1] == t[i])
			{
				kmp[i] = now + 1;
				break;
			}
			if (now == 0)
			{
				kmp[i] = 0;
				break;
			}
			now = kmp[now];
		}
	}
	printf("%s\n",t + 1);
	for (int i=1;i<=M;i++)printf("%d ",kmp[i]);
	puts("");
}

bool check()
{
	for (int i=1;i<=N;i++)p[i] = 0;
	for (int i=1;i<=N;i++)
	{
		int now = 0;
		for (int j=1;j<=N;j++)
		{
			if (p[j])
				now++;
			else
			{
				while(now && s[j] != t[now + 1]) now = kmp[now];
				if (t[now + 1] == s[j]) now++;
			}
			if (now == M)
			{
				
			}
		}
	}
}

int main()
{
	freopen("D.in","r",stdin);
	scanf("%s",s + 1);
	N = strlen(s + 1);
	for (int i=1;i<=N;i++)
		for (int j=i;j<=N;j++)
		if (s[i]==s[1] && s[j]==s[N])
		{
			//printf("fuck %d %d\n",i,j);
			M = j - i + 1;
			for (int k=i;k<=j;k++)
			t[k - i + 1] = s[k];
			t[M + 1] = 0;
			string tmp = string(t + 1);
			if (vis.find(tmp) != vis.end()) continue;
			//puts("??");
			vis[tmp] = true;
			if (check()) ans.push_back(tmp);
		}
	
	sort(ans.begin(),ans.end());
	for (auto s:ans) cout<<s<<endl;	
}
