#include <bits/stdc++.h>

using namespace std;

int N,cnt;
char s[200010];
int ch[200010][26];
bool canbelast[200010];
bool endofblk[200010];
bool Nosol;

void insert(bool blk)
{
	int len = strlen(s);
	int now = 1;
	for (int i=0;i<len;i++)
	{
		if (!blk)
			canbelast[now] = false;
		if (!ch[now][s[i]-'a'])
			ch[now][s[i]-'a'] = ++cnt;
		now = ch[now][s[i]-'a'];
	}
	if (!blk)
		canbelast[now] = false;
	if (blk)
		endofblk[now] = true;
}

vector<string>ans;
vector<char>now;

void dfs(int x)
{
	if (canbelast[x] && x!=1)
	{
		string tmp = "";
		for (auto t:now)
			tmp = tmp + t;
		ans.push_back(tmp);
		return;
	}
	for (int i=0;i<26;i++)
	if (ch[x][i])
	{
		now.push_back('a' + i);
		dfs(ch[x][i]);
		now.pop_back();
	}
}

int main()
{
	scanf("%d",&N);
	char type[2];
	memset(canbelast,true,sizeof(canbelast));
	memset(endofblk,false,sizeof(endofblk));
	cnt = 1;
	for (int i=1;i<=N;i++)
	{
		scanf("%s",type);
		scanf("%s",s);
		insert(type[0] == '-');
	}
	for (int i=1;i<=cnt;i++)
		if (endofblk[i] && !canbelast[i]) return 0*puts("-1");
	now.clear();
	dfs(1);
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
}
