#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[111000];
int N;
bool lo(char x){return x>='a' && x<='z';}
bool vis[26];
int main()
{
	scanf("%d",&N);
	scanf("%s",s+1);
	int ans = 0;
	for (int i=1;i<=N;i++)
	if (lo(s[i]))
	{
		int j=i;
		while(j+1<=N && lo(s[j+1])) j++;
		//printf("%d %d\n",i,j);
		memset(vis,false,sizeof(vis));
		for (int k=i;k<=j;k++)vis[s[k]-'a'] = true;
		int tmp = 0;
		for (int k=0;k<26;k++)
		tmp += vis[k];
		ans = max(ans,tmp);
	}
	printf("%d",ans);
}
